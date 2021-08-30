#include<iostream>

using namespace std;

double e1(int x,int n)
{
    double s=1;
    int i;
    double num=1,den=1;
    for(i=1;i<=n;i++)
    {   
        num*=x;
        den*=i;
        s=s+num/den;
    }
    return s;
}

double e(int x,int n)
{   
    static double p=1,f=1;
    double r;
    if(n==0)
        return 1;
    else    
    {   
        r=e(x,n-1);
        p*=x;
        f*=n;
    }
    return r+(p/f);
}

double ei(int x,int n)
{
    double s=1;
    for(;n>0;n--)
    {
        s=1+x*s/n;
    }
    return s;
}

double ei1(int x,int n)
{
    static int s=1;
    if(n==0)
        return s;
    
    s=1+x*s/n;

    return e(x,n-1);
}
int main()
{   
    int x,y;
    cin>>x>>y;
    cout<<ei1(x,y);
    // int sin()
    // int cos()
    // int tan()
    // int sini()
    // int cosi()
    // int tani()
    // int sec()
    return 0;
}