#include<iostream.h>
#include<sgi/hashtable.h>

void main()
{
	hashtable<int, int, hash<int>,i <int>, equal_to<int> >
		ht(50,hash<int>(), equal_to<int>());

	ht.insert_unique(1);
}

/*
/*
#include<map>
#include<string>
#include<set>
#include<list>

//using namespace std;

typedef int Type;
#define P  7

typedef struct HashNode
{
	Type data;
	struct HashNode *link;
}HashNode;

typedef HashNode* HashTable[P];

int Hash(Type key)
{
	return key % P;
}

void InitHashTable(HashTable &ht)
{
	for(int i=0; i<P; ++i)
	{
		ht[i] = NULL;
	}
}

void InsertHashTable(HashTable &ht, Type x)
{
	int index = Hash(x);

	HashNode *s = (HashNode*)malloc(sizeof(HashNode));
	s->data = x;

	s->link = ht[index];
	ht[index] = s;
}

void ShowHashTable(HashTable &ht)
{
	for(int i=0; i<P; ++i)
	{
		cout<<i<<":";
		HashNode *cur = ht[i];
		while(cur)
		{
			cout<<cur->data<<"-->";
			cur = cur->link;
		}
		cout<<"Nul."<<endl;
	}
}

HashNode* FindHashTable(const Type &x)
{
	int index = Hash(x);
}

void main()
{
	Type ar[] = {32,54,43,12,121,1,8,15};
	int n = sizeof(ar) / sizeof(int);

	HashTable ht;
	InitHashTable(ht);

	for(int i=0; i<n; ++i)
	{
		InsertHashTable(ht, ar[i]);
	}
	ShowHashTable(ht);

}

/*
#include<sgi/hash_map>
#include<string>

void main()
{
	hash_map<int,int> hp;
}

/*
using namespace std;


void main()
{
	int ar[] = {1,5,3,7,9,2,6};
	int n = sizeof(ar) / sizeof(int);
	list<int> mylist(ar, ar+n);

	//mylist.sort();
	mylist.sort(greater<int>());

	list<int>::iterator it = mylist.begin();
	while(it != mylist.end())
	{
		cout<<*it<<"-->";
		++it;
	}
	cout<<"Nul."<<endl;
}

/*
void main()
{
	plus<int> pl;
	cout<<pl(10,20)<<endl;
}

/*
void main()
{
	int ar[] = {1,5,3,7,9,2,6};
	int n = sizeof(ar) / sizeof(int);
	list<int> mylist(ar, ar+n);

	//mylist.sort();
	mylist.sort(greater<int>());

	list<int>::iterator it = mylist.begin();
	while(it != mylist.end())
	{
		cout<<*it<<"-->";
		++it;
	}
	cout<<"Nul."<<endl;
}

/*
void main()
{
	set<int> s;

	s.insert(2);
	s.insert(3);
	s.insert(1);
	
	set<int>::iterator it = s.begin();
	while(it != s.end())
	{
		cout<<*it<<endl;
		++it;
	}
}

/*
void main()
{
	const char *s1  ="abc";
	const char *s2 = "xyz";
	set<const char*> s;

	s.insert(s2);
	s.insert(s1);
	
	
	set<const char*>::iterator it = s.begin();
	while(it != s.end())
	{
		cout<<*it<<endl;
		++it;
	}
}

/*
void main()
{
	//int--string
	pair<int,string> p(1,"jfla");
	cout<<p.first<<":"<<p.second<<endl;
}

/*
template<class _T1, class _T2> 
struct pair 
{
	typedef _T1 first_type;
	typedef _T2 second_type;

	pair() : first(_T1()), second(_T2()) 
	{}
	pair(const _T1& _V1, const _T2& _V2): first(_V1), second(_V2) 
	{}
	template<class U, class V> 
	pair(const pair<U, V> &p): first(p.first), second(p.second) 
	{}
	_T1 first;  //int first;
	_T2 second; //string second
};

//pair

void main()
{
	map<string, string> mp;
	mp["1-1"] = "元旦节";
	mp["10-1"] = "国庆节";

	string key = mp["10-1"];
	cout<<"10-1:"<<key<<endl;

}

/*
void main()
{
	map<int, string> mp;
	pair<int, string> val1(1,"abc");
	pair<int, string> val2(3,"xyz");
	pair<int, string> val3(2,"hmn");
	mp.insert(val1);
	mp.insert(val2);
	mp.insert(val3);	

	typedef map<int, string>::iterator map_iter;

	map_iter it = mp.begin();
	while(it != mp.end())
	{
		cout<<(*it).first<<" : "<<(*it).second<<endl;
		++it;
	}
	cout<<"size = "<<mp.size()<<endl;
	cout<<"count = "<<mp.count(2)<<endl;
}

/*
void main()
{
	map<int, string> mp;
	mp[1] = "abc";
	mp[3] = "hmn";
	mp[2] = "xyz";
	

	typedef map<int, string>::iterator map_iter;

	map_iter it = mp.begin();
	while(it != mp.end())
	{
		cout<<(*it).first<<" : "<<(*it).second<<endl;
		++it;
	}
}
*/
