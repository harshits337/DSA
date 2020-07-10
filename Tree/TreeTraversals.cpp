// Author : Harshit Sharma
// Basic Binary Tree structure and travsersals

#include<iostream>
#define ll long long int
using namespace std;

class Node{
    public:
        ll data;
        Node * left;
        Node * right;
        Node(ll value){
            data= value;
            left = nullptr;
            right = nullptr;
        }
};

class Tree {
    public:
        Node * root;
        Tree(){
            root = nullptr;
        }
        Node * insert(ll index, ll data);
        void preOrder(Node * node);
        void inOrder(Node * node);
        void postOrder(Node * node);
};

Node * Tree :: insert( ll index,ll data){
    ll leftNode,rightNode;
    Node * newNode = new Node(data);
    if(root == nullptr){
        root = newNode;
    }
    cout<<"Value for left node (-1) for null for index "<<2*index<<":";
    cin>>leftNode;
    if(leftNode != -1){
        newNode->left = insert(2*index,leftNode);
    }
    cout<<"Value for right node(-1) for null for index "<<2*index+1<<":";
    cin>>rightNode;
    if(rightNode!=-1){
        newNode->right = insert(2*index+1,rightNode);
    }

    return newNode;

}

void Tree :: preOrder(Node * node){
    if(node){
        cout<<node->data<<" ";
        preOrder(node->left);
        preOrder(node->right);
    } 
}

void Tree :: inOrder(Node * node){
    if(node){
        inOrder(node->left);
        cout<<node->data<<" ";
        inOrder(node->right);
    }
}

void Tree :: postOrder(Node * node){
    if(node){
        postOrder(node->left);
        postOrder(node->right);
        cout<<node->data<<" ";
    }
}

int main(){

    Tree * tree = new Tree();
    
    ll rootValue;
    cin>>rootValue;
    tree->insert(1,rootValue);
    cout<<"PreOrder Travsesal is : ";
    tree->preOrder(tree->root);
    cout<<endl;
    
    cout<<"inOrder Traversal is : ";
    tree->inOrder(tree->root);
    cout<<endl;

    cout<<"Post Order Traversal is : ";
    tree->postOrder(tree->root);
    cout<<endl;

}