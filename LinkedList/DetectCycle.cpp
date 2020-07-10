// Author : Harshit Sharma
// Detect cycle in a linked list
//  Here we will point the last node of the linked list point to the 4th node just for the sake of explanation
// Also we will consider that the linked list consists of 8 nodes only
#include<iostream>
#define ll long long int
using namespace std;

class Node {
    public :
        ll data;
        Node * next;
        Node(ll value){
            data = value;
            next = nullptr;
        }
};

class LinkedList {
    public:
        Node * head = nullptr;
        Node * cycleNode = nullptr;
        void insert(ll data);
        void display();
        bool detectCycle();
        
};

// Main Algorithm
bool LinkedList :: detectCycle(){
    Node * first = head;
    Node * second = head;
    while(first->next && second->next && second->next->next){
        first = first->next;
        second = second->next->next;
        if(first == second){
            return true;
        }
    }

    return false;
}

void LinkedList :: insert(ll data){
    Node * newNode = new Node(data);
    if(head == nullptr){
        head = newNode;
        return;
    }
    Node * temp =head;
    while(temp->next){
        temp = temp->next;
    }
    temp->next = newNode;
    if(data == 4){
        cycleNode = newNode;
    }
    if(data ==8){
        newNode->next = cycleNode;
    }

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
    linkedList.insert(6);
    linkedList.insert(7);
    linkedList.insert(8);
    // linkedList.display();
    if(linkedList.detectCycle()){
        cout<<"Cycle Detected"<<endl;
    } else{
        cout<<"No cycle present"<<endl;
    }
}