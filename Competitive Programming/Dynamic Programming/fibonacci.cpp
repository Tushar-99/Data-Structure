#include <iostream>

using namespace std;

int fib(int n){
    if(n == 0 || n == 1)
        return n;
    
    int ans;
    ans = fib(n - 1) + fib(n - 2);
    return ans;
}

int fibTD(int n , int dp[]){

    if(n == 0 or n == 1)
        return n;
    
    if(dp[n] != 0)
        return dp[n];

    int ans;
    dp[n] = fibTD(n - 1 , dp) +fibTD(n - 2 , dp);
    ans = dp[n];
    return ans;
}

long long fibBU(int n){

    long long f_no = 0 , s_no = 1;
    long long ans;

    for (int i = 1; i < n; i++){
        ans = f_no + s_no;
        f_no = s_no;
        s_no = ans;
    }
    
    return ans;
}

int main(){
    int n;
    int *dp = new int[n + 1];
    cin >> n;
    // cout << fib(n);
    cout << fibTD(n , dp);
    // cout << fibBU(n);
}