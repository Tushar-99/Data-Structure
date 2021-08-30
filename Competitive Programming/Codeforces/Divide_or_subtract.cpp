#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t , n , count = 0;
    set<int> fact;
    cin >> t;
    while(t--)
    {
        // cin >> n;
        // int lim = sqrt(n);
        // while(n > 0)
        // {
        //     for(int i = 2 ; i <= lim ; i++)
        //     {
        //         if(n % i == 0)
        //         {
        //             fact.insert(i);
                    
        //             if(n / i != i)
        //                 fact.insert(n / i);
        //         }
        //     }
        // }

        // while(n != 1) 
        // {   
        //     if(n > 1 && n % 2 == 1)
        //     {
        //         n -= 1;
        //         count++;
        //     }
        //     else
        //     {
        //         auto it = fact.rbegin();
        //             n /= *it;
        //     }

        // }

        cin >> n;
        cout << (n <= 3 ? n - 1 : 2 + (n & 1)) << endl;
    }
}