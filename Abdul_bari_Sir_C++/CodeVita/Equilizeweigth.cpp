#include<bits/stdc++.h>

using namespace std;

void printDistSum(vector<int> v, int n) 
{ 
    int sum = 0; 
    for (int i=0; i<n; i++) 
        sum += v[i]; 
  
    // dp[i][j] would be true if arr[0..i-1] has 
    // a subset with sum equal to j. 
    bool dp[n+1][sum+1]; 
    memset(dp, 0, sizeof(dp)); 
  
    // There is always a subset with 0 sum 
    for (int i=0; i<=n; i++) 
        dp[i][0] = true; 
  
    // Fill dp[][] in bottom up manner 
    for (int i=1; i<=n; i++) 
    { 
        dp[i][v[i-1]] = true; 
        for (int j=1; j<=sum; j++) 
        { 
            // Sums that were achievable 
            // without current array element 
            if (dp[i-1][j] == true) 
            { 
                dp[i][j] = true; 
                dp[i][j + v[i-1]] = true; 
            } 
        } 
    } 
  
    // Print last row elements 
    for (int j=0; j<=sum; j++) 
        if (dp[n][j]==true) 
            cout << j << " "; 
} 
  

int main(){

    int bags_no,bag_in ,i , j ,sum = 0 , temp;
    cin>>bags_no;
    vector<int> weight;
    vector<int> dummy;
    for(i = 0 ; i < bags_no ; i++){
        cin>>bag_in;
        for(int i = 0 ; i < bag_in ; i++){
            weight.push_back(i);
        }
    }
    int size = weight.size();
    sort(weight.begin(),weight.end());
    for(i = 0 ; i < size ; i++){
        sum += weight[i];
    }
    int div = sum/bags_no;
    for(i = 0 ; i < size ; i++){
        for(j = 1 ; j < size ; j++){
            if(div > weight[i]+weight[j]){
                dummy.push_back(i);
                dummy.push_back(j);
            }
        }
    }
    printDistSum(weight,20);
}