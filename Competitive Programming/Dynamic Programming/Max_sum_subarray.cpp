#include <bits/stdc++.h>

using namespace std;

int max_Sum_D_C(){

    return 0;
}

int max_Sum(int *a , int len){

    int dp[100] = {0};
    dp[0] = a[0] > 0 ? a[0] : 0;
    int max_so_far = dp[0];

    for (int i = 1; i < len; i++){
        dp[i] = dp[i - 1] + a[i];
        if(dp[i] < 0){
            dp[i] = 0;
        }
        max_so_far = max(max_so_far , dp[i]);
    }
    if(max_so_far == 0)
        return *max_element(a , a + len);
    
    return max_so_far;
}

int max_Sum_SO(int *a ,int n){

    int cur_Sum = 0;
    int max_so_far = a[0];

    for (int i = 0; i < n; i++){
        cur_Sum += a[i];
        if(cur_Sum < 0)
            cur_Sum = 0;

        max_so_far = max(cur_Sum , max_so_far);
    }

   if(max_so_far == 0)
        return *max_element(a , a+n);

    return max_so_far;
}

int main(){

    int a[] = {-3 , -2 , -5 , -1 , -6 , -3 ,-2, -7 , -5 , -2};
    int n = sizeof(a) / sizeof(int);

    cout << "Maximum Sum is " << max_Sum(a , n) << endl;
    cout << "Maximum Sum is " << max_Sum_SO(a , n);
}