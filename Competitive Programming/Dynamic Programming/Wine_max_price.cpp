// 2-D  D.P.
#include <bits/stdc++.h>

using namespace std;
 
//here is concern about 2-D DP so aware of such kind of problems
// Why 2-D DP?
// Because we have two paths to cover the array i.e. start or end so at every point on e value related to two points in table i.e. start and end point which we need to store in table
int w_maxTD(int count , int price[] , int start , int end , int dp[][100]){

    if(start > end)
        return 0;

    if(dp[start][end] != 0)
        return dp[start][end];
    // here count++ have issue so use count + 1
    dp[start][end] = max(price[end] * count + w_maxTD(count + 1 , price , start , end - 1 , dp) , price[start] * count + w_maxTD(count + 1 , price ,  start + 1 , end , dp));

    return dp[start][end];
} 

int w_maxBU(int price[] , int len){

    int dp[len][len] = {0};

    //Consider any bottle can sold at last year i.e. nth year which is the size of the array so take a for loop which traverse through all diagonal

    for (int i = 0; i < len; i++){
        dp[i][i] = price[i] * len;
    }
    
    int year = len;
    --year;

    for (int i = 2; i <= len; i++){
        int srt = 0;
        int end = len - i;

        while (srt <= end){
            int endwindow = srt + i - 1;
            dp[srt][endwindow] = max(price[srt] * year + dp[srt + 1][endwindow] , price[endwindow] * year + dp[srt][endwindow - 1]);
            ++srt; 
        }
        --year;
    }
    
    // Code is not wrong but dont fit logically
    // for(int k = 0 ; k < len ; k++){
    //     for (int i = 0; i < len - k; i++){
    //         int ans = 0 , temp = 0; 
    //         for (int j = k; j < len && i <= j; j++){
    //             // if(i <= j){
    //                 int ans = 0 , temp = 0;
    //                 ans = (price[j] * len - (j - i)); 
    //                 if (i + 1 < len && j > 0){
    //                     temp = max(dp[i + 1][j] , dp[i][j - 1]);
    //                 }
    //                 dp[i][j] = ans + temp;
    //             //}
    //         }
    //     }
    // }

    // // for (int i = 0; i < len ; i++){
    // //     int ans = 0 , temp = 0; 
    // //     for (int j = i ; j < len ; j++){
    // //             if(i <= j){
    // //                 ans = (price[j] * len - (j - i)); 
    // //             if (i + 1 < len && j > 0){
    // //                 temp = max(dp[j][i + 1] , dp[j - 1][i]);
    // //             }
    // //         }
    // //         dp[i][j] = ans + temp;
    // //     }
    // // }

    for (int i = 0; i < len; i++){
        for (int j = 0; j < len; j++){
            cout << setw(3) <<dp[i][j] << " ";
        }
        cout << endl;
    }
    
    return dp[0][len - 1];
}

int main(){

    int price[5] = {2 , 3 , 5 , 1 , 4};
    //here greedy gives 49 so don't use greedy but in DP = 50
    int len = sizeof(price) / sizeof(int);
    int dp[100][100] = {0};
    // cout << w_maxTD(1 , price , 0 , len - 1 , dp);
    cout << w_maxBU(price , len);
}