#include<bits/stdc++.h>

using namespace std;

int main(){
    //Array of fixed space treated as O(1) space
    int n , no , cnt[64] = {0} , j , arr[64] , p = 1 , res = 0;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> no;

        j = 0;
        while(no > 0){

            int last_bit = (no & 1);
            cnt[j] += last_bit;
            j++;
            no >>= 1;
        }
    }

    for(int i = 0 ; i < 64 ; i++){
        cnt[i] %= 3;
        res += (cnt[i] * p);
        p *= 2;
    }
    // for(int i = 0 ; i < 64 ; i++){
    //     res += cnt[i] * p;
    //     p *= 2;
    // }

    cout << res;
}