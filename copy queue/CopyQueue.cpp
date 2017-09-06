#include <iostream>

using namespace std;

typedef struct queue{
    int front,rear;
    int capacity;
    int *arr;
}que;

void createqueue(que *q,int value){
    q->capacity=value;
    q->rear=q->front=-1;
    q->arr= new int[sizeof(int)*q->capacity];
}
void enque(que *q,int value){
    if(q->rear==q->capacity){
        cout <<"Queue is Full"<<endl;
    }else{
        q->rear=q->rear+1;
        q->arr[q->rear]=value;
        if(q->front==-1){
            q->front=q->rear;
        }
    }
}
int deque(que *q){
    int data;
    if(q->front==-1){
        cout <<"Queue is Empty"<<endl;
        return -1;
    }else{
        data = q->arr[q->front];
        if(q->front==q->rear){
            q->front=q->rear=-1;
        }else{
            q->front=q->front+1;
        }
        return data;
    }
}
void copyqueue(que *q1,que *q2){
    que *q3 =new que;
    createqueue(q3,7);
    while(q1->front!=-1){
        enque(q3,deque(q1));
    }
    while(q3->front!=-1){
        enque(q2,deque(q3));
    }
    delete[] q3->arr;
    delete q3;
}
int main()
{
    que *q1 = new que;
    que *q2 = new que;
    createqueue(q1,7);
    createqueue(q2,7);
    enque(q1,4);
    enque(q1,6);
    enque(q1,8);
    enque(q1,2);
    enque(q1,7);

    copyqueue(q1,q2);
    cout <<deque(q2)<<endl;
    cout <<deque(q2)<<endl;
    cout <<deque(q2)<<endl;
    cout <<deque(q2)<<endl;
    cout <<deque(q2)<<endl;
    return 0;
}
