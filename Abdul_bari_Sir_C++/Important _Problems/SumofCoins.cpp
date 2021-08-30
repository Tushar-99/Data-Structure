#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int coinWays(int *A, int target,int n){

    int total,no,j;
    int B[n+1] = {};
    B[0] = 1;
    if(target == 0) return 1;

    for(int i = 1 ; i <= target ; i++){
        total = 0;
        no = A[i-1];
        j = 0;
        while(j < n){
            if(i-j >= 0){
                total += B[i-j];
            }
            j++;
        }
    }

    return total;
}

int coinWays(int n){

    int count;
    int total= 0;
    int B[3] = {1,2,5};
    if(n == 0) return 1;

    for(int  i = 1 ; i < n ; i++)
        if(n - i >= 0) total += coinWays(n - B[i-1]);
    
    return total;
}

int main(){

    int A[] = {1,2,5};
    int target = 13;
    cout<<coinWays(13);

    return 0;
}
