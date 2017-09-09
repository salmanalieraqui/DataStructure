#include <iostream>
using namespace std;
struct node{
    int info;
    struct node *next;
}sll;
void insert(sll *h,int value){
    sll *p,*t;
    t=h;
    if(h->next==NULL){
        p=new sll;
        h->next=p;
        p->next=NULL;
        p->info=value;
    }else{
        while(t->next!=NULL){
            t=t->next;
        }
        p=new sll;
        t->next=p;
        p->next=NULL;
        p->info=value;
    }
}
int detectloop(sll *h){
    sll *p=h,*t=h;
    while(p && t && t->next){
        p=p->next;
        t=t->next->next;
        if(p==t){
            cout<<"LOOP found"<<endl;
            return 1;
        }
    }
    cout<<"Loop not found"<<endl;
    return 0;
}
int main()
{
    sll *head=new sll;
    head->next=NULL;

    insert(head,6);
    insert(head,7);
    insert(head,9);
    insert(head,3);
    insert(head,1);
    detectloop(head);
    head->next->next->next=head;
    detectloop(head);
    return 0;
}
