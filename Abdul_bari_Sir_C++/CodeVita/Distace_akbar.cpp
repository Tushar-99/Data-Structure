#include<bits/stdc++.h>

using namespace std;

int main(){

    // int t , n;
    // vector<pair<int ,int>> step;
    // step[0].first = 10;
    // step[0].second = 0;
    // step[1].first = 10;
    // step[1].second = 20;
    // step[2].first = -20;
    // step[2].second = 20;
    // step[3].first = -20;
    // step[3].second = -20;
    // step[4].first = 30;
    // step[4].second = -20;
    // cin >> t;
    // int prevx = 50;
    // int prevy = -20;
    // int prevDis = 0;
    // while(t--){
    //     cin >> n;

    //     if(n == 0)
    //         cout << "0 0";

    //     else if(n > 0 && n <= 5)
    //         cout << step[n - 1].first << step[n - 1].second;
        
    //     else{
    //         int i = 6;
    //         while(i <= n){
    //             if(i % 2 == 0){
    //                 prevx += prevDis + 10;
    //                 prevDis = prevx;
    //             }
    //             else{
    //                 prevy += prevDis + 10; 
    //                 prevDis = prevy;
    //             }
    //             i++;
    //         }

    //         resx = prevx + step[(n - 1) % 5].first;   
    //         resy  = prevy + step[(n - 1) % 5].second;
    //         cout << resx << " " << resy;
    //     }
    // }

    int x = 0 , y = 0 , n , distance = 10;
    char c = 'R';
    cin >> n;
    
    while(n){

        switch(c){
        
            case 'R':
                x += distance;
                c = 'U';
                break;
            
            case 'U':
                y += distance;
                c = 'L';
                break;
            
            case 'L':
                x -= distance;
                c = 'D';
                break;
            
            case 'D':
                y -= distance;
                c = 'A';
                break;
            
            case 'A':
                x += distance;
                c = 'R';
                break;
        }
        distance += 10;
        n--;
    }
    cout << x << " " << y;
}

