#ifndef _LNODE_H_
#define _LNODE_H_
#include<iostream>
struct Node{
    int value;
    Node *next;

    Node(int value=0):value{value},next{nullptr}{}
};

class LinkedList{
protected:
    Node *head;
public:
    friend std::ostream &operator<<(std::ostream &os,const LinkedList &list);
    LinkedList();
    LinkedList(int A[],int size);
    void push_back(int value);
    int size()const;
    int SumOfElement()const;
    int max();
    int min();
    int find(int value);
    void insert(int index,int value);
    void Delete(int index);
    bool isSorted();
    void RemoveDuplicated();
    void Reverse();
    bool isLoop();
    bool operator<(const LinkedList&list);
    bool operator==(const LinkedList&list);

    

    
    ~LinkedList();
};






#endif //_LNODE_H_