#include <bits/stdc++.h>
using namespace std;

void insert(int H[],int i){
    int temp;
    temp = H[i];

    while(i>1 && temp > H[i/2]){ // use < for min heap
        H[i]=H[i/2];
        i=i/2;
    }
    H[i] = temp;
}

int del(int H[], int lastIn){
    
    int i=1,j = 2*i;   // always first value will be deleted

    int val = H[1];
    H[1]= H[lastIn]; /// swap(H[1], H[lastIn]);
    H[lastIn] = val;

    while(j<lastIn-1){
        if(H[j+1]>H[j])
            j++;
        if(H[i]<H[j]){
            swap(H[i], H[j]);
            i=j;
            j=2*i;
        }
        else break;
    }
    //sz--;
    return val;
}

int main()
{
    int i, j;
    int H[]= {0, 2, 5, 8, 9, 4, 10, 7}; 
    int sz = 7;
    
    for(int i = 2; i<sz;i++){
        insert(H,i);       // construction of heap
    }
    for(int i=1; i<=sz; i++){
        cout << H[i] << " ";
    }
    cout << endl;

    for(int i = 7; i>1; i--){
        cout << del(H, i) << endl;   //working as priyority queue pop()
    }

    for(int i=1; i<=sz; i++){
        cout << H[i] << " ";        // sorted by heap sort 
    }

    return 0;
}