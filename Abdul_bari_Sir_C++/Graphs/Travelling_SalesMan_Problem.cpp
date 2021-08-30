#include<bits/stdc++.h>

using namespace std;

int v = 4;

int dp[16][4];
int dist [10][10] ={
        {0 , 20 , 42 , 25},
        {20 , 0 , 30 , 34},
        {42 , 30 , 0 , 10},
        {25 , 34 , 10 , 0}
};
int VISITED_ALL = (1 << v) - 1;

int tsp(int mask , int pos ,int dp[16][4])
{
    if(mask == VISITED_ALL)
        return dist[pos][0];

    if(dp[mask][pos] != -1)
        return dp[mask][pos];

    int ans = INT_MAX;
    for(int city = 0 ; city < v ; city++)
    {
        if((mask & (1 << city)) == 0)
        {
            int newAns = dist[pos][city] + tsp(mask | (1 << city) , city , dp);
            ans = min(ans , newAns);
        }
    }
    return dp[mask][pos] = ans;
}
int main()
{
    for(int i = 0 ; i < 16 ; i++)
        for(int j = 0 ; j < 4 ; j++)
            dp[i][j] = -1;
    
    cout << tsp(1 , 0 , dp) << endl;

    for(int i = 0 ; i < 16 ; i++)
    {
        for(int j = 0 ; j < 4 ; j++)
            cout << dp[i][j] << " ";
        
        cout << endl;
    }
}