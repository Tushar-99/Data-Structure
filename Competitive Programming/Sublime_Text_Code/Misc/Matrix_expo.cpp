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