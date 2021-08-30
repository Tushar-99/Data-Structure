//DP ki pehchan niche aate hue solve ho rahi hogi aur same problem baar baar solve ho rahi hogi
#include<bits/stdc++.h>

using namespace std;

//recursive
int fib(int n)
{

    if(n == 1 || n == 2)
        return n-1;

    return fib(n-1) + fib(n-2);   
}

//top-down --> recursion + memoization
int fibm(int n ,int *dp){

    if(dp[n] != -1)
        return dp[n];
    
    cout << "Hello" << n << endl;
    dp[n] = fibm(n-1 , dp) + fibm(n-2 , dp);

    return dp[n];
}

//Bottom-up mae recursion nahi use karte khali loop se kaam chal jaat hai;

int fibl(int n){

    int arr[2] = {0,1};
    int res = 0;

    for(int i = 1 ; i < n-1 ; i++) {
        res = arr[0] + arr[1];
        arr[0] = arr[1];
        arr[1] = res;
    }

    return arr[1];
}

int main(){

    int n = 10;
    int dp[n+1];
    // dp[0] = INT32_MIN;
    //cout << fib(1);
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;

    // for(int i = 3 ; i < n+1 ; i++)
    //     dp[i] = -1;
    
    // cout << fibm(n , dp);

    cout << fibl(n);
}