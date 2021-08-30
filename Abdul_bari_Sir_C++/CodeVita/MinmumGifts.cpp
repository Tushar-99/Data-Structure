#include<bits/stdc++.h>

using namespace std;

int main(){

    int size , prev, gifts = 0, next = 0, temp;
    int *arr;
    int *gift;
    int t;
    cin >> t;
    
    while(t--){

        cout <<"Enter the size of the array"<<endl;
        cin >> size;
        arr = new int[size];
        gift = new int[size]; 
        gift [0] = 1;
        cout << "Enter the elements of the array"<<endl;
        for(int i = 0 ; i < size ; i++){
            cin >> arr[i];
        }

        for(int i = 1 ; i < size ; i++){

            if(arr[i] > arr[i-1])
                gift[i] = gift[i-1] + 1;
            
            else
                gift[i] = 1;
        }
    
        for(int i = size-2 ; i >=0 ; i--){

            if(arr[i] > arr[i+1] && gift[i] <= gift[i+1])
                gift[i] = gift[i+1] + 1;
            
        }

        for(int i = 0 ; i < size ; i++){
            gifts += gift[i];
        } 
    cout << gifts;
    }
}
