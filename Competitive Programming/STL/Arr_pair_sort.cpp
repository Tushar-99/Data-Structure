#include<bits/stdc++.h>

using namespace std;

int main(){

    pair<int , int> arr[5];
    map< pair <int , int >, int> m;
    int arrP[5] = {1 , 5 , 8 , 2 , 9};

    // int j = 0;
    // for(int i = 0 ; i < 5 ; i++){
    //     m[{arrP[i] , i}] = j++;
    // }
    // for(auto x : m)
    //     cout << x.first.first << " "  << x.first.second << " " << x.second << endl;

    // cout << endl;
    // for(int i = 0 ; i < 5 ; i++){
    //     arr[i].first = arrP[i]; 
    //     arr[i].second = i;
    // }
    // sort(arr , arr + 5);
    // for(auto x : arr){
    //     cout << x.first << " " << x.second << endl;
    // }

    pair< pair< int , int > , int > p[5];
    p[0] = {{101 , 0} , 0};
    p[1] = {{758 , 1} , 1};
    p[2] = {{315 , 2} , 2};
    p[3] = {{730 , 3} , 3};
    p[4] = {{472 , 4} , 4};

    for(int i = 0 ; i < 5 ; i++)
        cout << p[i].first.first << " " << p[i].first.second << " " << p[i].second << endl;

    sort(p , p + 5);

    cout << endl;
    for(int i = 0 ; i < 5 ; i++)
        cout << p[i].first.first << " " << p[i].first.second << " " << p[i].second << endl;

}