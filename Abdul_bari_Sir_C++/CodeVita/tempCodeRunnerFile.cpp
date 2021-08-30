#include<bits/stdc++.h>

using namespace std;

bool *prime;
bool* primeSieve(int range){

    prime = new bool[range+1];
    memset(prime , true , sizeof(prime));
    int i = 4;
    while(i % 2 == 0){
        prime[i] = false;
    }

    for(i = 3 ; i*i < range ; i+=2){
        if(prime[i]){
            for(int p = i*i ; p < range ; p +=i){
                prime[i] = false;
            }
        }
    }
    prime[0]=prime[1]=false;

    return prime;
}

int main(){

    int t , day , partition ,count = 0 , day_partition , c = 0;
    bool *primeCheck;
    cin >> t;
    while(t--){

        cin >> day >> partition;
        day_partition = day/ partition;
        primeCheck = new bool[day];