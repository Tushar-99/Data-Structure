#include<bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){

        int n , pos , deno , jump = 0;
        cin >> n;

        //while(n > 0){

            jump = __builtin_popcount(n);
            // pos = log2(n & -n) + 1;
            // deno = 1 << pos;
            // // n /= deno;
            // n -= deno;
            // jump++;
        //}

        cout << jump << endl;
    }
}