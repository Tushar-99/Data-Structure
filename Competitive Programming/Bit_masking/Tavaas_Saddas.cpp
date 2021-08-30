#include<bits/stdc++.h>

using namespace std;

int main(){

    int N , ind = 0;
    cin >> N;
    int num[10];
    int temp = N;
    int i = 0;
    while(temp){
        num[i] = temp % 10;
        temp /= 10;
        i++;
    }
    
    for(int k = 0 ; k < i ; k++){

        if(num[k] == 7){
            ind += (1 << k);
        }
        ind += (1 << k);
    }

    cout << ind;
}