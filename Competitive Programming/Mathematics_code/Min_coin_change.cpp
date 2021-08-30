#include <iostream>

using namespace std;

int min_ch_TD(int n , int dp[] , int coins_d[] , int len){
    
    if(n <= 0)
        return 0;

    if(dp[n] != 0)
        return dp[n];

    int ans = INT32_MAX;
    for (int i = 0; i < len; i++){
        if(n - coins_d[i] >= 0){
            int subprob = min_ch_TD(n - coins_d[i] , dp , coins_d , len) + 1;
            // cout << subprob << " ";
            ans = min(ans , subprob);
        }
    }
    dp[n] = ans;
    // cout << dp[n] << " " << endl;
    return dp[n];
}

// Space Complexity -> O(N) , Time Complexity -> O(TN) here N is number which  is needed to be form and T is no of different denomination of coins
int min_ch_BU(int n , int coin_d[] , int len){

    int ans;
    int dp[100] = {0};
    dp[0] = 0;
    for (int i = 1; i <= n; i++){
        ans = INT32_MAX;
        dp[i] = INT32_MAX;
        for (int j = 0; j < len; j++){
            
            if(i - coin_d[j] >= 0){
                int idx = i - coin_d[j];
                dp[i] = min(dp[i] , dp[idx] + 1);
            }
        }
        // dp[i] = ans;
    }
    return dp[n];
}

int main(){

    int n , dp[100] = {0} , coins_d[3] = {1 , 7 , 10} , len = 3;
    dp[0] = 0;
    cin >> n;
    // cout << min_ch_TD(n , dp , coins_d , len);
    cout << min_ch_BU(n , coins_d , len);
}