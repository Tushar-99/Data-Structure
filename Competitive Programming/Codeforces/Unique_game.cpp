#include<bits/stdc++.h>

using namespace std;

int main(){

    bool flag = false;
    int t , n , val , res , * game , unq;
    cin >> t;

    while(t--){
        cin >> n;
        game = new int[n];
        map<int , int> m;
        unq = -1;

        for(int i = 0 ; i < n ; i++)
            cin >> game[i];

        for(int i = 0 ; i < n ; i++)
            m[game[i]]++;

        int min = INT_MAX;
        for(int i = 0 ; i < n ; i++){
            
            if(min > game[i]){

                if(m.find(game[i])->second == 1){
                    
                    min = game[i];
                    unq = i + 1;
                }
            }
        }
        cout << unq << endl;
    }
}