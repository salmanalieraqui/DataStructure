#include<iostream>
using namespace std;
#define capacity 5
void printallele();
void deleteele();
void insert();
int front=0,rear=0;
int q[capacity];
int main()
{
	while(1)
	{
		cout<<"choose one"<<endl;
		cout<<"1.insert element"<<endl;
		cout<<"2.remove element"<<endl;
		cout<<"3.print all element"<<endl;
		cout<<"4.exit"<<endl;
		int choose;
		cin>>choose;
		switch(choose)
		{
			case 1:
			insert();
			break;
			case 2:
			deleteele();
			break;
			case 3:
			printallele();
			break;
			case 4:
			exit(0);
			break;
			default:
			cout<<"invalid input"<<endl;
			break;
		}
	}
}
void insert()
{
	
	if(rear==capacity)
	{
		cout<<"queue is full"<<endl;
	}
	else
	{
		cout<<"enter a element"<<endl;
		int ele;
		cin>>ele;
		q[rear]=ele;
		rear++;
	}
}
void deleteele()
{
	if(rear==front)
	{
		cout<<"queue is full"<<endl;
	}
	else
	{
		cout<<"deleted element is "<<q[0];
		for(int i=0;i<rear;i++)
		{
			q[i]=q[i+1];
		}
		rear--;
	}
}
void printallele()
{
	if(front==rear)
	{
		cout<<"queue is empty"<<endl;
	}
	else
	{
		cout<<"queue is ";
		for(int i=0;i<rear;i++)
		{
			cout<<q[i]<<" ";
		}
	}

}
		
