#include<iostream>

using namespace std;

int pow(int n,int m)
{
    if(m == 0)
        return 1;
    else
        return pow(n,m-1)*n;
}

int powi(int m,int n)
{
    if(m == 0)
        return 1;

    if(n%2==0)
    {
        return pow(m*m,n/2);
    }
        
    return m*pow(m*m,(n-1)/2);
}

int pow1(int m,int n)
{
    int i,x=1;
    if(n==0)
        return 1;

    else
    {
        for(i=1;i<=n;i++)
        {
            x=x*m;
        }
    }
    return x;
}

int pow2(int a,int b)
{
    int result = 1;

    while(b > 0){

        if(b % 2 == 1)
            result *= a;

        a *= a;
        b /= 2;
    }
    return result;
}

int pow3(int a,int b)
{
    if(b==0) 
        return 1;
    if(b==1) 
        return a;
    int temp=pow3(a,b/2);
    int result=temp*temp;

    if(b%2==1) 
        result*=a;

    return result;
}

int main()
{
    int x,y;
    cin >> x>> y;
    cout << pow3(x,y);
    return 0;
}