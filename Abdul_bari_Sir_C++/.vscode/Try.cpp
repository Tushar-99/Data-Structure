#include<iostream>
using namespace std;

// int nCr(int a,int b)
// {
// 	int i,t=1,s=1,l=1,r;
// 	for(int i=a;i>b;i--)
//     {
//         t=t*i;
//         s=s*l;
//     	l++; 
//     }
// 	r=(t/s)+(t/s)+1;

//     return r;
// }
int main()
{
	int i,n,x;
	cin >> n;
	for(i=0;i<n;i++)
	{
		cin >> x;
        if(x>2)
        {
            cout<< x*(x-1)+1<<endl;
        }
        // {
		// cout<<nCr(x,x/2)<<endl;
        // }
        else
        {
            continue;
        }
        
	}
}