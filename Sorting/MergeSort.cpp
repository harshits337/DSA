// Author : Harshit Sharma
// Implementation of Merge Sort Algorithm

#include<iostream>
#include<vector>
#define ll long long int
using namespace std;

void display(vector<ll> & array){
    for(ll i=0;i<array.size();i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

void merge(vector<ll> &array, ll start, ll mid,ll end){
    ll i,j,k,m,n;
    m = mid-start+1;
    n = end-mid;
    vector<ll> first;
    vector<ll> second;
    for(i=start;i<=mid;i++){
        first.push_back(array[i]);
    }
    for(i=mid+1;i<=end;i++){
        second.push_back(array[i]);
    }
    i=0,j=0,k=start;
    while(i<m && j<n){
        if(first[i]<=second[j]){
            array[k++] = first[i];
            i++;
        } else {
            array[k++] =second[j];
            j++;
        }
    }

    while(i<m){
        array[k++] = first[i++];
    }
    while(j<n){
        array[k++] = second[j++];
    }

    display(array);

}



void mergeSort(vector<ll> &array, ll start, ll end){
    if(start<end){
        ll mid = (start+end)/2;
        mergeSort(array,start,mid);
        mergeSort(array,mid+1,end);
        merge(array,start,mid,end);
    }
}

int main(){
    ll i,j,n;
    vector<ll> array;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>j;
        array.push_back(j);
    }
    mergeSort(array,0,n-1);
    display(array);
}