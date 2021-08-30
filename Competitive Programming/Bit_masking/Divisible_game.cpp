#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main(){

    int t;
    cin >> t;

    vector<int> prime;

    for(int i = 2 ; i < 20 ; i++){
        int j;
        bool rt = true;
        for(j = 2 ; j * j <= i ; j++){
            
            if(i % j == 0)
                rt = false;
        }
        if(rt)
            prime.push_back(i);
    }

    // for(auto x : prime)
    //     cout << x << " ";

    // cout << prime.size();

    while(t--){
        lli n , res , ans = 0 , temp , j , count;
        cin >> n;
        
        for(int i = 1 ; i < (1 << prime.size()) ; i++){
            temp = i;
            j = 0;
            count = 0;
            res = n;
            while(temp > 0){
                if(temp & 1){
                    res /= prime[j];
                    count++;
                }
                j++;
                temp >>= 1;
            }
            if(count & 1)
                ans += res;

            else
                ans -= res;
        }

        cout << ans << endl;
    }
}