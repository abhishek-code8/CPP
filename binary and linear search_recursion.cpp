#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int lsearch(int *arr,int i,int n,int k){
    if(i==n){
        return -1;
    }
    if(arr[i]==k){
        return i;
    }
    return lsearch(arr,i+1,n,k);
}

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int lsearch(int *arr,int i,int n,int k){
    if(i==n){
        return -1;
    }
    if(arr[i]==k){
        return i;
    }
    return lsearch(arr,i+1,n,k);
}

int bsearch(int *arr,int l,int r,int k){
    if(l<=r){
        int mid=l+(r-l)/2;
        if(arr[mid]==k){
            return mid;
        }
        else if(arr[mid]>k){
            return bsearch(arr,l,mid-1,k)
        }
        else
        {
            return bsearch(arr,mid+1,r,k);
        }
        
    }
    else
    {
        return -1;
    }
}
int main(){
    int a[]={1,5,3,456,45,324,4};
    int p=sizeof(a)/sizeof(a[0]);
    sort(a,a+p);
    int k=3;
    int n=7;
    cout<<lsearch(a,0,n,k)<<endl;
    cout<<bsearch(a,0,n,k);
    return 0;

}


int main(){
    int a[]={1,5,3,456,45,324,4};
    int k=3;
    int n=7;
    cout<<lsearch(a,0,n,k);
    return 0;

}
