// Author : Harshit Sharma
// Binary Search Algorithm 

#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long int
using namespace std;

ll binarySearch(vector<ll> &array,ll element){
    ll low,high,mid;
    low =0;
    high = array.size();
    while(low<=high){
        mid = (low+high)/2;
        if(array[mid] == element ){
            return mid;
        }
        else if(array[mid] < element){
            low = mid+1;
        }
        else {
            high = mid-1;
        }
    }

    return -1;
}

int main(){
    ll i,j,n;
    cin>>n;
    vector<ll> array;
    for(i=0;i<n;i++){
        cin>>j;
        array.push_back(j);
    }
    sort(array.begin(),array.end());
    for(i=0;i<10;i++){
        cin>>j;
        cout<<binarySearch(array,j)<<endl;
    }
}