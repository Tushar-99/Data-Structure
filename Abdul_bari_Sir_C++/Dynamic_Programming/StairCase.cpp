// In divide and conquor approach we divide the problems into smaller problem such that it is non overlapping(i.e. all the problems are independent) like merge sort and Quick Sort

// IN Dynamic Programming the problems is divided into smaller problems such that it can be if overlapped then that result is stored into memory

//in greedy we already know the path trace for the subproblems so no need to go through the similar problems.

//in DP we have multiple paths to go to the solution to find the maximum or minimum no of value of the greedy in the given problem but in case problem we have one appraoch to go through the problem 

//There is error in thprintpath and pathways only because of not picking of correct index at dp array so not proper taking of correct value

#include<bits/stdc++.h>

typedef long double ld;

using namespace std;

int printPath(int,string);

int anyprintPath(int , int* , string);

int tdprintPath(int , int* ,string ,int*);

int buprintpath(int , int*);

int opPath(int , int);

ld op_Path(int , int);

int opPathPro(int , int , int *);

// similar to fibonacci with some changes
// top-down DP
// there is error in this code

int pathWays(int n , int *A , int size , int *dp)
{
    if(n < 0)
        return 0;
    
    if(dp[n] != -1)
        return dp[n];

    int ans = 0;
    //int res = pathWays(strno-1) + pathWays(strno-2) + pathWays(strno-3);
    for(int i = 0 ; i < size ; i++){
        if(n - A[i] >= 0){
            ans += pathWays(n - A[i] , A , size , dp);
            //Mistake because of not picking of correct value of n
            dp[n] = ans;
        }
    }
    return dp[n];    
}

int recStair(int n){

    if(n == 0 || n == 1)
        return 1;

    if(n < 0)
        return 0;

    cout << "Hello" << n << endl; 
    //recusive trace --> ternary tree
    int res = recStair(n-1) + recStair(n-2) + recStair(n-3);

    return res;
}

int stairMem(int n,int *dp){

    int ans = 0;

    if(dp[n] != -1)
        return dp[n];

    cout << "Hello " << n << endl;

    for(int i = 1 ; i <= 3 ; i++)
    {
        if(n - i >= 0)
        {
            ans += stairMem(n - i , dp);
            //dp[n] value is -1 when not any operation is performed
            dp[n] = ans;
        }
    }
    
    return dp[n];
}

int main(){

    int n = 18;
    int dp[n+1];                                                            
    dp[0] = 1;

    for(int i = 1 ; i <= n ; i++)
        dp[i] = -1;

    int A[3] = {1 , 2 , 3};
        
    // cout << pathWays(n , A , 3 , dp)<<endl;
    // for(int i = 0 ; i <= n ; i++)
    //    cout << dp[i] << " ";
    // cout << recStair(n);
    // cout << stairMem(n,dp);
    // for(int x: dp){
    //     cout<< x << " ";
    // }
    // cout << printPath(4,"");

    // cout << anyprintPath(18 , A , "");
    // cout << tdprintPath(n , A , "" , dp);
    cout << buprintpath(n , A);
    // cout << endl;

    // for(int x: dp)
    //     cout<< x << " ";
    // cout << op_Path(120 , 3);
    // cout << endl;
    // cout << opPathPro(n , 3 , A);
}

// print all the paths for only 1,2,3 jump
int printPath(int n,string path)
{
    if(n == 0){
        cout << path << endl;
        return 1;
    }

    if(n < 0)
        return 0;
    
    int ans = printPath(n-1,path +"1") + printPath(n-2,path +"2") + printPath(n-3,path +"3");

    return ans;
}

//print all path for array digit jumps
int anyprintPath(int n , int *A , string path)
{
    if(n < 0)
        return 0;
    
    if(n == 0)
    {
        cout << path << endl;    
        return 1;
    }

    // to_string --> it is used convert any primitive data type into string
    // stoi --> it is used to convert string into integer

    int ans = 0;
    for(int i = 0 ; i < 3; i++)
        ans += anyprintPath(n - A[i] , A , path + " " +to_string(A[i]));

    return ans;
}

// top-down DP

int tdprintPath(int n , int *A , string path , int *dp)
{
    if(dp[n] != -1)
    {
        cout << path << endl;
        return dp[n];
    }

    int ans = 0;
    for(int i = 0 ; i < 3 ; i++){
        if(n - A[i] >= 0){
            // ans varaible stack memory mae result maintain karke rakhega
            ans += tdprintPath(n - A[i] , A , path + to_string(A[i]) , dp);
            dp[n] = ans; // during returning n-i == n
        }
    }
    return dp[n];
}

// Bottom-UP DP

int buprintpath(int n , int *A)
{
    int ans = 0;
    int stair[n+1];
    stair[0] = 1;

    for(int i = 1 ; i <= n ; i++)
    {
        stair[i] = 0;
        for(int j = 0 ; j < 3 ; j++)
        {
            if(i - A[j] >= 0)
                stair[i] += stair[i - A[j]];
        }
    }

    for(int i = 0 ; i <= n ; i++)
        cout << stair[i] << " " ;
    
    cout << endl;
    return stair[n];
}

// more optimized one Time --> O(n)
// how to come to these kind of approach recursive practices without ending condition

int opPath(int n , int m)
{
    int res[n+1];
    res[0] = 1;
    int temp = 0;
    
    for(int i = 1 ; i <= n ; i++)
    {
        int s = i - m - 1;
        
        if(s >= 0)
            temp -= res[s];

        temp += res[i - 1];
        res[i] = temp;
    }
    return res[n];
}

ld op_Path(int n , int m)
{
    ld first = 1 , second = 1 , third = 2 , res = 0;

    for(int i = 3 ; i <= n ; i++)
    {
        res = first + second + third;
        first = second;
        second = third;
        third = res;
    }

    return third;
}

//Wrong thinking
int opPathPro(int n , int m , int *A)
{
    int s;
    int res[n+1];
    res[0] = 1;
    res[1] = 0;
    int temp = 0;
    // 1 0 1 0 1 1 1 2 1 3 3 4 6 5 10 9 15 17 21
    // 21
    for(int i = 2 ; i <= n ; i++)
    {
        s = i - A[m - 1] - 2;
            
        if(s >= 0)
            temp -= res[s];

        temp += res[i - 2];
        res[i] = temp;

    }

    for(int i = 0 ; i <= n ; i++)
        cout << res[i] << " " ;

    return res[n];
}
