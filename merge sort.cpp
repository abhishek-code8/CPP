#include<iostream>
#include<bits/stdc++.h>


// Follow 3 steps
// 1. Devide
//2. Sort
//3. Merge
using namespace std;

void merge(int *a,int s,int e){
    int mid=(s+e)/2;
    int i=s;
    int j=mid+1;
    int k=s;
    int temp[100];
    while(i<=mid && j<=e){
        if(a[i]<a[j]){
            temp[k]=a[i];
            ++i;
            k++;
        }
        else
        {
            temp[k]=a[j];
            k++;
            ++j;
        }
    }
        while(i<=mid){
            temp[k++]=a[i++];
        }
        while(j<=e){
            temp[k++]=a[j++];
        }



    for(int i=s;i<=e;++i){
            a[i]=temp[i];
        }
}

void mergesort(int *a,int s,int e){

    //  Base case - 1 or 0 elements
    if(s>=e)
    {
        return ;
    }
    int mid=(s+e)/2;
    // Recursively the array - s, mid and mid+1,e
    mergesort(a,s,mid);
    mergesort(a,mid+1,e);
    merge(a,s,e);
}

int main(){
    int a[]={1,5,2,6,7,4};
    int n=sizeof(a)/sizeof(int);
    mergesort(a,0,n-1);
    for(int i=0;i<n;++i){
        cout<<a[i]<<",";
    }


    return 0;
}