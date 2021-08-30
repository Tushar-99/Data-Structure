//Have some mistake needed to correct immediately --> fully corrected enjoy life
#include<bits/stdc++.h>

using namespace std;

#define mod 1000000000

#define ll long long

void matrixMul(ll **m1, ll **m2 , int k , ll **res) {

    ll sum = 0;
    for (int i = 0; i < k ; i++) {
        for (int j = 0; j < k; j++) {
            for (int l = 0; l < k; l++) {
                // res[i][j] = (res[i][j] + (m1[i][l] * m2[l][j]) % mod) % mod;
                sum += (m1[i][l] * m2[l][j]) % mod;
            }
            res[i][j] = sum % mod;
            sum = 0;
        }
    }
}

int main() {

#ifdef ONLINE_JUDGE
    //for getting input from input.txt
    freopen("inputf.in" , "r", stdin);
    //for wrtiting output to output.txt
    freopen("outputf.in" , "w" , stdout);
#endif

    int test;
    cin >> test;
    while (test--) {
        ll **res , **t , *b , *c , **dum;
        int k , n , temp;
        cin >> k;

        b = new ll[k];
        c = new ll[k];
        res = new ll*[k];
        t = new ll*[k];
        dum = new ll*[k];
        for (int i = 0 ; i < k ; i++) {
            res[i] = new ll[k];
            t[i] = new ll[k];
            dum[i] = new ll[k];
        }

        for (int i = 0 ; i < k ; i++)
            cin >> b[i];

        for (int i = 0 ; i < k ; i++)
            cin >> c[i];

        cin >> n;

        for (int i = 0; i < k - 1; i++) {

            t[i][0] = 0;
            for (int j = 1 ; j < k ; j++) {
                if (i == (j - 1)) {
                    t[i][j] = 1;
                }
                else {
                    t[i][j] = 0;
                }
            }
        }

        for (int i = 0 ; i < k ; i++)
            t[k - 1][i] = c[k - 1 - i];

        for (int i = 0; i < k; i++) {
            for (int j = 0 ; j < k ; j++) {
                if (i == j)
                    res[i][j] = 1;

                else
                    res[i][j] = 0;

            }
        }

        temp = n - 1;
        while (temp) {

            // cout << "Before" << endl;
            // for (int i = 0 ; i < k ; i++) {
            //     for (int j = 0 ; j < k ; j++) {
            //         cout << res[i][j] << " ";
            //     }
            //     cout << endl;
            // }

            // for (int i = 0 ; i < k ; i++) {
            //     for (int j = 0 ; j < k ; j++) {
            //         cout << t[i][j] << " ";
            //     }
            //     cout << endl;
            // }

            if (temp & 1) {
                matrixMul(t , res , k , dum);
                for (int i = 0 ; i < k ; i++) {
                    for (int j = 0 ; j < k ; j++) {
                        res[i][j] = dum[i][j];
                    }
                }
            }

            matrixMul(t , t , k , dum);

            for (int i = 0 ; i < k ; i++) {
                for (int j = 0 ; j < k ; j++) {
                    t[i][j] = dum[i][j];
                }
            }

            // cout << "After" << endl;
            // for (int i = 0 ; i < k ; i++) {
            //     for (int j = 0 ; j < k ; j++) {
            //         cout << res[i][j] << " ";
            //     }
            //     cout << endl;
            // }

            // for (int i = 0 ; i < k ; i++) {
            //     for (int j = 0 ; j < k ; j++) {
            //         cout << t[i][j] << " ";
            //     }
            //     cout << endl;
            // }
            temp /= 2;
        }

        int fin = 0;
        for (int i = 0; i < k; i++) {
            fin = (fin + (res[0][i] * b[i]) % mod) % mod;
            // fin = (fin + (res[k - 1][i] * b[i]));
        }

        cout << fin << endl;
    }
}

//Error free Code
#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000000
using namespace std;

vector<ll> a, b, c;
ll k;

vector<vector<ll>> multiply(vector<vector<ll>> A, vector<vector<ll>> B)
{
    //Matrix to store the result
    vector<vector<ll>> C(k + 1, vector<ll>(k + 1));

    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            for (int x = 1; x <= k; x++)
            {
                C[i][j] = (C[i][j] + (A[i][x] * B[x][j]) % MOD) % MOD;
            }
        }
    }
    return C;
}

vector<vector<ll>> pow(vector<vector<ll>> A, ll p) {

    if (p == 1)
        return A;

    if (p & 1)
        return multiply(A, pow(A, p - 1));

    vector<vector<ll>> X = pow(A, p / 2);
    return multiply(X, X);
}

ll compute(ll n) {

    if (n == 0)
        return 0;
    if (n <= k)
        return b[n - 1];

    //otherwise using matrix exponentiation
    vector<ll> F1(k + 1);

    //Indexing from 1
    for (int i = 1; i <= k; i++)
        F1[i] = b[i - 1];

    vector<vector<ll>> T(k + 1 , vector<ll>(k + 1));

    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (i < k)
            {
                if (j == i + 1)
                    T[i][j] = 1;

                else
                    T[i][j] = 0;
            }
            else
                T[i][j] = c[k - j];
        }
    }

    T = pow(T, n - 1);

    ll ans = 0;
    for (int i = 1; i <= k; i++)
        ans = (ans + (T[1][i] * F1[i]) % MOD) % MOD;

    return ans;
}

int main()
{
    ll t, n, num;
    cin >> t;
    while (t--)
    {
        cin >> k;

        // F1 vector
        for (int i = 0; i < k; i++)
        {
            cin >> num;
            b.push_back(num);
        }

        //coefficients
        for (int i = 0; i < k; i++)
        {
            cin >> num;
            c.push_back(num);
        }

        //value of n (nth term to be computed in sequence)
        cin >> n;
        cout << compute(n) << endl;

        b.clear();
        c.clear();
    }
    return 0;
}
