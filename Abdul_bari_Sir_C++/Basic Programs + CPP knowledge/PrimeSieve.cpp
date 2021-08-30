// #include<iostream>
// using namespace std;

// #define ll long long

// void primeSieve(int* p)
// {
//     for(int i=3;i<=10000000;i+=2){
//         p[i]=1;
//     }
//     for(ll i=3; i<=10000000; i += 2){
//         if(p[i]==1){
//             for(ll j=i*i; j<=10000000; j = j+i){
//                 p[j]=0;
//             }
//         }
//     }
//     p[2]=1;
//     p[0]=p[1]=0;    
// }

// int main()
// {
//     int p[10000000]={0};
//     primeSieve(p);
//     for(int k=2;k<=10000000;k++){   
//         if(p[k]==1)
//         {
//         cout<< k <<" ";
//         }
//     }
//     return 0;
// }
//more efficient than above
#include <bits/stdc++.h> 
using namespace std; 
  

void SieveOfEratosthenes(int n) 
{ 
    // Create a boolean array "prime[0..n]" and initialize 
    // all entries it as true. A value in prime[i] will 
    // finally be false if i is Not a prime, else true. 
    bool prime[n+1]; 
    memset(prime, true, sizeof(prime)); 
    
    for(int i=2;i<=n;i+=2){
        prime[i]=false;
    }
    for (int p=3 ; p*p<=n ; p+=2) 
    { 
        // If prime[p] is not changed, then it is a prime 
        if (prime[p]) 
        { 
            // Update all multiples of p greater than or  
            // equal to the square of it 
            // numbers which are multiple of p and are 
            // less than p^2 are already been marked.  
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
    prime[0]=prime[1]=false;
    prime[2]=true;    
    // Print all prime numbers 
    for (int p=2; p<=n; p++) 
       if (prime[p]) 
          cout << p << " ";
} 
  
// Driver Program to test above function 
int main() 
{ 
    int n = 1000; 
    cout << "Following are the prime numbers smaller "
         << " than or equal to " << n << endl; 
    SieveOfEratosthenes(n);
    //cout<<isPrime(113);
    // int n1;
    // cin>>n1;

    // if(p[n1-1] == 1)
    //     cout<<"Yes"; 
    // else
    //     cout<<"NO";
    return 0; 
} 

// bool isPrime(int n)
// {
//     int x=(n+1)%6;
//     int y=(n-1)%6;
//     if(n>3){
//         if(x == 0){
//             if(y == 0)
//                 return true;
//         }
//     }
//     return false;
// }