#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int i,j,n,l=1;
    cout<<"Enter a no.:";
    cin>>n;
    for(i=1;i<=n;i++)
    {	
        for(j=1;j<=i;j++)
        {
            if(l>n)
        		break;
        	cout<<i;
        	l++;
		} 	 
     }
    return 0;
}
