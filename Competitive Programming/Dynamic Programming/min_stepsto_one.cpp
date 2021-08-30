#include <iostream>

using namespace std;

int min_stepTD(int n , int dp[]){

    if(n <= 1)
        return 0;

    if(n == 2 || n == 3)
        return 1;

    if(dp[n] != 0)
        return dp[n];

    int div_3 = INT32_MAX , div_2 = INT32_MAX;
    if(n % 3 == 0) 
        div_3 = min_stepTD(n / 3 , dp);

    if(n % 2 == 0) 
        div_2 = min_stepTD(n / 2 , dp);
    
    dp [n] = min(min(div_3 , div_2) , min_stepTD(n - 1 , dp)) + 1;
    return dp[n];
}

int min_stepBU(int n){

    if (n <= 1)
        return 0;

    if(n == 1 || n == 2)
        return 1;

    int dp[100] = {0};
    dp[0] = INT32_MAX;
    dp[1] = INT32_MAX;
    dp[2] = dp[3] = 1;
    int div_3 , div_2 , num_1;

    // Wrong Approach because track of n is not designated
    // while(n > 1){
    //     if(n % 3 == 0){
    //         div_3 = dp[n / 3];
    //         n /= 3;
    //     }
    //     if(n % 2 == 0){
    //         div_2 = dp[n / 2];
    //         n /= 2;
    //     }
        
    //     dp[n] = min(min(div_3 , div_2) , n - 1) + 1;
    // }

    for(int i = 4 ; i <= n ; i++){
        div_3 = 0 , div_2 = 0;
        if(i % 3 == 0){
            div_3 = i / 3;
        }
        if(i % 2 == 0){
            div_2 = i / 2;
        }
        cout << dp[div_3] << " " << dp[div_2] << " " << dp[i - 1] << endl;
        dp[i] = min(min(dp[div_3] , dp[div_2]) , dp[i - 1]) + 1; 
    }
    return dp[n];
}

int main(){
    
    int dp[100] = {0}; // ==> to initialize all indexes with 0
    // for (int i = 0; i < 100; i++)
    //     cout << dp[i];
    
    int n;
    cin >> n;
    // cout << min_stepTD(n , dp); 
    cout << min_stepBU(n);
}