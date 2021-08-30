#include<bits/stdc++.h>

using namespace std;

int main(){

    int n = 365 , i;
    double ans = 1;

    for(i = 364 ; i >= 1 ; i--){
        ans = (ans * i) / n;
    }

    cout << 1 - ans << endl;
    cout << 365 - i;
}