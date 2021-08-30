#include<iostream>

using namespace std;

//2D DP

int gridP(int m, int n)
{
    int **gridPaths = new int*[m];

    for(int  i = 0 ; i < m ; i++)
        gridPaths[i] = new int[n];

    //int gridPaths[m][n] = {0};

    for(int i = 0 ; i < m ; i++){
        gridPaths[i][0] = 1;
    }

    for(int i = 0 ; i < m ; i++){
        gridPaths[0][i] = 1;
    }

    for(int i = 1 ; i < m ; i++){
        for(int j = 1 ; j < n ; j++){
            cout<<"("<<i<<","<<j<<")"<<endl;
            gridPaths[i][j] = gridPaths[i-1][j] + gridPaths[i][j-1];
        }
    }

    return gridPaths[m-1][n-1];
}

int recGrid(int m,int n){

    if(m == 3 || n == 3){
        return 1;
    }
    cout<<"("<<m<<","<<n<<")"<<endl;    
    return recGrid(m,n+1) + recGrid(m+1,n);
}

//1D DP
int gridPaths(int m , int n){

    int dp[n] = {1};
    // index -> value
    // 0 -> 1 , 1 -> 0 , 1 -> 0 , 1 -> 0 , ......... , (n-1)th index -> 0 
    // for(int i = 0 ; i < n ; i++)
    //     cout<<dp[i]<<endl;

    for(int i = 0 ; i < m ; i++){
        for(int j = 1 ; j < n ; j++){
            //cout<<dp[j]<<endl;
            dp[j] += dp[j-1];
        }
    }
    return dp[n-1];
}

int main()
{
    // cout << gridP(4,4);
    cout << gridPaths(4,2);
    //Note by doing this only first element is initialized with given value and rest are zero
    // int arr[5] = {1};
    
    // for(int i = 0 ; i < 5 ; i++)
    //     cout<<arr[i]<<" ";
    return 0;
}