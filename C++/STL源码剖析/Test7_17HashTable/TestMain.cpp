#include<iostream.h>
#include<sgi/set>
#include<sgi/hash_set>
#include<sgi/hash_map>
#include<sgi/map>
#include<string>

void main()
{
	map<int, std::string> hp;
	//hp[1] = "hello";
	//hp[2] = "C++";
	//hp[3] = "Linux";
	//hp[4] = "Java";
	pair<int,std::string> v1(1,"Hello");
	hp.insert(v1);

	map<int, std::string>::iterator it = hp.begin();
	while(it != hp.end())
	{
		std::cout<<(*it).first<<" : "<<(*it).second<<std::endl;
		++it;
	}

}

/*
//#define SET

void main()
{
#ifdef SET
	set<int> st;
#else
	hash_multiset<int> st;
#endif
	st.insert(194);
	st.insert(10);
	st.insert(1);
	st.insert(5);
	st.insert(3);

#ifdef SET
	typedef set<int>::iterator iter;
#else
	typedef hash_set<int>::iterator iter;
#endif

	iter it = st.begin();
	while(it != st.end())
	{
		cout<<*it<<" "; //54  1  3  5  10
		++it;
	}
	cout<<endl;

}

/*
#include<iostream.h>
#include<sgi/stl_hashtable.h>
//using namespace std;

void main()
{
	hashtable<int, int, hash<int>, identity<int>, equal_to<int> >
		ht(50, hash<int>(), equal_to<int>());

	cout<<"size = "<<ht.size()<<endl;
	cout<<"bucket size = "<<ht.bucket_count()<<endl;
	cout<<"max bucket size = "<<ht.max_bucket_count()<<endl;

	ht.insert_unique(1);
	ht.insert_unique(54);
	ht.insert_unique(0);
	ht.insert_unique(7);

	hashtable<int,int,hash<int>,identity<int>,equal_to<int> >::iterator it;
	it = ht.begin();
	while(it != ht.end())
	{
		cout<<*it<<" ";
		++it;
	}
	cout<<endl;
}


/*

//#define SET

void main()
{
#ifdef SET
	set<int> st;
#else
	hash_set<int> st;
#endif
	st.insert(54);
	st.insert(10);
	st.insert(1);
	st.insert(5);
	st.insert(3);

#ifdef SET
	typedef set<int>::iterator iter;
#else
	typedef hash_set<int>::iterator iter;
#endif

	iter it = st.begin();
	while(it != st.end())
	{
		cout<<*it<<" "; //54  1  3  5  10
		++it;
	}
	cout<<endl;

}


/*
//vs  iostream.h
#include<iostream.h>
#include<sgi/stl_hashtable.h>
//using namespace std;

void main()
{
	hashtable<int, int, hash<int>, identity<int>, equal_to<int> >
		ht(50, hash<int>(), equal_to<int>());

	cout<<"size = "<<ht.size()<<endl;
	cout<<"bucket size = "<<ht.bucket_count()<<endl;
	cout<<"max bucket size = "<<ht.max_bucket_count()<<endl;

	for(int i=0; i<53; ++i)
	{
		ht.insert_unique(i);
	}

	ht.insert_unique(54);

	for(i=0; i<ht.bucket_count(); ++i)
	{
		cout<<i<<" : ";
		ht.print_buckets_elem(i);
	}
}
/*
void main()
{
	hashtable<int, int, hash<int>, identity<int>, equal_to<int> >
		ht(50, hash<int>(), equal_to<int>());
	cout<<"size = "<<ht.size()<<endl;
	cout<<"bucket size = "<<ht.bucket_count()<<endl;
	cout<<"max bucket size = "<<ht.max_bucket_count()<<endl;

	ht.insert_unique(1);
	ht.insert_unique(54);
	ht.insert_unique(0);
	ht.insert_unique(7);
	//ht.insert_equal(1);
	//ht.insert_equal(54);
	ht.insert_unique(1);
	ht.insert_unique(54);

	cout<<"===================="<<endl;
	cout<<"size = "<<ht.size()<<endl;
	cout<<"bucket size = "<<ht.bucket_count()<<endl;

	cout<<"1 bucket size="<<ht.elems_in_bucket(1)<<endl;

	/*
	hashtable<int,int,hash<int>,identity<int>,equal_to<int> >::iterator it;
	it = ht.begin();
	while(it != ht.end())
	{
		cout<<*it<<" ";
		++it;
	}
	cout<<endl;
	

	for(int i=0; i<ht.bucket_count(); ++i)
	{
		cout<<i<<" : ";
		ht.print_buckets_elem(i);
	}
}
*/
