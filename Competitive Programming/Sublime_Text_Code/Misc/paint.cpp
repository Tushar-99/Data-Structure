#include<bits/stdc++.h>

using namespace std;

int main() {

#ifdef ONLINE_JUDGE
    //for getting input from input.txt
    freopen("inputf.in" , "r", stdin);
    //for wrtiting output to output.txt
    freopen("outputf.in" , "w" , stdout);
#endif

    int t;
    cin >> t;

    while (t--) {

        int n , k , num , max_no , max_count , *arr , min_days = 0 , flag = false;
        unordered_map<int , int> m;
        cin >> n >> k;
        arr = new int[n];

        for (int i = 0 ; i < n ; i++) {
            cin >> arr[i];
            m[arr[i]]++;
        }

        auto it = m.begin();
        max_no = it->first;
        max_count = it->second;

        it++;
        while (it != m.end()) {

            if (it->second > max_count) {
                max_count = it->second;
                max_no = it->first;
            }
        }

        cout << max_no << " " << max_count << endl;
        // int i = 0 , j;
        // while (i < n) {

        //     for (j = 0 ; j  < k ; j++) {

        //         if (arr[i] != max_no)
        //             flag = true;

        //         i++;
        //     }
        //     if (flag)
        //         min_days++;
        // }

        // cout << min_days << endl;
    }
}