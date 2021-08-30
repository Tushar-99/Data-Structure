#include<bits/stdc++.h>

using namespace std;

// bool cmp(pair<int , int> &a, pair<int , int> &b) {
//     return a.second < b.second;
// }

// void qOrder(int nop, int maxAmt, map<int, int> &m) {

//     for (int i  = 1 ; i <= nop ; i++) {
//         m[i] = ceil(m[i] / maxAmt);
//     }

//     sort(m.begin() , m.end() , cmp);
// }

int main() {

#ifdef ONLINE_JUDGE
    //for getting input from input.txt
    freopen("inputf.in" , "r", stdin);
    //for wrtiting output to output.txt
    freopen("outputf.in" , "w" , stdout);
#endif

    int t , nop , maxAmt , temp , no = 1;
    map<int, int> m;
    cin >> t;
    while (t--) {

        cin >> nop;
        cin >> maxAmt;

        for (int i = 1 ; i <= nop ; i++) {
            cin >> temp;
            m.insert({i , temp});
        }

        qOrder(nop , maxAmt , m);

        for (auto it = m.begin() ; it != m.end() ; it++) {
            cout << "Case #no" << it->first;
        }

        no++;
    }

}