#include<iostream>

using namespace std;

int fact(int d){
    if(d==0 || d==1)
    {
        return 1;
    }
    else
    {
        return fact(d-1)*d;
    }
    
}

int factl(int d)
{
    // int x=d-1;
    // while(x>0)
    // {
    //     d=d*x;
    //     x--;
    // }
    // return d;

    int i,x=1;
    for(i=1;i<=d;i++)
    {
        x=x*i;
    }
    return x; 
}

int main()
{
    int n;
    cin >> n;
    cout << factl(n);
    return 0;
}