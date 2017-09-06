#include<iostream>
using namespace std;
void InsertAtBegin();
void InsertAtEnd();
void InsertAtAnyWhere();
void Print();
int Length();
void Delete();
struct Node
{
	int data;
	Node *link;
};
Node * last=NULL;
int main()
{
	while(1)
	{
		cout<<"enter ur choice"<<endl;
		cout<<"1.Insert at the begin"<<endl;
		cout<<"2.Insert at the end"<<endl;
		cout<<"3.insert at Nth place"<<endl;
		cout<<"4.show all the elements"<<endl;
		cout<<"5.Delete"<<endl;
		cout<<"6.length of the list"<<endl;
		cout<<"7.exit"<<endl;
		int choice,num;
		cin>>choice;
		switch(choice)
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
			Print();
			break;
			case 5:
			Delete();
			break;
			break;
			case 6:
			num=Length();
			if(num==-1)
			{
				cout<<"length is 0"<<endl;
			}
			else
			{
				
				cout<<"length is "<<num<<endl;
			}
			break;
			case 7:
			exit(0);
			break;
			default:
			cout<<"invalid input"<<endl;
			break;
		} 
	} 
}
void InsertAtBegin()
{
	Node *temp=new Node();
	if(last==NULL)
	{
		cout<<"enter the data"<<endl;
		cin>>temp->data;
		temp->link=NULL;
		temp->link=temp;
		last=temp;
	}
	else
	{
		cout<<"enter the data"<<endl;
		cin>>temp->data;
		temp->link=NULL;
		temp->link=last->link;
		last->link=temp;
	}
}
void InsertAtEnd()
{
	Node *temp=new Node();
	if(last==NULL)
	{
		cout<<"enter the data"<<endl;
		cin>>temp->data;
		temp->link=NULL;
		temp->link=temp;
		last=temp;
	}
	else
	{
		cout<<"enter the data"<<endl;
		cin>>temp->data;
		temp->link=NULL;
		temp->link=last->link;
		last->link=temp;
		last=temp;
	}
}
void InsertAtAnyWhere()
{
	if(last==NULL)
	{
		cout<<"list is empty"<<endl;
	}
	else
	{
		cout<<"enter the location"<<endl;
		int a;
		cin>>a;
		Node *temp=new Node();
		Node *t;
		t=last;
		t=t->link;
		cout<<"enter the data"<<endl;
		cin>>temp->data;
		temp->link=NULL;
		for(int i=1;i<a-1;i++)
		{
			t=t->link;
		}
		temp->link=t->link;
		t->link=temp;
	}
}
void Print()
{
	Node *temp=last;
	temp=last->link;
	do
	{
		cout<<temp->data<<" ";
		temp=temp->link;
	}while(temp!=last->link);
		
}
int Length()
{
	Node *temp;
	temp=last;
	int count=0;
	if(last==NULL)
	{
		return -1;
	}
	else
	{
		
		temp=temp->link;
		do
		{
			count++;
			temp=temp->link;
		}while(temp!=last->link);
		return count;
	}
}
void Delete()
{
	cout<<"enter the location"<<endl;
	int loc;
	cin>>loc;
	if(loc>Length())
	{
		cout<<"list is of only size "<<Length()<<endl;
	}
	else if(loc==Length())
	{
		 Node *temp=last;
		 Node *t2=last;
		 t2=t2->link;
		 for(int i=1;i<loc;i++)
		 {
			 temp=temp->link;
			 t2=t2->link;
		 }
		 last=temp;
		 temp->link=t2->link;
		 t2->link=NULL;
		 cout<<"delted item is "<<t2->data<<endl;
		 delete t2;
	 }
	 		
	else
	{
		Node *t=new Node();
		Node *t2=new Node();
		t=last;
		t2=last;
		t2=t2->link;
		for(int i=1;i<loc;i++)
		{
			t=t->link;
			t2=t2->link;
		}
		t->link=t2->link;
		t2->link=NULL;
		cout<<"deleted item is "<<t2->data;
		delete t2;
		
	}
}
			
			
		
		
