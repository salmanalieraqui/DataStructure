#include <iostream>

using namespace std;

typedef struct stack{
    int top,capacity;
    int *arr ;
}stk;

void createstack(stk *s,int v){
    s->capacity=v;
    s->top=0;
    s->arr=new int[sizeof(int)*s->capacity];
}
void push(stk *s,int value){
    if(s->top==s->capacity){
        cout <<"Stack is Full"<<endl;
    }else{
        s->arr[s->top++]=value;
    }
}
int pop(stk *s){
    if(s->top==0){
        cout <<"Stack is empty"<<endl;
        return -1;
    }else{
        return s->arr[--s->top];
    }
}
void copystack(stk *s1,stk *s2){
    stk *s3=new stk;
    createstack(s3,7);
    while(s1->top!=0){
        push(s3,pop(s1));
    }
    while(s3->top!=0){
        push(s2,pop(s3));
    }
    delete[] s3->arr;
    delete s3;
}
int main()
{
    stk *s1=new stk;
    stk *s2=new stk;
    createstack(s1,7);
    createstack(s2,7);
    push(s1,5);
    push(s1,6);
    push(s1,7);
    push(s1,8);
    push(s1,9);

    copystack(s1,s2);
    cout <<pop(s2)<<endl;
    cout <<pop(s2)<<endl;
    cout <<pop(s2)<<endl;
    cout <<pop(s2)<<endl;
    cout <<pop(s2)<<endl;
    return 0;
}
