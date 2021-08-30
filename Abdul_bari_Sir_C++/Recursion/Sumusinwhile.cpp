#include<iostream>

using namespace std;

int main()
{
    int x,n;
    cout<<"Enter a no.";
    cin>>x;
    n=x-1;
    while(n>0)
    {
        x=x+n;
        n--;
    }
    cout<<x;
}