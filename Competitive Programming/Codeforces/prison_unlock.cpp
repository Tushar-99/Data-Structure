#include<bits/stdc++.h>

using namespace std;

#define lli long long int

int main(){

    int t;
    cin >> t;

    while(t--){

        int x , y , ans = 0;
        cin >> x >> y;

        while(x <= y){

            ans += __builtin_popcount(x);
            x++;
        }

        cout << ans << endl;
    }
}