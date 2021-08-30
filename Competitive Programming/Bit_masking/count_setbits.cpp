#include<bits/stdc++.h>

using namespace std;

int main(){

    int N , x = 0 , ans = 0;
    cin >> N;

    // 1 << -n --> 0 for any value of n >= 0
    // while((1 << x) < N)
    //     x++;

    while(N > 0){
        x = 1;
        while((1 << x) <= N)
            x++;
        
        x -= 1;
        
        ans += x * (1 << (x - 1)) + (N - (1 << x) + 1);
        N -= (1 << x);
    }
    
    cout << ans;
}