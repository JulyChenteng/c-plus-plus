/*函数模板和类模板初讲*/
#include <iostream>

using namespace std;


#if 0
/*
类模板：
和函数模板一样，类模板就是建立一个通用类，其数据成员的类型、成员函数的返回类型和参数类形
都可以不具体指定，而用虚拟的类型来代表。当使用类模板建立对象时，系统会根据实参的类型取代类模
板中的虚拟类型，从而实现不同类的功能。
*/
template <typename T>
class CMax
{
public:
	CMax(T a, T b)
	{
		m_a = a;
		m_b = b;
	}

public:
	T getMax();

private:
	T m_a;
	T m_b;
};

template<class T>
T CMax<T>::getMax()
{
	return m_a > m_b ? m_a : m_b;
}

int main()
{
	CMax<char> myMax0('a', 'c');
	auto cMax = myMax0.getMax();
	cout << cMax << endl;

	CMax<int> myMax1(12, 16);
	auto iMax = myMax1.getMax();
	cout << iMax << endl;

	return 0;
}
#endif

#if 0
//用类模板实现顺序栈的简单操作

template <class T>
class SeqStack
{
public:
	explicit SeqStack<T>(int sz) : m_nTop(-1), m_nSzie(sz) 
	{
		m_pCapacity = new T[sz];
		if (m_pCapacity == NULL)
		{
			cout << "Application error!" << endl;		
			exit(1);
		}		
	}

	~SeqStack<T>() { delete []m_pCapacity; }

public:
	T getTop();
	T pop();
	void push(T x);
	void print();	

	void clear() {	m_nTop = -1; }
	bool isFull() const { return (m_nTop == m_nSzie-1); }
	bool isEmpty() const { return (m_nTop == -1); }

private:
	T *m_pCapacity;
	int m_nSzie;
	int m_nTop;	
};

template <class T>
void SeqStack<T>::push(T x)
{
	if (isFull())
	{
		cout << "the stack is full !" << endl;
		return ;
	}
	
	m_pCapacity[++m_nTop] = x;
}

template<class T>
T SeqStack<T>::getTop()
{
	if (isEmpty())
	{
		cout << "the stack is empty !" << endl;
		exit(1);
	}

	return m_pCapacity[m_nTop];
}

template <class T>	
void SeqStack<T>::print()
{
	cout << "<--Bottom--";
	for (int i = 0; i <= m_nTop; ++i)
		cout << m_pCapacity[i] << " ";
	cout << "--Top-->" << endl << endl;
}

template <class T>
T SeqStack<T>::pop()
{
	if (isEmpty())
	{
		cout << "the stack is empty !" << endl;
		exit(1);
	}

	return m_pCapacity[m_nTop--];
}

int main()
{
	SeqStack<int> s(15);

	for (int i = 2; i < 15; i++)
		s.push(i);
	cout << s.getTop() << endl;
	s.pop();
	s.push(99);
	s.print();

	return 0;
}
#endif

#if 1
template<typename Type> class LinkStack;

template<typename Type> class StackNode{
private:
	friend class LinkStack<Type>;
	StackNode(Type dt,StackNode<Type> *next=NULL):m_data(dt),m_pnext(next){} 

private:
	Type m_data;
	StackNode<Type> *m_pnext;
};

template<typename Type> 
class LinkStack{
public:
	LinkStack():m_ptop(NULL){}
	~LinkStack(){
		MakeEmpty();
	}

public:
	void MakeEmpty();           //make the stack empty
	void Push(const Type item); //push the data
	Type Pop();                 //pop the data
	Type GetTop() const;        //get the data
    void Print();               //print the stack
        
	bool IsEmpty() const{
		return m_ptop==NULL;
	}
	
private:
	StackNode<Type> *m_ptop;
};

template<typename Type> 
void LinkStack<Type>::MakeEmpty(){
	StackNode<Type> *pmove;
	while(m_ptop!=NULL){
		pmove=m_ptop;
		m_ptop=m_ptop->m_pnext;
		delete pmove;
	}
}

template<typename Type>
void LinkStack<Type>::Push(const Type item){
	m_ptop=new StackNode<Type>(item,m_ptop);
}

template<typename Type> 
Type LinkStack<Type>::GetTop() const{
	if(IsEmpty()){
		cout<<"There is no elements!"<<endl;
		exit(1);
	}
	return m_ptop->m_data;
}

template<typename Type> 
Type LinkStack<Type>::Pop(){
	if(IsEmpty()){
		cout<<"There is no elements!"<<endl;
		exit(1);
	}
	StackNode<Type> *pdel=m_ptop;
	m_ptop=m_ptop->m_pnext;
	Type temp=pdel->m_data;
	delete pdel;
	return temp;
}

template<typename Type> 
void LinkStack<Type>::Print(){
	StackNode<Type> *pmove=m_ptop;
	cout<<"Top";
	while(pmove!=NULL){
		cout<<"--->"<<pmove->m_data;
		pmove=pmove->m_pnext;
	}
	cout<<"--->Bottom"<<endl<<endl<<endl;
}

int main(){
	LinkStack<int> stack;
	int init[10]={1,3,5,7,4,2,8,0,6,9};
	for(int i=0;i<10;i++){
		stack.Push(init[i]);
	}
	stack.Print();

	cout<<stack.Pop()<<endl;
	stack.Print();
	
	cout<<stack.GetTop()<<endl;
	stack.Print();

	cout<<stack.Pop()<<endl;
	stack.Print();

	stack.MakeEmpty();
	stack.Print();
	
	stack.Pop();

	system("pause");
	return 0;
}
#endif
