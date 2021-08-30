#include<bits/stdc++.h>

using namespace std;

int main(){

    int t , day , partition ,count = 0 , day_partition ;
    cin >> t;
    while(t--){
        int c = 0;
        cin >> day;
        cin >> partition;
        day_partition = day/partition;
        bool prime[day+1];
        memset(prime , true , sizeof(prime));
        int i = 4;
        while(i <= day){
            if(i % 2 == 0){
                prime[i] = false;
                i += 2;
            }
        }

        for(i = 3 ; i*i <= day ; i+=2){
            if(prime[i]){
                for(int p = i*i ; p <= day ; p +=i){
                    prime[p] = false;
                }
            }
        }
        
        prime[0]=prime[1]=false;
        
        for(i = 1 ; i <= day_partition ; i++){
            count = 0 ;
            for(int j = i ; j <= day ; j+=day_partition){
                if(prime[j] == false)
                    break;
                    
                if(prime[j]) 
                    count++;
            }
            if(count == partition){
                c++;
            }
        }
        cout<<c;
    }
}