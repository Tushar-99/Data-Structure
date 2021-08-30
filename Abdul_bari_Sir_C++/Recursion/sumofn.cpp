#include<iostream>

using namespace std;

int sum(int x)
{
    if(x == 0){
        return 0;
    }
    else
    {
       return sum(x-1)+x; 
    }
    
}

void lsum(int u)
{
    int i=u-1;
    while(i>0)
    {
        u=u+i;
        i--;
    }
    cout << u;
} 

int dsum(int n)
{
    return (n*(n+1))/2; 
}

int suml(int n)
{
    int i,s=0;
    for(i=1;i<=n;i++)
    {
        s=s+i;
    }
    return s;
}

int main()
{
    int n;
    cin >> n;
    cout << dsum(n);
    return 0;
}