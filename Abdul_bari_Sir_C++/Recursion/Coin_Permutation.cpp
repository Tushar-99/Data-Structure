#include<bits/stdc++.h>

using namespace std;

void coins(int n , string s)
{
    if(n == 0)
    {
        cout << s << " ";
        return;
    }

    coins(n - 1 , s + "H");
    coins(n - 1 , s + "T");
}

int main()
{
    coins(3 , "");
}