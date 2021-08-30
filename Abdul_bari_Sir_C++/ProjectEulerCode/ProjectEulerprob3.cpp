// #include<iostream>

// using namespace std;
// #define ll long long

// int prime(ll l)
// {

//     for(ll i=0;i<=l/2;i++)
//     {
//         if(l%i==0)
//         {
//             return 1;
//         }
//     }
//     return 0;
// }


// bool isPrime(int n) 
// { 
//     // Corner case 
//     if (n <= 1) 
//         return false; 
  
//     // Check from 2 to n-1 
//     for (int i = 2; i*i < n; i++) 
//         if (n % i == 0) 
//             return false; 
  
//     return true; 
// } 
  
// // // Driver Program 
// int main() 
// { 
//     isPrime(11) ? cout << " true\n" :  
//                   cout << " false\n"; 
//     return 0; 
// } 

// int main()
// {
//     ll x,y,i,s;
//     // s=600851475143;
//     // i=(s+1)/6;
//     // cout<<i;
//     for(i=2;i<600851475143;i+2)
//     {
//         if(isPrime(i)==true && 600851475143%i == 0)
//         {
//             s=i;
//         }
//     }
//     cout<<s<<endl;
// }


//==============================================================
//Correct one
#include<bits/stdc++.h> 
using namespace std; 
  
// A function to find largest prime factor 
long long maxPrimeFactors(long long n) 
{ 
    // Initialize the maximum prime factor 
    // variable with the lowest one 
    long long maxPrime = -1; 
  
    // Print the number of 2s that divide n 
    while (n % 2 == 0) { 
        cout<<2<<"|";
        n >>= 1; // equivalent to n /= 2 
        maxPrime = 2; 
        cout<<n<<endl;
        cout<<"-----------------"<<endl;
    } 
  
    // n must be odd at this point, thus skip 
    // the even numbers and iterate only for 
    // odd integers 
    // long long y = n;
    
    cout<< n <<endl;
    
    for (int i = 3; i*i <= n; i += 2) { 
       
        while (n % i == 0) {
            cout<<i<<"|";
            cout << n << endl;
            cout<<"-----------------"<<endl;
            maxPrime = i; 
            n = n / i;
            // cout<<sqrt(y)<<endl;
        }
        //maxPrime = n;
    } 
  
    // This condition is to handle the case 
    // when n is a prime number greater than 2 
    if (n > 2) 
       maxPrime = n; 
  
    return maxPrime; 
} 
  
// Driver program to test above function 
int main() 
{ 
    long long n = 8; 
    cout << maxPrimeFactors(n) << endl; 
  
    n = 600851475143; 
    cout <<  maxPrimeFactors(n)<<endl;

    cout <<  maxPrimeFactors(256); 
  
}