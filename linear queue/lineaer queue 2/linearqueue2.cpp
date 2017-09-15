#include<iostream>
using namespace std;
struct Arrayqueue
{
	int front;
	int rear;
	int capacity;
	int *data;
};
Arrayqueue* Createqueue(int cap)
{
	Arrayqueue *temp=new Arrayqueue();
	temp->capacity=cap;
	temp->front=0;
	temp->rear=0;
	temp->data=new int[temp->capacity];
	return temp;
}
void insert(Arrayqueue *queue)
{
	if(queue->rear==queue->capacity)
	{
		cout<<"queue is full"<<endl;
	}
	else
	{
		cout<<"enter the data"<<endl;
		int d;
		cin>>d;
		queue->data[queue->rear]=d;
		queue->rear++;
	}
}
void deleteele(Arrayqueue *queue)
{
	if(queue->rear==0)
	{
		cout<<"queue is empty"<<endl;
	}
	else
	{
		int deletedlele;
		deletedlele=queue->data[queue->front];
		queue->rear--;
		cout<<"deleted ele is "<<deletedlele<<endl;
		for(int i =0;i<queue->rear;i++)
		{
			queue->data[i]=queue->data[i+1];
		}
	}
}
void printallele(Arrayqueue *queue)
{
	if(queue->rear==0)
	{
		cout<<"queue is empty"<<endl;
	}
	else
	for(int i=0;i<queue->rear;i++)
	{
		cout<<queue->data[i]<<" ";
	}
}
	
	
int main()
{
	cout<<"enter the size of the queue"<<endl;
	int size;
	cin>>size;
	Arrayqueue *queue;
	queue=Createqueue(size);
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
			insert(queue);
			break;
			case 2:
			deleteele(queue);
			break;
			case 3:
			printallele(queue);
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
