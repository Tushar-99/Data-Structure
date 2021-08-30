#include<bits/stdc++.h>

using namespace std;

int main(){

    int fac , n = 5 , ans = 0;
    cin >> fac;

    while(fac / n){
        ans += fac / n;
        n *= 5;
    }
    cout << ans;
}