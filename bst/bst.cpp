#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node *rchild;
	Node *lchild;
};

Node * insert(Node *ptr,int ikey)
{
	if(ptr==NULL)
	{
		ptr=new Node ();
		ptr->data=ikey;
		ptr->rchild=NULL;
		ptr->lchild=NULL;
	}
	else if(ikey<ptr->data) 
	{
		ptr->lchild=insert(ptr->lchild,ikey);
	}
	else if(ikey>ptr->data)
	{
		ptr->rchild=insert(ptr->rchild,ikey);
	}
	else
	cout<<"duplicate key"<<endl;
	
	return ptr;
}
void preorder (Node *ptr)
{
	if(ptr==NULL)
	return ;
	cout<<ptr->data<<" ";
	preorder(ptr->lchild);
	preorder(ptr->rchild);
}
void inorder(Node *ptr)
{
	if(ptr==NULL)
	return ;
	inorder(ptr->lchild);
	cout<<ptr->data<<" ";
	inorder(ptr->rchild);
}
void postorder(Node *ptr)
{
	if(ptr==NULL)
	return;
	postorder(ptr->lchild);
	postorder(ptr->rchild);
	cout<<ptr->data<<" ";
}
Node *search(Node *ptr,int skey)
{
	if(ptr==NULL)
	{
		cout<<"key not found"<<endl;
		return NULL;
	}
	else if(skey<ptr->data)
	return search(ptr->lchild,skey);
	else if(skey>ptr->data)
	return search (ptr->rchild,skey);
	else   //key is found	
	return ptr;
}
int height(Node *ptr)
{
	int l_h,r_h;
	if(ptr==NULL)
	return 0;
	l_h=height(ptr->lchild);
	r_h=height(ptr->rchild);
	if(l_h>r_h)
	return 1 + l_h;
	else
	return 1+r_h;
}
Node *mim(Node *ptr)
{
	if(ptr==NULL)
	return NULL;
	else if(ptr->lchild==NULL)
	return ptr;
	else
	return mim(ptr->lchild);
}
Node *max(Node *ptr)
{
	if(ptr==NULL)
	return NULL;
	else if(ptr->rchild==NULL)
	return ptr;
	else
	return max(ptr->rchild);
}
Node *del(Node *ptr,int dkey)
{
	Node *temp,*succ;
	if(ptr==NULL)
	{
		cout<<"dkey is not found"<<endl;
		return ptr;
	}
	if(dkey<ptr->data)
	{
		ptr->lchild=del(ptr->lchild,dkey);
	}
	else if(dkey>ptr->data)
	{
		ptr->rchild=del(ptr->rchild,dkey);
	}
	else
	{
		if(ptr->lchild!=NULL && ptr->rchild!=NULL)
		{
			succ=ptr->rchild;
			while(succ->lchild)
			succ=succ->lchild;
			ptr->data=succ->data;
			ptr->rchild=del(ptr->rchild,succ->data);
		}
		else
		{
			temp=ptr;
			if(ptr->lchild!=NULL)
			ptr=ptr->lchild;
			else if(ptr->rchild!=NULL)
			ptr=ptr->rchild;
			else
			ptr=NULL;
			delete (temp);
		}
	}
	return ptr;
}
	

	
int main()
{
	Node *root=NULL;
	while(1)
	{
		cout<<"choose one"<<endl;
		cout<<"1.insert()"<<endl;
		cout<<"2.preorder()"<<endl;
		cout<<"3.inorder()"<<endl;
		cout<<"4.postorder()"<<endl;
		cout<<"5.search()"<<endl;
		cout<<"6.height of tree()"<<endl;
		cout<<"7.mim node()"<<endl;
		cout<<"8.max node()"<<endl;
		cout<<"9.delete"<<endl;
		int a;
		cin>>a;
		switch(a)
		{
			case 1:
			{
				cout<<"enter the data to be inserted"<<endl;
				int info;
				cin>>info;
				root=insert(root,info);
			
			}
			break;
			case 2:
			preorder(root);
			break;
			case 3:
			inorder(root);
			break;
			case 4:
			postorder(root);
			break;
			case 5:
			{
				cout<<"enter the dat to be searched "<<endl;
				int info;
				cin>>info;
				Node *temp=search(root,info);
				if(temp!=NULL)
				{
					cout<<info<<" is present in the tree"<<endl;
				}
				
			}
			break;
			case 6:
			{
				int h=height(root);
				cout<<"height is "<<h<<endl;
			}
			break;
			case 7:
			{
				Node *temp=mim(root);
				cout<<"mim node is "<<temp->data<<endl;
			}
			break;
			case 8:
			{
				Node *temp=max(root);
				cout<<"Max node is "<<temp->data<<endl;
			}
			break;
			case 9:
			{
				cout<<"enter the key to be deletd "<<endl;
				int dkey;
				cin>>dkey;
				root=del(root,dkey);
			}
			break;
			default:
			cout<<"invalid input"<<endl;
			break;
		}
	}
}
		
