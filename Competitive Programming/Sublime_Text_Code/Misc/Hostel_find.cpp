#include<bits/stdc++.h>

using namespace std;

typedef long long int lli;

int main() {

#ifdef ONLINE_JUDGE
    //for getting input from input.txt
    freopen("inputf.in" , "r", stdin);
    //for wrtiting output to output.txt
    freopen("outputf.in" , "w" , stdout);
#endif

    priority_queue<lli> pq;
    int q , k , qtype;
    lli x = 0 , y = 0;
    cin >> q >> k;

    while (q--)
    {
        cin >> qtype;

        if (qtype == 1) {
            cin >> x >> y;

            if (pq.size() == k) {
                if ((x * x) + (y * y) < pq.top())
                {
                    pq.pop();
                    pq.push((x * x) + (y * y));
                }
            }

            else
                pq.push((x * x) + (y * y));
        }

        else if (qtype == 2) {
            if (pq.size() == k)
                cout << pq.top() << endl;
        }
    }
    // while (!pq.empty())
    // {
    //     cout << pq.top() << " ";
    //     pq.pop();
    // }
}