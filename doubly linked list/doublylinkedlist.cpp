#include<iostream>
using namespace std;
void InsertAtAnyWhere();
void InsertAtBegin();
void InsertAtEnd();
int Length();
void showall();
void deleteele();
void search();
void reverse();
void largest();


struct Node
{
	int data;
	Node *right;
	Node *left;
};
Node *head=NULL;
int main()
{
	while(1)
	{
		cout<<"enter ur choice "<<endl;
		cout<<"1.insert at begin"<<endl;
		cout<<"2.insert at the end"<<endl;
		cout<<"3.insert at the Nth place "<<endl;
		cout<<"4.show all the elements "<<endl;
		cout<<"5.Length"<<endl;
		cout<<"6.delete"<<endl;
		cout<<"7.searc"<<endl;
		cout<<"8.exit"<<endl;
		cout<<"9.reverse"<<endl;
		cout<<"10.largest()"<<endl;
		int choose;
		cin>>choose;
		switch(choose)
		{
			case 1:
			InsertAtBegin();
			break;
			case 2:
			InsertAtEnd();
			break;
			case 3:
			InsertAtAnyWhere();
			break;
			case 4:
			showall();
			break;
			case 5:
			int len;
			len=Length();
			cout<<"length is "<<len<<endl;
			break;
			case 6:
			deleteele();
			break;
			case 7:
			search();
			break;
			case 8:
			//exit();
			break;
			case 9:
			//reverse();
			break;
			case 10:
			largest();
			break;
			default:
			cout<<"invalid input"<<endl;
			break;
		}
	}
}
void InsertAtBegin()
{
	Node *temp;
	temp=new Node();
	cout<<"enter the data"<<endl;
	cin>>temp->data;
	temp->left=NULL;
	temp->right=NULL;
	if(head==NULL)
	{
		head=temp;
	}
	else
	{
		temp->right=head;
		head->left=temp;
		head=temp;
	}
}
void InsertAtEnd()
{
	Node *temp,*p;
	temp=new Node();
	p=head;
	cout<<"enter the data"<<endl;
	cin>>temp->data;
	temp->left=NULL;
	temp->right=NULL;
	if(head==NULL)
	{
		head=temp;
	}
	else
	{
		while(p->right!=NULL)
		{
			p=p->right;
		}
		p->right=temp;
		temp->left=p;
	}
}
int Length()
{
	Node *temp;
	int count=0;
	temp=head;
	while(temp!=NULL)
	{
		count++;
		temp=temp->right;

	}
	return count;
}
void InsertAtAnyWhere()
{
	Node *temp,*p;
	temp=new Node();
	p=head;
	cout<<"enter the data"<<endl;
	cin>>temp->data;
	temp->left=NULL;
	temp->right=NULL;
	if(head==NULL)
	{
		head=temp;
	}
	else
	{
		cout<<"enter the location"<<endl;
		int loc;
		cin>>loc;
		if(loc>Length())
		{
			cout<<"invalid location"<<endl;
			cout<<"total length is "<<Length()<<endl;
		}
		else
		{
			if(loc==1)
			{
				p->left=temp;
				temp->right=p;
				head=temp;
			}
			else
			{
				
				for(int i=1;i<loc-1;i++)
				{
					p=p->right;
				}
				temp->right=p->right;
				p->right->left=temp;
				p->right=temp;
				temp->left=p;
			}
			
		}
	}
}
void showall()
{
	Node *temp;
	temp=head;
	if(head==NULL)
	{
		cout<<"list is empty"<<endl;
	}
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->right;
	}
}
void deleteele()
{
	cout<<"enter the location"<<endl;
	int loc;
	cin>>loc;
	if(loc>Length())
	{
		cout<<"location is greter than the length! the length of the list is "<<Length()<<endl;
	}
	else if(loc==1)
	{
		Node *temp;
		temp=head;
		head=temp->right;
		temp->right=NULL;
		head->left=NULL;
		cout<<"deleted item is "<<temp->data;
		delete temp;
	}
	else
	{
		Node *temp,*t;
		temp=head;
		t=head;
		for(int i=1;i<loc-1;i++)
		{
			temp=temp->right;
		}
		t=temp->right;
		temp->right=t->right;
		t->right=temp;
		t->right=NULL;
		t->left=NULL;
		delete t;
	}
}
void search()
{
	cout<<"enter the element"<<endl;
	int ele;
	cin>>ele;
	Node *temp=head;
	int pos=1;
	while(temp!=NULL)
	{
		if(temp->data==ele)
		{
			cout<<"the "<<ele<<" is found at "<<pos<<endl;
			return;
		}
		temp=temp->right;
		pos++;
	}
	
}
void largest()
{
	if(head==NULL)
	{
		cout<<"list is empty"<<endl;
	}
	else
	{
		
		Node *temp=head;
		int max;
		max=temp->data;
		while(temp->right!=NULL)
		{
			temp=temp->right;
			if(max<temp->data)
			{
				max=temp->data;
			}
		}
		cout<<"largest no int the list is "<<max<<endl;
	}
}
		
	
	
