// Author : Harshit Sharma
// Linked List Deletion operations

#include<iostream>
#define ll long long int
using namespace std;

class Node {
    public :
        ll data;
        Node * next ;
        Node(ll value) {
            data = value;
            next = nullptr;
        }
};

class LinkedList {
    public:
        Node * head = nullptr;
        void insert(ll data);
        void deleteFirst();
        void deleteLast();
        void deleteAtPos(ll pos);
        void display();
};

void LinkedList :: insert(ll data){
    Node * newNode = new Node(data);
    if(head == nullptr){
        head = newNode;
        return;
    }

    Node * temp = head;
    while(temp->next){
        temp = temp->next;
    }
    temp->next = newNode;
}

void LinkedList :: deleteFirst(){
    if(head == nullptr){
        return;
    }
    Node * temp = head;
    head = head ->next;
    free(temp);
}

void LinkedList :: deleteLast(){
    if(head == nullptr){
        return;
    }
    if(head->next == nullptr){
        deleteFirst();
    }
    Node * temp = head;
    while(temp->next && temp->next->next){
        temp = temp->next;
    }
    Node * temp2 = temp->next;
    temp ->next = nullptr;
    free(temp2);
}

void LinkedList :: deleteAtPos(ll pos){
    if(pos == 0 || head->next== nullptr){
        deleteFirst();
    }
    
    ll cnt = 0;
    Node * temp =head;
    while(temp->next && temp->next->next && cnt < pos-1){
        cnt++;
        temp =temp->next;
    }
    Node * temp2 = temp->next;
    temp->next = nullptr;
    free(temp2);
}

void LinkedList :: display(){
    Node * temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
    LinkedList linkedList;
    linkedList.insert(1);
    linkedList.insert(2);
    linkedList.insert(3);
    linkedList.insert(4);
    linkedList.insert(5);
    linkedList.display();
    linkedList.deleteFirst();
    linkedList.display();
    linkedList.deleteLast();
    linkedList.display();
    linkedList.deleteAtPos(1);
    linkedList.display();
    linkedList.deleteFirst();
    linkedList.display();
    linkedList.insert(2);
    linkedList.insert(3);
    linkedList.display();
    linkedList.deleteAtPos(0);
    linkedList.display();
    
}


