#include<iostream>

using namespace std;

void rec (int n)
{   
    if(n == 0)
        return ;

    cout<< n<<" ";
    rec(n-1);
    cout<<n<<" ";
}

int main()
{
    int x;
    cout<<"Enter a no.";
    cin>>x;
    rec(x);
    return 0;
}