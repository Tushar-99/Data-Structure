#include<iostream>
using namespace std;
void fun(int n)
{
    if(n>0)
    {
    cout << n <<endl;
    fun(n-1);
    }
}
int main()
{   
    int x;
    cout <<"Enter a no.";
    cin >>x;
    fun(x);
    return 0;
}