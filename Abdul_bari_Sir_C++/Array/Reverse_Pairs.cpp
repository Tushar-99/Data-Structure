#include<bits/stdc++.h>

using namespace std;

//Brute force
int reversePairs(int a[],int len){

    int i,j,c = 0;
    for(i = 0 ; i < len ; i++){
       for(j = 1 ; j < len ; j++){
           if(a[i] > 2*a[j]){
               c++;
           }
       } 
    }
    return c;
}

//optimized one


int main(){

    int a[] = {2,4,3,5,1};
    cout<<reversePairs(a,5);
}