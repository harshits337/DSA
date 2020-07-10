// Author : Harshit Sharma
// Merge two sorted Linked list

#include<iostream>
#define ll long long int
using namespace std;

class Node{
    public :
        ll data;
        Node * next;
        Node(ll value){
            data = value;
        }
};

class LinkedList {
    public :
        Node * head = nullptr;
        void insert(ll data);
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
    temp->next= newNode;   
}

void LinkedList :: display(){
    Node * temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

// Main Function to merge 
Node * Merge(Node * head1, Node* head2){
    if(head1 == nullptr){
        return head2;
    }
    if(head2 == nullptr){
        return head1;
    }

    Node * result = nullptr;
    if(head1->data<=head2->data){
        result = head1;
        result->next= Merge(head1->next,head2);
    } else {
        result = head2;
        result->next = Merge(head1,head2->next);
    }

    return result;
}

int main(){
    LinkedList first;
    LinkedList second;

    ll i,j,n,m,val;
    cin>>n>>m;  // lengths of first and second list respectively
    for(i=0;i<n;i++){
        cin>>val;
        first.insert(val);
    }
    for(i=0;i<m;i++){
        cin>>val;
        second.insert(val);
    }
    cout<<"First List"<<endl;
    first.display();

    cout<<"Second List"<<endl;
    second.display();

    first.head = Merge(first.head,second.head);
    cout<<"After Merging"<<endl;
    first.display();
}