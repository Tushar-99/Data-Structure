#include<bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){

        int n , k , num , max_no , max_count , *arr , min_days = 0 , flag = false;
        unordered_map<int , int> m;
        cin >> n >> k;
        arr = new int[n];

        for(int i = 0 ; i < n ; i++){
            cin >> arr[i];
            m[arr[i]]++;
        }

        // for(int i = 0 ; i < n ; i++)
        //     cout << arr[i] << " " ;

        // cout << endl;

        // for(auto x : m)
        //     cout << x.first << " " << x.second << endl;

        auto it = m.begin();
        max_no = it->first;
        max_count = it->second;
        // cout << max_no << " " << max_count << endl;
        it++;
        while(it != m.end()){

            if(it->second > max_count){
                max_count = it->second;
                max_no = it->first;
            }
            it++;
        }

        //cout << max_no << " " << max_count << endl;
        int i = 0;
        while(i < n){
            flag = false;

            if(arr[i] != max_no){
                flag = true;
                i += k;
            }

            if(flag)
                min_days++;
            
            else
                i++;
        }

        cout << min_days << endl;
    }
}