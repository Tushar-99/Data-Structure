#include<iostream>

using namespace std;
#define li long int
int main()
{
    int i,n,y=0,t0=1,t1=2,s=2;
    cin >> n;
    if(n==1 || n==2)
    {
        cout<<n;
    }
    else{
    for(i=3;i<=n;i++)
    {
        y=t0+t1;
        t0=t1;
        t1=y;

        if(y%2==0)
        {
            s=s+y;
        }
        if(s>4000000)
        {
            cout<<i+2<<endl;
            break;
        }
    }
    }
    cout << s;
}