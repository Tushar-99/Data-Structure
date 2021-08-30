#include<iostream>

using namespace std;


int main(){
    int x,i=1,n=0,j=1,l=0;
    cout<<"Enter range:";
    cin>>x;
    while(i<=x)
    {
        while(j<=i)
        {   
            if(i%j == 0)
            {
                n++;
            }
            if(n == 9)
             {
                l++;
            }
            j++;
        }
        i++;
    }
    cout<<l<<endl;
    return 0; 
}