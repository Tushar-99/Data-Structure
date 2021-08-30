#include <iostream> 
#include<bits/stdc++.h> 
using namespace std; 

int main(){
    int i=2,n,c=0;
    cin>>n;

    while(n % i == 0){
        n/=i;
        c++;
        if(n % i == 1)
            cout<<i<<"^"<<c<<" ";
    }
    for(i = 3 ; i <= sqrt(n) ; i+=2){
        if(n % i == 0){//important logic
            c=0;
            while(n % i == 0){
                n=n/i;
                c++;
            }
            cout<<i<<"^"<<c<<" ";
        }        
    }
    if(n!=1){
       cout<<n<<"^"<<"1"<<" "; 
    }
}

