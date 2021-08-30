#include<iostream>

using namespace std;

void fun(int n)
{
    if(n>0)
    {
        printf("%d",n);
        fun(n-1);
        printf("%d",n);
        fun(n-1);
        printf("%d",n);
        fun(n-1);
        printf("%d",n);
    }
}
int main()
{
    int x;
    cout<< "Enter a no.";
    cin >> x;
    fun(x);
    return 0;
}