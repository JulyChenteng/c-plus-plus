#include <iostream>
#include <string>
#include <unistd.h>

using namespace std;

typedef int int32;
typedef long long int64;
typedef unsigned int uint32;

static const size_t kMinAlign = 16;
static const size_t kBaseClasses = 9;
static const size_t kPageShift = 16;
//! calss 对应于256k的数量
static const size_t kNumClasses = kBaseClasses + 73; 

static const size_t kMaxThreadCacheSize = 4 << 20;

static const size_t kPageSize = 1 << kPageShift;
static const size_t kMaxSize = 256 * 1024;
static const size_t kAlignment = 8;
static const size_t kLargeSizeClass = 0;

static const int kMaxSmallSize = 1024;
static const size_t kClassArraySize = ((kMaxSize +127 + (120 << 7)) >> 7) + 1;

static inline int LgFloor(size_t n) 
{
    int log = 0;

    for (int i = 4; i >= 0; --i)
    {
        int shift = (1 << i);
        size_t x = n >> shift;

        if (x != 0)
        {
            n = x;
            log += shift;
        }
    }

    return log;
}

static inline size_t ClassIndex(int s)
{
    if ((s <= kMaxSmallSize)) 
    {
        return (static_cast<uint32>(s) + 7) >> 3;
    }
    else
    {
        return (static_cast<uint32>(s) + 127 + (120 << 7)) >> 7;
    }
}

int NumMoveSize(size_t size)
{
    if (size == 0) return 0;

    int num = static_cast<int>(64.0 * 1024.0 / size);
    if (num < 2) num == 2;

    return num;
}

int AlignmentForSize(size_t size) {
    int alignment = kAlignment;
    
    if (size > kMaxSize) { //! 大于
        //! Cap alignment at kPageSize for large sizes.
        alignment = kPageSize;
    }
    else if (size >= 128) {
        //! Space wasted due to alignment is at most 1/8, i.e., 12.5%.
        alignment = (1 << LgFloor(size)) / 8;
    }
    else if (size >= kMinAlign) {
        //! We need an alignment of at least 16 bytes to satisfy
        //! requirements for some SSE types. 
        alignment = kMinAlign;
    }

    //! Maximum alignment allowed is page size alignment
    if (alignment > kPageSize) {
        alignment = kPageSize;
    }

    //! CHECK_CONDITION(size < kMinAlign || alignment >= kMinAlign);
    //! CHECK_CONDITION(alignment & (alignment - 1)) == 0);
    return alignment;
}

int main()
{
    int sc = 1; //! Next size class to assign
    int alignment = kAlignment;

    size_t class_to_pages_[kNumClasses];
    size_t class_to_size_[kNumClasses];

    unsigned char class_array_[kClassArraySize];
    int num_objects_to_move_[kNumClasses];

    //! CHECK_CONDITION(kAlignment <= kMinAlign)
    //!cout << "ClassIndex(" << 15 << ")" << ClassIndex(15) << endl;

    for (size_t size = kAlignment; size <= kMaxSize; size += alignment) 
    {
        alignment = AlignmentForSize(size);
        //! CHECK_CONDITION((size % alignment) == 0);
        cout << "alignment " << alignment << endl;
        int blocks_to_move = NumMoveSize(size) / 4;
        size_t psize = 0;
        
        do 
        {
            psize += kPageSize;

            //! Alocate enough pages so leftover is less than 1/8 of total.
            //! This bounds wasted space to at most 12.5%.
            while ((psize % size) > (psize >> 3)) 
            {
                psize += kPageShift;

            }

            //! Continue to add pages until there are at least as many objects
            //! in the span as are needed when moving objects from the central
            //! freelists and spans to the thread caches.
        } while ((psize / size) < blocks_to_move);

        const size_t my_pages = psize >> kPageShift;

        cout << "psize: " << psize << endl;
        cout << "my_pages: " << my_pages << endl;

        if (sc > 1 && my_pages == class_to_pages_[sc - 1])
        {
            //! See if we can merge this into the previous class without 
            //! increasing the fragmentation of previous class.
            const size_t my_objects = (my_pages << kPageShift) / size;
            const size_t prev_objects = (class_to_pages_[sc - 1]) << kPageShift / class_to_size_[sc - 1];

            if (my_objects == prev_objects)
            {
                //! Adjust last class to include this size
                class_to_size_[sc - 1] = size;
                continue;
            }
        }

        //! Add new class
        class_to_pages_[sc] = my_pages;
        class_to_size_[sc] = size;
        
        cout << "class_to_size_[" << sc << "] = " << class_to_size_[sc] << endl;
        sc++; 
    }

    //! Initialize the num_objects_to_move array.
    for (size_t cl = 1; cl < kNumClasses; ++cl)
    {
        num_objects_to_move_[cl] = class_to_pages_[cl] * kPageSize / class_to_size_[cl];

        //! num_objects_to_move_[cl] = NumMoveSize(ByteSizeForClass(cl));
        //! cout << "num_objects_to_move_[" << cl << "] = " << num_objects_to_move_[cl] << endl;
    }

    int next_size = 0;
    for (int c = 1; c < kNumClasses; c++)
    {
        const int max_size_in_class = class_to_size_[c];
        //! cout << "class_to_size_[" << c << class_to_size_[c] <<endl;

        for (int s = next_size; s <= max_size_in_class; s += kAlignment) 
        {
            class_array_[ClassIndex(s)] = c;
            //! cout << "ClassIndex(" << s << ClassIndex(s) << endl;
            cout << "class_array_[" << ClassIndex(s) << "] = " << c << endl;
            usleep(8000000);
        }

        //! cout << "------------------\n" << endl;
        next_size = max_size_in_class + kAlignment;
    }

    /*
    int32 x, y;
    while (cin >> x) 
    {
        y = class_to_size_[class_array_[ClassIndex(x)]];
        cout << y << endl;
        cout << "----------------------\n" << endl;
    }
    */

    return 0;
}
