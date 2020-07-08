// Author : Harshit Sharma
// Implementation for Heap Sort Algorithm

#include<iostream>
#include<vector>
#define ll long long int
using namespace std;

void heapify(vector<ll> &array,ll heapSize,ll index){
    
    ll largest = array[index];
    ll largestIndex = index;
    if(index*2<=heapSize && array[index*2]>largest){
        largest = array[index*2];
        largestIndex = index*2;
    }

    if(index*2 +1 <=heapSize && array[index*2+1]>largest){
        largest = array[index*2+1];
        largestIndex = index*2+1;
    }

    if(largestIndex != index){
        ll temp = array[index];
        array[index] = array[largestIndex];
        array[largestIndex] = temp;
        heapify(array,heapSize,largestIndex);

    }
}

// Convert Array to MaxHeap
void buildHeap(vector<ll> &array,ll heapSize){
    for(ll i=heapSize/2 ; i>0;i--){
        heapify(array,heapSize,i);
    }
}

void HeapSort(vector<ll> &array, ll heapSize){

    if(!heapSize)
        return;

    // Swap the root node of heap with last node and apply heapify on root
    // With this the largest element resides at end of the array and heapify balances the heap
    ll maxElement = array[1];
    array[1] = array[heapSize];
    array[heapSize] = maxElement;
    heapify(array,heapSize-1,1);
    HeapSort(array,heapSize-1);

}

void display(vector<ll> &array){
    for(ll i=1;i<array.size();i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

int main(){
    ll i,j,n;
    cin>>n;
    vector<ll> array;

    // Following 1-based indexing for array
    array.push_back(0);
    for(i=0;i<n;i++){
        cin>>j;
        array.push_back(j);
    }
    buildHeap(array,n);
    HeapSort(array,n);
    display(array);
}