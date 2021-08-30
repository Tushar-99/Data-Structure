// Idea is to use selection sort
#include<bits/stdc++.h>

using namespace std;

void swap(int *a,int *b){
    
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

int main(){

    int temp , k , j , i , count = 0;
    int A[5] = {4 , 5 , 3 , 1 , 2};
    int size = 5;
    for(i = 0 ; i < size-1 ; i++){
        k = i;
        for(j = i + 1 ; j < size ; j++){
            if(A[k] > A[j]){ 
                k = j;
            }
        }
        if(A[k] < A[i]){
            count++;
            swap(&A[k] , &A[i]);
        }
    }
    cout << count << endl;
    for(i = 0 ; i < size ; i++)
        cout << A[i] << " ";
}