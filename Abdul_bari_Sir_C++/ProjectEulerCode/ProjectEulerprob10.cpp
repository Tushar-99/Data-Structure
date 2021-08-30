#include<bits/stdc++.h>

using namespace std;

#define MAX_SIZE 2000000

void SieveOfEratosthenes(vector<int> &primes){

    bool prime[MAX_SIZE+1];
    memset(prime , true , sizeof(prime));

    for(int i = 4 ; i <= MAX_SIZE ; i+=2){
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

    vector<int> primes(2000000);
    long long sum=0;
    SieveOfEratosthenes(primes);
    
    for(int i = 0; i < primes.size() ; i++){
        sum += primes[i];
    }
    cout<<sum;
    
    return 0;    
}