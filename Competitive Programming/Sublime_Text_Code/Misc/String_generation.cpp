// #include<bits/stdc++.h>

// using namespace std;

// int main() {

//  int t;
//  cin >> t;
//  while (t--) {

//      int n , k;
//      cin >> n >> k;
//      string s;
//      int q = n / 3;
//      int rem = n % 3;
//      for (int i = 0; i < q; ++i)
//          s += "abc";

//      if (rem > 0) {
//          s += "a";
//          rem--;
//      }

//      if (rem > 0)
//          s += "b";

//      cout << s << endl;
//  }
// }

#include <bits/stdc++.h>

#define fi first
#define se second
#define m_p make_pair
#define endl '\n'
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)

using namespace std;

typedef long long ll;

const int MAXN = 1123456;
const int MAXINT = 2147483098;
const ll MAXLL = 9223372036854775258LL;

void next(char &x) {
    if (x <= 'b') x++;
    else x = 'a';
}

void solve() {
    int n, k;
    cin >> n >> k;
    char cur = 'a';
    for (int i = 0; i < n; ++i) {
        cout << cur;
        next(cur);
    }
    cout << endl;
}

int main()
{
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}