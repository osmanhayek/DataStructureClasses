#include<iostream>
#include "LinkedList.cpp"

using namespace std;

int main(){
    
    int A[]={1,1,1,2,2,5,5,7,10};
    int size=sizeof(A)/sizeof(int);

    LinkedList list(A,size);

    cout<<list;

    list.RemoveDuplicated();
    cout<<list;
    list.Reverse();
    cout<<list;
    
    return 0;
}