#include<iostream>

using namespace std;

int main()
{
    int i,x,s=0;
    cin >>x;
    for(i=1;i<x;i++)
    {
    if(x%3 == 0 || x%5 == 0)
    {
        s=s+x;
    }
    }
    cout<<s;
}