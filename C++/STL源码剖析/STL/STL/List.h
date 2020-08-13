		
//STL之list带头节点的双向循环链表的简化实现
#include <iostream>
using namespace std;
#include <memory.h>

template<class _Ty>
class CList
{
public:
	struct _Node;
	typedef _Node* _Nodeptr;
	typedef size_t size_type;

	struct _Node
	{
		_Nodeptr _Prev;
		_Nodeptr _Next;
		_Ty		 _Value;
	};

	struct _ACC
	{
		typedef _Node*& _Nodepref;
		typedef _Ty& _Vref;

		static _Nodepref _Next(_Nodeptr _P)
		{ return (_Nodepref)(*_P)._Next; }
		static _Nodepref _Prev(_Nodeptr _P)
		{ return (_Nodepref)(*_P)._Prev; }
		static _Vref _Value(_Nodeptr _P)
		{ return (_Vref)(*_P)._Value; }
	};

public:
	void push_back(const _Ty& _X) 
	{
		_Nodeptr _S = _Buynode(_Head, _ACC::_Prev(_Head));
		_ACC::_Value(_S) = _X;
		_ACC::_Next(_ACC::_Prev(_Head)) = _S;
		_ACC::_Prev(_Head) = _S;

		_Size++;
	}

	void display()
	{

	}

public:
	explicit CList():_Head(_Buynode()), _Size(0) {}

protected:
	_Nodeptr _Buynode(_Nodeptr _Narg = 0, _Nodeptr _Parg = 0)
	{
		_Nodeptr _S = (_Nodeptr)malloc(sizeof(struct _Node));
		_ACC::_Next(_S) = _Narg != 0 ? _Narg : _S;
		_ACC::_Prev(_S) = _Parg != 0 ? _Parg : _S;
		_ACC::_Value(_S) = _Ty();

		return _S;
	}

private:
	_Nodeptr _Head;
	size_type _Size;
};