#include<bits/stdc++.h>

using namespace std;

// bool cmp(pair<int , int> &a, pair<int , int> &b) {
//     return a.second < b.second;
// }

void qOrder(int nop, int maxAmt, vector<pair<int, int>> &m) {

    for (auto it = m.begin() ; it != m.end() ; it++) {
        // m[i] = ceil(m[i] / maxAmt);
        it->second = ceil(it->second / maxAmt);
    }

    sort(m.begin() , m.end() , [] (pair<int,int> a,pair<int,int> b) {return a.second < b.second;});
}

int main() {

    int t , nop , maxAmt , temp , no = 1;
    cin >> t;
    while (t--) {

        cin >> nop;
        cin >> maxAmt;
        vector<pair<int,int>> v;
        for (int i = 1 ; i <= nop ; i++) {
            cin >> temp;
            v.push_back(make_pair(i , temp));
        }

        qOrder(nop , maxAmt , v);
        cout << "Case #"<< no <<":";
        for (auto it = v.begin() ; it != v.end() ; it++) {
            cout << " " << it->first;
        }
        no++;
    }
}