#include<bits/stdc++.h>

using namespace std;

void multiply(int *a , int &n , int no){
    
    int carry = 0;
    for(int i = 0 ; i < n ; i++){
        int product = a[i] * no + carry;
        a[i] = product % 10;
        carry = product / 10;
    }
    // here n indicates upto what length the array is filled
    while(carry){
        a[n] = carry % 10;
        carry /= 10;
        n++; 
    }
}

void big_factorial(int num){

    int *a = new int[1000];
    for(int i = 0 ; i < 1000 ; i++){
        a[i] = 0;
    }

    a[0] = 1;
    int n = 1;

    for(int i = 2 ; i <= num; i++){
        multiply(a , n , i);
    }

    for(int i = n - 1 ; i >= 0 ; i--){
        cout << a[i] << " ";
    }
}

int main(){

    int n;
    cin >> n;

    big_factorial(n);

    // int len = 1 , q = 2 , fac[100000] = {0} , i , carry , n , product;
    // cin >> n;
    // fac[0] = 1;
    // while(q <= n){

    //     i = 0;
    //     carry = 0;
    //     while(i < len){
    //         product = fac[i] * q + carry;
    //         fac[i] = product % 10;
    //         carry = product / 10;
    //         i++;
    //     }
    //     while(carry){
    //         fac[len] = carry % 10;
    //         carry /= 10;
    //         len++;
    //     }
    //     q++;
    // }
    
    // for(i = len - 1 ; i >= 0 ; i--)
    //     cout << fac[i];
}