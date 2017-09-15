#include <iostream>

using namespace std;

typedef struct link_list{
    int info;
    struct link_list *next;
}sll;

void insert(sll *h,int v){
    sll *p,*t,*n;
    p=h;
    t=h->next;
    if(h->next==NULL){
        p=new sll;
        h->next=p;
        p->next=NULL;
        p->info=v;
    }else{
        while(t->info<=v&&t->next!=NULL){
            p=t;
            t=t->next;
        }
        if(t->info>=v){
            n =new sll;
            p->next=n;
            n->next=t;
            n->info=v;
        }else{
            n=new sll;
            t->next=n;
            n->next=NULL;
            n->info=v;
        }
    }
}
int del(sll *h){
    sll *p=h,*t;
    t=p;
    if(h->next==NULL){
        cout <<"List is empty";
    }else{
        while(p->next!=NULL){
            t=p;
            p=p->next;
        }
        t->next=NULL;
        int data = p->info;
        delete p;
        return data;
    }
}
void trav(sll*h){
    sll *p;
    p=h->next;
    while(p->next!=NULL){
        cout <<p->info<<"\t";
        p=p->next;
    }
    cout <<p->info<<endl;
}
sll *merge_sll(sll *h1,sll *h2){
    sll *h3=new sll;
    h3->next=NULL;
    sll *p,*t;
    p=h1;
    t=h2;
    while(p->next!=NULL){
        int data = del(p);
        insert(h3,data);
    }
    while(t->next!=NULL){
        int data = del(t);
        insert(h3,data);
    }
    return h3;
}
int main()
{
    sll *head1=new sll;
    head1->next=NULL;

    insert(head1,9);
    insert(head1,45);
    insert(head1,55);
    insert(head1,85);
    insert(head1,178);
    trav(head1);
    sll *head2=new sll;
    head2->next=NULL;

    insert(head2,77);
    insert(head2,78);
    insert(head2,33);
    insert(head2,56);
    insert(head2,13);
    trav(head2);
    sll *head3=new sll;
    head3->next=NULL;

    head3=merge_sll(head1,head2);
    trav(head3);
    return 0;
}
