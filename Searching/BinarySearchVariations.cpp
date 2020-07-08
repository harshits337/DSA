// Author  : Harshit Sharma
// Variations on BinarySearch Algorithm
// 1)Finding the first Occurrence of an element
// 2)Finding the last Occurrence of an element


#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long int
using namespace std;

ll firstOccurence(vector<ll> &array,ll element){
    ll low,high,mid;
    low = 0;
    high = array.size();
    ll ans = high;
    while(low<=high){
        mid = (low+high)/2;
        if(array[mid] >= element){
            ans=mid;
            high = mid-1;
        } else {
            low=mid+1;
        }
    }
    // If element not found it will return the least position where it should be inserted
    return ans;
}

ll lastOccurence(vector<ll> &array,ll element){
    ll low,high,mid;
    low = 0;
    high = array.size();
    ll ans = low;
    while(low<=high){
        mid = (low+high)/2;
        if(array[mid]<=element){
            low = mid+1;
            ans=mid;
        }
        else {
            high = mid-1;
        }
    }

    return ans;
}



int main(){
    ll i,j,n;
    cin>>n;
    vector<ll> array;
    for(i=0;i<n;i++){
        cin>>j;
        array.push_back(j);
    }

    for(i=0;i<10;i++){
        cin>>j;
        cout<<firstOccurence(array,j)<<" "<<lastOccurence(array,j)<<endl;
    }
    
}