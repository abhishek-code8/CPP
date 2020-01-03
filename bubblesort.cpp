#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void swap(int *a,int *b){
    int temp=0;
    temp=*a;
    *a=*b;
    *b=temp;
}

void bbsortrecur(int *arr,int n,int i)
{
    if(i==n-2)
    return ;
    if(arr[i]>arr[i+1])
    swap(arr[i],arr[i+1]);
    return (arr,n,i+1);
}

void bubblesort(int *arr,int n){
    for(int i=0;i<n-1;++i){
        for(int j=0;j<n-i-1;++j){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }

}

int main(){
    int a[]={1,8,7,5,6,8,4,5,6,9,8,3};
    int n=sizeof(a)/sizeof(int);
    bubblesort(a,n);
    for(int i=0;i<n;++i){
        cout<<a[i]<<" ";
    }
    return 0;
}
