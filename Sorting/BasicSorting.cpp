// Author : Harshit Sharma
// Implementation for bubbleSort, Insertion Sort, Selection Sort

#include<iostream>
#include<vector>
#define ll long long int
using namespace std;


// For passing an array as call by value to a function we wrap it into a structure/class
// and pass the object to all the functions.
struct Node {
    vector<ll> list;
};

void display(Node array){
    for(int i=0;i<array.list.size();++i){
        cout<<array.list[i]<<" ";
    }
    cout<<endl;
}

void bubbleSort(Node array){
    ll i,j,temp;
    for(i=0;i<array.list.size();++i){
        for(j=1;j<array.list.size()-i;++j){
            if(array.list[j]<array.list[j-1]){
                temp = array.list[j-1];
                array.list[j-1]=array.list[j];
                array.list[j] = temp;
            }
        }
    }
    display(array);
}

void selectionSort(Node array){
    ll i,j,min,minInd;
    for(i=0;i<array.list.size();++i){
        min = array.list[i];
        minInd = i;
        for(j=i+1;j<array.list.size();++j){
            if(array.list[j]<min){
                min = array.list[j];
                minInd = j;
            }
        }

        ll temp = array.list[minInd];
        array.list[minInd] = array.list[i];
        array.list[i] = temp;
    }
    display(array);
}

void insertionSort(Node array){
    ll i,j,key;
    for(i=0;i<array.list.size();++i){
        key = array.list[i];
        j=i-1;
        while(j>=0 && key<array.list[j]){
            array.list[j+1]= array.list[j];
            --j;
        }
        array.list[j+1] = key;
    }

    display(array);
}
int main(){

    Node array;
    ll i,j,n;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>j;
        array.list.push_back(j);
    } 

    bubbleSort(array);
    selectionSort(array);
    insertionSort(array);
}