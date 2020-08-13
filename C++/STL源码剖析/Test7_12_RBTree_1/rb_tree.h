#pragma once

typedef enum {RED = 0, BLACK} COLOR;

template<class Type>
class RBTree;

template<class Type>
class RBNode
{
	friend class RBTree<Type>;
public:
	RBNode():data(Type()),color(RED),parent(NULL),leftChild(NULL),rightChild(NULL)
	{}
	RBNode(Type d, COLOR c=RED, RBNode<Type>*pr=NULL, RBNode<Type>*left=NULL,RBNode<Type>*right=NULL)
		:data(d),color(c),parent(pr),leftChild(left),rightChild(right)
	{}
	~RBNode()
	{}
private:
	Type          data;
	COLOR         color;
	RBNode<Type> *parent;
	RBNode<Type> *leftChild;
	RBNode<Type> *rightChild;
};

template<class Type>
class RBTree
{
public:
	RBTree() : root(NULL)
	{}
public:
	bool Insert(const Type &v)
	{
		return Insert(root, v);
	}
	bool Remove(const Type &key)
	{
		return Remove(root, key);
	}
protected:
	bool Remove(RBNode<Type>*&t, const Type &v)
	{
		//
	}
	bool Insert(RBNode<Type>*&t, const Type &v)
	{
		RBNode<Type> *x = t;
		RBNode<Type> *pr = NULL;
		while(x != NULL)
		{
			if(v == x->data)
				return false;

			pr = x;

			if(v < x->data)
				x = x->leftChild;
			else
				x = x->rightChild;
		}
		x = _Buynode(v);
		if(pr == NULL)
		{
			t = x;
			t->color = BLACK;
			return true;
		}
		if(v < pr->data)
			pr->leftChild = x;
		else
			pr->rightChild = x;
		x->parent = pr;

		_Balance_Tree(t, x);

		return true;
	}
protected:
	void _Balance_Tree(RBNode<Type> *&t, RBNode<Type> *x)
	{
		RBNode<Type> *s;
		while(x->parent!=NULL && x->parent->color==RED)
		{
			if(x->parent == x->parent->parent->leftChild)
			{
				s = x->parent->parent->rightChild;

				if(s!=NULL && s->color==RED)
				{
					x->parent->color = BLACK;
					s->color = BLACK;
					x->parent->parent->color = RED;
					x = x->parent->parent;
					continue;
				}
				else if(x == x->parent->rightChild)
				{
					x = x->parent;
					RotateL(x);
				}

				//1
				x->parent->color = BLACK;
				x->parent->parent->color = RED;
				RotateR(x->parent->parent);
			}
			else
			{
				s = x->parent->parent->leftChild;
				if(s!=NULL && s->color==RED)
				{
					s->color = BLACK;
					x->parent->color = BLACK;
					x->parent->parent->color = RED;
					x = x->parent->parent;
					continue;
				}
				else if(x == x->parent->leftChild)
				{
					x = x->parent;
					RotateR(x);
				}

				x->parent->color = BLACK;
				x->parent->parent->color = RED;
				RotateL(x->parent->parent);
			}
		}
		t->color = BLACK;
	}
	/*
	void _Balance_Tree(RBNode<Type> *&t, RBNode<Type> *x)
	{
		RBNode<Type> *s;
		while(x->parent!=NULL && x->parent->color==RED)
		{
			if(x->parent==x->parent->parent->leftChild)
			{
				s = x->parent->parent->rightChild;
				if((x==x->parent->leftChild && s==NULL)
					|| (x==x->parent->leftChild&&s!=NULL&&s->color==BLACK))
				{
					//1
					x->parent->color = BLACK;
					x->parent->parent->color = RED;
					RotateR(x->parent->parent);
				}
				else if((x==x->parent->rightChild && s==NULL)
				     	|| (x==x->parent->rightChild&&s!=NULL&&s->color==BLACK))
				{
					//2
					x->color = BLACK;
					x->parent->parent->color = RED;
					RotateL(x->parent);
					RotateR(x->parent);
				}
				else if((x==x->parent->leftChild && s->color==RED))
				{
					//3
					x->color = BLACK;
					RotateR(x->parent->parent);
					if(x->parent->parent!=NULL && x->parent->parent->color == RED)
					{
						x = x->parent;
						continue;
					}
					else
						break;
				}
				else if((x==x->parent->rightChild && s->color==RED))
				{
					x->parent->color = BLACK;
					RotateL(x->parent);
					RotateR(x->parent);

					if(x->parent!=NULL && s->parent->color==RED)
					{
						continue;
					}
					else
						break;
				}
			}
			else
			{
				s = x->parent->parent->leftChild;
				if((x==x->parent->leftChild&&s==NULL)
					||(x==x->parent->leftChild&&s!=NULL&&s->color==BLACK))
				{
					x->color = BLACK;
					x->parent->parent->color = RED;
					RotateR(x->parent);
					RotateL(x->parent);
				}
				
			}
		}
		t->color = BLACK;
	}
	*/
protected:
	void RotateR(RBNode<Type> *ptr)
	{
		RBNode<Type> *subR = ptr;
		ptr = subR->leftChild;
		subR->leftChild = ptr->rightChild;

		if(ptr->rightChild != NULL)
			ptr->rightChild->parent = subR;
		if(subR->parent == NULL)
			root = ptr;
		else
		{
			if(subR == subR->parent->leftChild)
				subR->parent->leftChild = ptr;
			else
				subR->parent->rightChild = ptr;
		}
		ptr->parent = subR->parent;

		ptr->rightChild = subR;
		subR->parent = ptr;
	}
	void RotateL(RBNode<Type> *ptr)
	{
		RBNode<Type> *subL = ptr;
		ptr = subL->rightChild;

		subL->rightChild = ptr->leftChild;
		if(ptr->leftChild != NULL)
			ptr->leftChild->parent = subL;

		if(subL->parent == NULL)
			root = ptr;
		else
		{
			if(subL == subL->parent->leftChild)
				subL->parent->leftChild = ptr;
			else
				subL->parent->rightChild = ptr;
		}

		ptr->parent = subL->parent;

		ptr->leftChild = subL;
		subL->parent = ptr;
	}
private:
	RBNode<Type>* _Buynode(const Type &v)
	{
		RBNode<Type> *s = new RBNode<Type>(v);
		assert(s != NULL);
		return s;
	}
private:
	RBNode<Type> *root;
};