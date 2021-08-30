#include<bits/stdc++.h>

using namespace std;

#define MAX_SIZE 1000005

void SieveOfEratosthenes(vector<int> &primes){

    bool prime[MAX_SIZE];
    memset(prime , true , sizeof(prime));

    for(int i = 4 ; i <= MAX_SIZE ; i += 2){
            prime[i]=false;
    }

    for(int i=3 ; i*i <= MAX_SIZE ; i+=2){
        if(prime[i] == true){
            for(int j = i*i ; j < MAX_SIZE ; j += i)
                prime[j]=false;
        }
    }

    for(int p = 2 ; p < MAX_SIZE ; p++){
        if(prime[p])
            primes.push_back(p);
    }
}

int main(){

    // vector<long long> p(10001,0);
    // vector<bool> prime{true};
    // vector<int> n;

    // //This is Sieve of Eratosthenes
    // for(int i = 4 ; i <= n.max_size() ; i+=2){
    //         prime[i]=false;
    // }

    // for(int i=3 ; i*i <= n.max_size() ; i+=2){
    //     if(prime[i] == true){
    //         for(int j = i*i ; j < n.max_size() ;j += i){
    //             prime[i]=false;
    //         }
    //     }
    // }
    // //Seive of Eratosthenes End
    // for(vector<bool>::iterator i=prime.begin() ; i != prime.end() ; ++i){
    //     if(*i == true){
    //         p.push_back();
    //     }
    // }

    vector<int> primes;

    SieveOfEratosthenes(primes);
    cout<<primes[10000];
    return 0;    
}