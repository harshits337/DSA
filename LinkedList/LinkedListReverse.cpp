// Author : Harshit Sharma
// Linked List reverse

#include<iostream>
#define ll long long int
using namespace std;

class Node{
    public :
        ll data;
        Node * next;
        Node(ll value){
            data= value;
            next = nullptr;
        }
};

class LinkedList {
    public :
        Node * head = nullptr;
        void insert(ll data);
        void display();
        void reverse();
        void recursiveReverse(Node * currentNode, Node * prevNode);
};

void LinkedList :: reverse(){
    Node * currentNode = head;
    Node * nextNode = nullptr;
    Node * prevNode = nullptr;
    while(currentNode){
        nextNode = currentNode->next;
        currentNode->next = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
    }
    head = prevNode;
}

void LinkedList :: recursiveReverse(Node * currentNode, Node * prevNode){
    if(currentNode){
        recursiveReverse(currentNode->next,currentNode);
        currentNode->next = prevNode;
    }
    else{
        head = prevNode;
    }
}

void LinkedList :: insert(ll data){
    Node * newNode = new Node(data);
    if(head == nullptr){
        head = newNode;
        return;
    }
    Node * temp = head;
    while(temp->next){
        temp =temp->next;
    }
    temp->next = newNode;
}

void LinkedList :: display(){
    Node * temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp =temp->next;
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
    linkedList.insert(6);
    linkedList.display();
    linkedList.reverse();
    // After Reverse
    linkedList.display();
    // Reverse using recursion
    linkedList.recursiveReverse(linkedList.head,nullptr);
    linkedList.display();
}