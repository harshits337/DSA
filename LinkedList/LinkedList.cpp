// Author : Harshit Sharma
// Linked List Implementation for insertion operations

#include<iostream>
#define ll long long int
using namespace std;

class Node {
    public :
        ll data;
        Node * next;
        Node(ll value){
            data = value;
            next = NULL;
        }
};

class LinkedList{
    public :
        Node * head = NULL;
        void insert(ll data);
        void insertAtFront(ll data);
        void insertAtPosition(ll data, ll pos);
        void display();
};

void LinkedList :: insert(ll data){
    Node * newNode = new Node(data);

    if(head == NULL){
        head = newNode;
        return;
    }

    Node * temp = head;
    while(temp->next){
        temp = temp ->next;
    }
    temp->next = newNode;

}

void LinkedList :: display(){
    Node * temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void LinkedList :: insertAtFront(ll data){
    Node * newNode = new Node(data);
    if(head == NULL){
        head = newNode;
        return;
    }
    newNode ->next = head;
    head = newNode;
}

void LinkedList :: insertAtPosition(ll data, ll pos){

    if(pos==0){
        insertAtFront(data);
        return;
    }
    ll count = 0;
    Node * temp = head;
    while(temp->next && count<pos-1){
        count++;
        temp = temp->next;
    }
    Node * newNode = new Node(data);
    newNode ->next = temp->next;
    temp->next = newNode;
}

int main(){

    LinkedList linkedList;
    linkedList.insert(1);
    linkedList.insert(2);
    linkedList.insert(3);
    linkedList.display();
    linkedList.insertAtFront(4);
    linkedList.display();
    // 0 based indexing
    linkedList.insertAtPosition(5,0);
    linkedList.display();


}