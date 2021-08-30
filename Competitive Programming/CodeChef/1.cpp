#include<bits/stdc++.h>

using namespace std;

int main()
{
    // int N , M , K , count = 0 , sum;

    // cin >> N >> M >> K;

    // int mat[N][N + 1];

    // for(int i = 0 ; i < N ; i++)
    // {
    //     for(int j = 0 ; j <= N ; j++)
    //     {
    //         cin >> mat[i][j];
    //     }
    // }

    // for(int i = 0 ; i < N ; i++)
    // {
    //     sum = 0;
    //     if(mat[i][N] <= 10)
    //     {
    //         for(int j = 0 ; j < N ; j++)
    //         {
    //             sum += mat[i][j];
    //         }

    //         if(sum >= M)
    //             count++;
    //     }
    // }
    // cout << count;

    //cout << ((100001 & 100001) == 100001) << endl;
    string str;
    getline(cin , str);
    int  i = 0;
    while(str.at(i) != '\0')
        cout << str.at(i++);
}
