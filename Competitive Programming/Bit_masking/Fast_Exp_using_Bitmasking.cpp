#include<bits/stdc++.h>

using namespace std;

int main(){

    int a , n , ans = 1;
    cin >> a >> n;

    while(n > 0){

        if(n & 1 == 1)
            ans *= a;
        
        // if at that position bit is 1 then ans multiplies by that no (a) which is growing exponentially
    // bit 1 2 3 4 i.e. 2^n but in binary format
        // 2 4 16 32 ......
        a *= a;
        n >>= 1;
    }
    cout << ans;
}