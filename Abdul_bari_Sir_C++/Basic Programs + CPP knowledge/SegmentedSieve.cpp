//From Coding Ninjas
//works on only 10^5 to 10^6
#include<bits/stdc++.h>

using namespace std;
#define MAX 1000000 //we can maximum array of 1 million size only
vector<int>* sieve(){

    bool isPrime[MAX];
    for(int i = 0 ; i < MAX ; i++){//here last no is excluded
        isPrime[i]=true;
    }
    for(int i = 2 ; i*i < MAX ; i++){
            if(isPrime[i]){
                for(int j = i*i ; j < MAX ; j += i){//here also last no is excluded
                    isPrime[j]=false;
                }
            }
    }
    vector<int>* primes = new vector<int>();
    primes->push_back(2);
    for(int i = 3 ; i < MAX ; i +=2){
        if(isPrime[i])
            primes->push_back(i);
    }
    return primes;
}

void printPrimes(long long l,long long r,vector<int>* & primes){
    bool isPrime[r-l+1];//{1000000-----------1000000000000}--size 10^6indexes 0----10^6

    for(int i = 0;i<=r-l;i++){
        isPrime[i]=true;
    }
    for(int i=0;primes->at(i)*primes->at(i)<=r;i++){
        int curPrime = primes->at(i);
        long long base = (l/(curPrime))*(curPrime);
        if(base <l){
            base = base + curPrime;
        }
        for(long long j = base ; j<=r ;j+= curPrime){
            isPrime[j-l] = false;
        }
        if(base == curPrime){
            isPrime[base-l] = true;
        }
    }
    for(int i=0;i<=r-l;i++){
         if(isPrime[i]){
            cout<<i+l<<" ";
        }
    }    
}
int main(){
    vector<int>* primes = sieve();
    int t;
    cin>>t;
    while (t--)
    {
        long long l,r;
        cin>>l>>r;
        printPrimes(l,r,primes);
    }
}

//===================================================
//work on any range but must be multiple of 10 like 10^8 to 10^9
//From GeeksforGeeks
// C++ program to print print all primes smaller than 
// n using segmented sieve 
#include <bits/stdc++.h> 
using namespace std; 
  
// This functions finds all primes smaller than 'limit' 
// using simple sieve of eratosthenes. It also stores 
// found primes in vector prime[] 
void simpleSieve(int limit, vector<int> &prime) 
{ 
    // Create a boolean array "mark[0..n-1]" and initialize 
    // all entries of it as true. A value in mark[p] will 
    // finally be false if 'p' is Not a prime, else true. 
    bool mark[limit+1]; 
    memset(mark, true, sizeof(mark)); 
  
    for (int p=2; p*p<limit; p++) 
    { 
        // If p is not changed, then it is a prime 
        if (mark[p] == true) 
        { 
            // Update all multiples of p 
            for (int i=p*2; i<limit; i+=p) 
                mark[i] = false; 
        } 
    } 
  
    // Print all prime numbers and store them in prime 
    for (int p=2; p<limit; p++) 
    { 
        if (mark[p] == true) 
        { 
            prime.push_back(p); 
            cout << p << " "; 
        } 
    } 
} 
  
// Prints all prime numbers smaller than 'n' 
void segmentedSieve(int n) 
{ 
    // Compute all primes smaller than or equal 
    // to square root of n using simple sieve 
    int limit = floor(sqrt(n))+1; 
    vector<int> prime;  
    simpleSieve(limit, prime);  
  
    // Divide the range [0..n-1] in different segments 
    // We have chosen segment size as sqrt(n). 
    int low = limit; 
    int high = 2*limit; 
  
    // While all segments of range [0..n-1] are not processed, 
    // process one segment at a time 
    while (low < n) 
    { 
        if (high >= n)  
           high = n; 
          
        // To mark primes in current range. A value in mark[i] 
        // will finally be false if 'i-low' is Not a prime, 
        // else true. 
        bool mark[limit+1]; 
        memset(mark, true, sizeof(mark)); 
  
        // Use the found primes by simpleSieve() to find 
        // primes in current range 
        for (int i = 0; i < prime.size(); i++) 
        { 
            // Find the minimum number in [low..high] that is 
            // a multiple of prime[i] (divisible by prime[i]) 
            // For example, if low is 31 and prime[i] is 3, 
            // we start with 33. 
            int loLim = floor(low/prime[i]) * prime[i]; 
            if (loLim < low) 
                loLim += prime[i]; 
  
            /* Mark multiples of prime[i] in [low..high]: 
                We are marking j - low for j, i.e. each number 
                in range [low, high] is mapped to [0, high-low] 
                so if range is [50, 100] marking 50 corresponds 
                to marking 0, marking 51 corresponds to 1 and 
                so on. In this way we need to allocate space only 
                for range */
            for (int j=loLim; j<high; j+=prime[i]) 
                mark[j-low] = false; 
        } 
  
        // Numbers which are not marked as false are prime 
        for (int i = low; i<high; i++) 
            if (mark[i - low] == true) 
                cout << i << " "; 
  
        // Update low and high for next segment 
        low = low + limit; 
        high = high + limit; 
    } 
} 
  
// Driver program to test above function 
int main() 
{ 
    int n = 100000000; 
    cout << "Primes smaller than " << n << ":n"; 
    segmentedSieve(n); 
    return 0; 
} 