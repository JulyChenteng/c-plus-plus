#include<iostream>
#include<typeinfo>
#include<vector>
#include<map>
#include<stddef.h>
using namespace std;

#pragma pack(1)

typedef struct alignas(32)  
{
    char a; // 1
    double d;//8
    int b;   //4
}Test;

int main()
{
    cout<<sizeof(Test)<<endl;
    cout<<"a offset : "<<offsetof(Test, a)<<endl;
    cout<<"d offset : "<<offsetof(Test, d)<<endl;
    cout<<"b offset : "<<offsetof(Test, b)<<endl;
    //
    cout<<alignof(Test)<<endl;
    return  0;
}

/*
template<typename ..._Args>
void fun(_Args ...args)
{
    cout<<sizeof...(args)<<endl;
}
int main()
{
    fun(1,2,34,5,6);
    return 0;
}

/*
int main()
{
    printf("jflalfjal = %d, = %d\n", 10,20);
    return 0;
}


/*
int main()
{
    pair<int, int> p(1,10);
    pair<int, string> p1 = make_pair(1,"abc");
    cout<<p1.first<<" : "<<p1.second<<endl;

    auto t1 = make_tuple(1,12.34,"C++");
    cout<<get<0>(t1)<<" : "<<get<1>(t1)<<" : "<<get<2>(t1)<<endl;
    return 0;
}

/*
int main()
{
    int ar[]{1,2,3,4};

    vector<int> v{1,2,3,4};

    for(auto i : ar)
        cout<<ar[i-1]<<" ";
    cout<<endl;
    return 0;
}

/*
int main()
{
    int ar[] = {1,2,3,4,5,6,7,8,9,10};
    for(auto i : ar)  //for
        cout<<ar[i-1]<<" ";
    cout<<endl;

    map<int, string> mp;
    mp[1] = "abc";
    mp[2] = "xyz";

    for(auto x : mp)
        cout<<x.first<<" : "<<x.second<<endl;

    return 0;
}

/*
int main()
{
    int *p = nullptr; // 0
    //int a = nullptr;
    return 0;
}

/*
int main()
{
    int a = 10;
    ///////////////////////////
    decltype(a) b = a;

}

/*
int main()
{
    int ar[10] = {1,2,3,4,5,6,7,8,9,10};
    vector<int> v(ar, ar+10);

    auto i = v.begin();
    cout<<typeid(i).name()<<endl;
    return 0;
}

/*
int main()
{
    auto i;
    const char *str = "Hello";
    cout<<typeid(str).name()<<endl;
    return 0;
}

/*
int main()
{
    auto i = 10;
    cout<<typeid(i).name()<<endl;
    auto s = "Hello";
    cout<<typeid(s).name()<<endl;
    const char *str = "Hello C++11";
    auto a = str;
    cout<<typeid(a).name()<<endl;


    cout<<typeid(str).name()<<endl;
    return 0;
}
*/
