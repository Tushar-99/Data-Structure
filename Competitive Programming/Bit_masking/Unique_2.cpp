#include<bits/stdc++.h>

using namespace std;

int main(){

    int *arr , n , ans = 0 , pos = 0 , res = 0;
    cin >> n;

    arr = new int[n];

    for(int i = 0 ; i < n ; i++)
        cin >> arr[i];

    for(int i = 0 ; i < n ; i++)
        ans ^= arr[i];

    int temp = ans;

    while(temp > 0){

        if((temp & 1) == 1)
            break;
        
        pos++;
        temp >>= 1;
    }

    for(int i = 0 ; i < n ; i++){
    
        if(((1 << pos) & arr[i]) == 1)
            res ^= arr[i];
    }

    cout << (res ^ ans) << " " << res; 
}