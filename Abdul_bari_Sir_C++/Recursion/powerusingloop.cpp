#include<iostream>

using namespace std;

int pow (int a,int b)
{
    int r,t;
    if (b==0) return 1;
    if (b==1) return a;
    t=pow(a,b/2);
    r=t*t;
    if(b%2==1) r*=a;
    return r;
    // while(b>0)
    // {
    //     if(b%2==1)
    //     {
    //         r*=a;
    //     }
        
    //     a*=a;
    //     b/=2;
    // }
    return r;
}

int main()
{
    int x,y;
    cin >> x >> y;
    cout << pow(x,y);
    return 0;
}