#include "LinkedList.h"
#include<iostream>
LinkedList::LinkedList(){this->head=nullptr;}

LinkedList::LinkedList(int A[],int size){
    this->head=new Node(A[0]);
    this->head->next=nullptr;
    Node *last=this->head;
    for(int i=1;i<size;i++){
        Node *t=new Node(A[i]);
        t->next=nullptr;
        last->next=t;
        last=t;
    }
}

LinkedList::~LinkedList(){
    Node *p;
    while(head){
        p=head;
        head=head->next;
        delete p;
    }
}

std::ostream &operator<<(std::ostream &os,const LinkedList &list){
    Node *p=list.head;

    while(p){
        os<<p->value<<" ";
        p=p->next;
    }
    os<<std::endl;
    return os;
}

void LinkedList::push_back(int value){
    if(!this->head){
        this->head=new Node(value);
    }
    else{
        Node *p=this->head;

        while(p->next) p=p->next;//moving to the last Node
        Node *add=new Node(value);//add->next its already null
        p->next=add;
    }
}

int LinkedList::size()const {
    int x=0;
    Node *p=this->head;

    while(p){
        x++;
        p=p->next;
    }
    return x;
}

bool LinkedList::operator<(const LinkedList &list){
    return this->size()<list.size();
}

bool LinkedList::operator==(const LinkedList &list){
    return this->size()==list.size();
}

int LinkedList::SumOfElement()const{
    int x=0;
    Node *p=this->head;

    while(p){
        x+=p->value;
        p=p->next;
    }
    return x;
}

int LinkedList::max(){
    Node *p=head;
    int x=p->value;
    p=p->next;
    while(p){
        if(x<p->value) x=p->value;
        p=p->next;
    }
    return x;
}

int LinkedList::min(){
    Node *p=head;
    int x=p->value;
    p=p->next;
    while(p){
        if(x>p->value) x=p->value;
        p=p->next;
    }
    return x;
}

int LinkedList::find(int value){
    Node *p=this->head;
    while(p){
        if(value==p->value) {return 1;}
        p=p->next;
    }
    return 0;
}

void LinkedList::insert(int index,int value){
    if(index==0){
        Node *nw=new Node(value);//by deafult next=nullptr;
        nw->next=head;
        head=nw;
    }
    else if(index>0&&index<=this->size()){
        Node *p=head;
        for(int i=0;i<index-1;i++) p=p->next;
        Node *nw=new Node(value);
        nw->next=p->next;
        p->next=nw;
    }
    else return;
}

void LinkedList::Delete(int index){
    if(index==1){
        Node *p=head;
        head=head->next;
        delete p;
    }
    else if(index>1&&index<=this->size()){
        Node *p=head,*tail=nullptr;
        for(int i=0;i<index-1;i++){
            tail=p;
            p=p->next;
        }
        tail->next=p->next;
        delete p;
    }
    else return;
}

bool LinkedList::isSorted(){
    Node *p=this->head;
    while(p->next){
        if(p->value>p->next->value) return 0;
        p=p->next;
    }
    return 1;

}

void LinkedList::RemoveDuplicated(){
    if(!this->isSorted()) return;
    Node *p=head,*r=head;
    p=p->next;
    while(p){
        if(p->value==r->value){
            r->next=p->next;
            delete p;
            p=r->next;
        }
        else{
            p=p->next;
            r=r->next;
        }
    }
}

void LinkedList::Reverse(){
    Node *r=nullptr,*q=nullptr,*p=head;

    while(p){
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    this->head=q;
}

bool LinkedList::isLoop(){
    Node *p=head,*q=head;
    do{
        p=p->next;
        q=q->next;
        p=p?p->next:nullptr;
    }while(p&&q&&p!=q);
    if(p==q)return true;
    return false;
}




