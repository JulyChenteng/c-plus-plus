#pragma once

#include<stack>

template<class Type>
class AVLTree;

template<class Type>
class AVLNode
{
	friend class AVLTree<Type>;
public:
	AVLNode() : data(Type()),leftChild(NULL),rightChild(NULL),bf(0)
	{}
	AVLNode(Type d, AVLNode<Type>*left=NULL,AVLNode<Type>*right=NULL)
		: data(d),leftChild(left),rightChild(right),bf(0)
	{}
	~AVLNode()
	{}
public:
	void SetData(Type d);
	Type& GetData()const;
private:
	Type data;
	AVLNode *leftChild;
	AVLNode *rightChild;
	int bf;
};

template<class Type>
class AVLTree
{
public:
	AVLTree() : root(NULL)
	{}
public:
	void Insert(const Type &x)
	{
		Insert(root, x);
	}
	bool Remove(const Type &key)
	{
		return Remove(root, key);
	}
private:
	bool Remove(AVLNode<Type> *&t, const Type &key)
	{
		//1
		if(t == NULL)
			return false;
		AVLNode<Type> *p = t;
		AVLNode<Type> *q;
		AVLNode<Type> *pr = NULL;
		stack<AVLNode<Type> *> st;
		while(p != NULL)
		{
			if(p->data == key)
				break;

			pr = p;
			st.push(pr);

			if(key < p->data)
				p = p->leftChild;
			else
				p = p->rightChild;
		}

		if(p == NULL)
			return false;
		//
		if(p->leftChild!=NULL && p->rightChild!=NULL)
		{
			pr = p;
			st.push(pr);

			q = p->leftChild;
			while(q->rightChild != NULL)
			{
				pr = q;
				q = q->rightChild;
			}
			p->data = q->data;
			p = q;
		}

		//
		if(p->leftChild != NULL)
			q = p->leftChild;
		else
			q = p->rightChild;

		if(pr == NULL)
			t = q;
		else
		{
			if(pr->leftChild == p)
				pr->leftChild = q;
			else 
				pr->rightChild = q;

			///////////////////////////////////
			while(!st.empty())
			{
				pr = st.top();
				st.pop();

				if(pr->leftChild == q)
					pr->bf++;
				else
					pr->bf--;

				if(pr->bf==1 || pr->bf==-1)
					break;
				else if(pr->bf == 0)
					q = pr;
				else
				{
					if(pr->bf > 0)
						q = pr->rightChild;
					else
						q = pr->leftChild;

					if(q->bf == 0) // 单旋转
					{
						if(pr->bf > 0)
						{
							//RotateL(pr);
							//bf ????
						}
						else
						{
							RotateR(pr);
							//pr->bf  =   ???
							//pr->rightChild->bf = ?????
						}
					}
					else if(q->bf > 0)
					{
						if(pr->bf > 0)   // \ 
						{
							RotateL(pr);
						}
						else            //   <
						{
							RotateLR(pr);
							//cout<<"RotateLR"<<endl;
						}
					}
					else
					{
						if(pr->bf < 0)   //     / 
						{
							RotateR(pr);
						}
						else            //      >
						{
							RotateRL(pr);
						}
					}
 
					break;
				}
			}

			//
			AVLNode<Type> *ppr = st.top();
			if(ppr->data > pr->data )
				ppr->leftChild = pr;
			else
				ppr->rightChild = pr;

		}
		delete p;
		return true;
	}
	void Insert(AVLNode<Type> *&rt, const Type &x)
	{
		AVLNode<Type> *pr = NULL;
		AVLNode<Type>*t = rt;
		stack<AVLNode<Type> *> St;
                                                                                                                                                                                                                                                                                                                                                                                                                                         	while(t != NULL)
		{
			if(x == t->data)
				return;

			pr = t;
			St.push(pr);

			if(x < t->data)
				t = t->leftChild;
			else if(x > t->data)
				t = t->rightChild;
		}
		t = new AVLNode<Type>(x);
		if(rt == NULL)
		{
			rt = t;
			return;
		}

		if(x < pr->data)
			pr->leftChild = t;
		else 
			pr->rightChild = t;

		while(!St.empty())
		{
			pr = St.top();
			St.pop();

			if(pr->leftChild == t)
				pr->bf--;
			else
				pr->bf++;

			if(pr->bf == 0)
				break;
			else if(pr->bf==1 || pr->bf==-1)
				t = pr;
			else
			{
				//调整
				if(pr->bf < 0)
				{
					if(t->bf < 0)   //     /
					{
						RotateR(pr);
					}
					else            //    <   
					{
						RotateLR(pr);
					}
				}
				else
				{
					if(t->bf > 0)   //    \  
					{
						RotateL(pr);
					}
					else            //    >
					{
						RotateRL(pr);
					}
				}
				break;
			}
		}
		if(St.empty())
			rt = pr;
		else
		{
			AVLNode<Type> *s = St.top();
			if(pr->data < s->data)
				s->leftChild = pr;
			else
				s->rightChild = pr;
		}
	}
protected:
	AVLNode<Type>* RotateL(AVLNode<Type> *&ptr)
	{
		AVLNode<Type> *subL = ptr;
		ptr = subL->rightChild;
		subL->rightChild = ptr->leftChild;
		ptr->leftChild = subL;
		ptr->bf = subL->bf = 0;
		return ptr;
	}
	AVLNode<Type>* RotateR(AVLNode<Type> *&ptr)
	{
		AVLNode<Type> *subR = ptr;
		ptr = subR->leftChild;
		subR->leftChild = ptr->rightChild;
		ptr->rightChild = subR;
		ptr->bf = subR->bf = 0;
		return ptr;
	}
	AVLNode<Type>* RotateLR(AVLNode<Type> *&ptr)
	{
		AVLNode<Type> *subR = ptr;
		AVLNode<Type> *subL = ptr->leftChild;
		ptr = subL->rightChild;
		
		subL->rightChild = ptr->leftChild;
		ptr->leftChild = subL;
		//bf
		if(ptr->bf <= 0)
			subL->bf = 0;
		else
			subL->bf = -1;
		
		subR->leftChild = ptr->rightChild;
		ptr->rightChild = subR;
		//bf
		if(ptr->bf >= 0)
			subR->bf = 0;
		else
			subR->bf = 1;

		ptr->bf = 0;
		return ptr;
	}
	AVLNode<Type>* RotateRL(AVLNode<Type> *&ptr)
	{
		AVLNode<Type> *subL = ptr;
		AVLNode<Type> *subR = ptr->rightChild;
		ptr = subR->leftChild;
		subR->leftChild = ptr->rightChild;
		ptr->rightChild = subR;
		//bf
		if(ptr->bf >= 0)
			subR->bf = 0;
		else
			subR->bf = 1;

		subL->rightChild = ptr->leftChild;
		ptr->leftChild = subL;
		//bf
		if(ptr->bf <= 0)
			subL->bf = 0;
		else
			subL->bf = -1;

		ptr->bf = 0;
		return ptr;
	}
private:
	AVLNode<Type> *root;
};