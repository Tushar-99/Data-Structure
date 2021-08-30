#include<bits/stdc++.h>

using namespace std;

int main(){

    int K , size , temp , r1 , r2 , count , j;
    cin >> size;
    cin >> K;
    int *arr = new int[size];
    for(int i = 0 ; i < size ; i++){
        cin>>arr[i];
    }

    sort(arr,arr+size);
    for(int i = 0 ; i < size ; i++){

        while(arr[i] == arr[i+1])
            i++;

        if(arr[i]-K >= r1 && arr[i+1]+K >= arr[j]){
            count++;
        }

    }
}