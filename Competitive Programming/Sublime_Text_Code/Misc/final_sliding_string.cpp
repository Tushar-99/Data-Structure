#include <bits/stdc++.h>

using namespace std;

int main() {

// #ifdef ONLINE_JUDGE
//     freopen("inputf.in" , "r", stdin);
//     freopen("outputf.in" , "w" , stdout);
// #endif

    string s , t;
    getline(cin , s);
    getline(cin , t);
    int m , n , l = 0 , r , resl = -1 , resr = 1e9;

    m = s.size();
    n = t.size();

    unordered_map<char , int> frq_s , frq_t;

    for (auto x : t) frq_t[x]++;

    for (r = 0 ; r < m ; r++) {
        frq_s[s[r]]++;

        bool good = true;
        for (auto x : frq_t) {
            if ((frq_s.count(x.first) == 0) || frq_s[x.first]  < x.second) {
                good = false;
                break;
            }
        }

        if (!good) continue;

        while (l < m && l <= r && (frq_t.count(s[l]) == 0 || frq_t[s[l]] < frq_s[s[l]])) {
            frq_s[s[l]]--;
            if (frq_s[s[l]] == 0) frq_s.erase(s[l]);
            l++;
        }

        if (resr - resl > r - l) {
            resr = r;
            resl = l;
        }
    }
    
    if (resl == -1)
        cout << "No String";

    else
        cout << s.substr(resl , resr - resl + 1);
}