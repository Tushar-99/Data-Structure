#include<iostream>

using namespace std;

int fact(int n)
{
    if(n==0)
    {
        return 1;
    }
    return fact(n-1)*n;
}

int nCr(int n,int r)
{
    int num=fact(n);
    int den=fact(r)*fact(n-r);

    return num/den;
}

int C(int n,int r)
{
    if(r==0 || n==r)
        return 1;

    else
    {
        return C(n-1,r-1)+C(n-1,r);
    }
}

int main()
{
    // int s=1,t=1,a=1;
    // int n,r;
    // cin>> n >> r;
    // cout << C(n,r)<<endl;
    for(int i = n ; i > r ; i--){

        t = t * i;
        s = s * a;
        a++; 
    }
    cout << t/s<<endl;

    // if(r > n - r)
    //     r = n - r;

    int res = 1;
    int r = 3;
    int n = 10;
    for(int i = 0 ; i < r ; i++){
        res *= (n - i);
        res /= (i + 1);
    }
    cout<<res<<endl;
}