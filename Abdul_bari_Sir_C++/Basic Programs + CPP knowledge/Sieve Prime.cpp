#include<iostream>
using namespace std;

#define ll long long

void primeSieve(int *p)
{
    for(int i=3;i<=10000000;i+=2)
    {
        p[i]=1;
    }
    for(ll i=3; i<=10000000; i += 2){
        if(p[i]==1)
        {
        for(ll j=i*i; j<=10000000; j += i)
        {
            p[i]=0;
        }
    }
}
    p[2]=1;
    p[0]=p[1]=0;    
}

int main()
{
    int n;
    cin>>n;
    int p[10000000]={0};

    primeSieve(p);

    for(int i=0;i<=n;i++)
    {   
        if(p[i]==1)
        {
        cout<< i <<" ";
        }
    }
}
 
