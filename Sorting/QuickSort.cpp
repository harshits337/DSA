// Author : Harshit Sharma
// Implementation of Quick Sort Algorithm

#include<iostream>
#include<vector>
#define ll long long int

using namespace std;

void display(vector<ll> array){
    for(int i=0;i<array.size();i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

ll partitionIndex(vector<ll> &array, ll start, ll end){
    ll pivot = array[end];
    cout<<start<<" "<<end<<endl;
    ll i,j,temp,partionIndexValue = start-1;
    for(i=start;i<end;i++){
        if(array[i]<=pivot){
            partionIndexValue++;
            temp = array[i];
            array[i] = array[partionIndexValue];
            array[partionIndexValue] = temp;
        }
    }

    partionIndexValue++;
    temp = pivot;
    array[end] = array[partionIndexValue];
    array[partionIndexValue] = temp;
    return partionIndexValue;
}

void quickSort(vector<ll> &array, ll start, ll end){
    if(start<end){
        ll partition = partitionIndex(array,start,end);
        quickSort(array,start,partition-1);
        quickSort(array,partition+1,end);
    }
}

int main(){
    ll n,i,j;
    cin>>n;
    vector<ll> array;
    for(i=0;i<n;i++){
        cin>>j;
        array.push_back(j);
    }
    quickSort(array,0,n-1);
    display(array);
}