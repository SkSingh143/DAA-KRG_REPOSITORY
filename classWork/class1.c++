

#include <bits/stdc++.h>
using namespace std;
int binarySearchResult(int start,int end , int arr[],int size,int t){
    int result=0;
    int mid =start+end/2;
    for(int i=0;i<size;i++){
        result += mid/arr[i];
    }
    if(result>t){
        binarySearchResult(start,mid,arr,size,t);
    }else if(result<t){
        binarySearchResult(mid,end,arr,size,t);
    }else{
        return mid;
    }
}
int findLow(int t,int arr[],int n){
    int min = *min_element(arr, arr + n);
    int low =min*t;
    return low;
}
int main()
{
    int n,t;
    cin>>n>>t;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    int low = findLow(t,arr,n);
    
    int min_time = binarySearchResult(1,low,arr,n,t);
    cout<<min_time;
    
}