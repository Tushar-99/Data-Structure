#include<bits/stdc++.h>

using namespace std;

#define ll long long

void matrixMul(ll **m1, ll **m2 , int k , ll **res , int p) {

    ll sum = 0;
    for (int i = 0; i <= k ; i++) {
        for (int j = 0; j <= k; j++) {
            for (int l = 0; l <= k; l++) {
                // res[i][j] = (res[i][j] + (m1[i][l] * m2[l][j]) % mod) % mod;
                sum += (m1[i][l] * m2[l][j]) % p;
            }
            res[i][j] = sum % p;
            sum = 0;
        }
    }
}

int main() {

    int test;
    cin >> test;

    while (test--) {

        ll **res , **t , *b , *c , **dum , m , n , sum = 0 , *F1;
        int k , p;

        cin >> k;
        b = new ll[k];
        c = new ll[k];
        F1 = new ll[k + 1];
        res = new ll*[k + 1];
        t = new ll*[k + 1];
        dum = new ll*[k + 1];
        for (int i = 0 ; i <= k ; i++) {
            res[i] = new ll[k + 1];
            t[i] = new ll[k + 1];
            dum[i] = new ll[k + 1];
        }

        for (int i = 0 ; i < k ; i++) {
            cin >> b[i];
            sum += b[i];
        }
        for (int i = 0 ; i < k ; i++)
            cin >> c[i];

        cin >> m >> n >> p;

        for (int i = 0; i <= k; i++) {
            for (int j = 0 ; j <= k ; j++) {
                if (i == j)
                    res[i][j] = 1;

                else
                    res[i][j] = 0;

            }
        }

        t[0][0] = 1;
        for (int i = 1 ; i <= k ; i++)
            t[0][i] = c[k - i];

        for (int i = 1; i < k; i++) {
            for (int j = 2 ; j <= k ; j++) {
                if (i == j - 1)
                    t[i][j] = 1;

                else
                    t[i][j] = 0;

            }
        }

        for (int i = 1 ; i <= k ; i++)
            t[i][0] = 0;

        for (int i = 1 ; i < k ; i++)
            t[i][1] = 0;

        for (int i = 1 ; i <= k ; i++)
            t[k][i] = c[k - i];

        m -= 2;
        while (m) {
            if (m & 1) {
                matrixMul(t , res , k , dum , p);
                for (int i = 0 ; i <= k ; i++) {
                    for (int j = 0 ; j <= k ; j++) {
                        res[i][j] = dum[i][j];
                    }
                }
            }

            matrixMul(t , t , k , dum , p);

            for (int i = 0 ; i <= k ; i++) {
                for (int j = 0 ; j <= k ; j++) {
                    t[i][j] = dum[i][j];
                }
            }

            m /= 2;
        }

        int sum1 = 0;
        sum1 = res[0][0] * sum;
        for (int i = 1; i <= k; i++) {
            sum1 = (sum1 + (res[0][i] * b[i - 1]) % p) % p;
        }

        sum1 -= (b[k - 1] * k - 1);

        for (int i = 0; i <= k; i++) {
            for (int j = 0 ; j <= k ; j++) {
                if (i == j)
                    res[i][j] = 1;

                else
                    res[i][j] = 0;

            }
        }

        t[0][0] = 1;
        for (int i = 1 ; i <= k ; i++)
            t[0][i] = c[k - i];

        for (int i = 1; i < k; i++) {
            for (int j = 2 ; j <= k ; j++) {
                if (i == j - 1)
                    t[i][j] = 1;

                else
                    t[i][j] = 0;

            }
        }

        for (int i = 1 ; i <= k ; i++)
            t[i][0] = 0;

        for (int i = 1 ; i < k ; i++)
            t[i][1] = 0;

        for (int i = 1 ; i <= k ; i++)
            t[k][i] = c[k - i];

        n -= 2;
        while (n) {
            if (n & 1) {
                matrixMul(t , res , k , dum , p);
                for (int i = 0 ; i <= k ; i++) {
                    for (int j = 0 ; j <= k ; j++) {
                        res[i][j] = dum[i][j];
                    }
                }
            }

            matrixMul(t , t , k , dum , p);

            for (int i = 0 ; i <= k ; i++) {
                for (int j = 0 ; j <= k ; j++) {
                    t[i][j] = dum[i][j];
                }
            }

            n /= 2;
        }

        int sum2 = 0;
        sum2 = res[0][0] * sum;
        for (int i = 1; i <= k; i++) {
            sum2 = (sum2 + (res[0][i] * b[i - 1]) % p) % p;
        }

        cout << sum2 - sum1 << endl;
    }
}


#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000000
using namespace std;

vector<ll> a, b, c;
ll k , p , sum = 0;

vector<vector<ll>> multiply(vector<vector<ll>> A, vector<vector<ll>> B)
{
    //Matrix to store the result
    vector<vector<ll>> C(k + 2, vector<ll>(k + 2));

    for (int i = 1; i <= k + 1; i++)
    {
        for (int j = 1; j <= k + 1; j++)
        {
            for (int x = 1; x <= k + 1; x++)
            {
                C[i][j] = (C[i][j] + (A[i][x] * B[x][j]) % p) % p;
            }
        }
    }
    return C;
}

vector<vector<ll>> pow(vector<vector<ll>> A, ll n) {

    if (n == 1)
        return A;

    if (n & 1)
        return multiply(A, pow(A, n - 1));

    vector<vector<ll>> X = pow(A, n / 2);
    return multiply(X, X);
}

ll compute(ll n) {

    if (n == 0)
        return 0;
    if (n <= k)
        return b[n - 1];

    //otherwise using matrix exponentiation
    vector<ll> F1(k + 2);

    //Indexing from 1
    F1[1] = sum;
    for (int i = 2; i <= k + 1; i++)
        F1[i] = b[i - 2];

    vector<vector<ll>> T(k + 2 , vector<ll>(k + 2));

    for (int i = 1; i <= k + 1; i++)
    {
        for (int j = 1; j <= k + 1; j++)
        {
            if (i == 1) {
                if (i == j)
                    T[i][j] = 1;
                else
                    T[i][j] = c[k - j + 1];
            }

            else if (i < k + 1)
            {
                if (j == i + 1)
                    T[i][j] = 1;

                else
                    T[i][j] = 0;
            }

            else {
                if (j == 1)
                    T[i][j] = 0;
                else
                    T[i][j] = c[k - j + 1];
            }
        }
    }

    T = pow(T, n - 1);

    ll ans = 0;
    for (int i = 1; i <= k + 1; i++)
        ans = (ans + (T[1][i] * F1[i]) % p) % p;

    return ans;
}

int main()
{
    ll t, n, num , m;
    cin >> t;
    while (t--)
    {
        cin >> k;

        // F1 vector
        for (int i = 0; i < k; i++)
        {
            cin >> num;
            b.push_back(num);
            sum += num;
        }

        //coefficients
        for (int i = 0; i < k; i++)
        {
            cin >> num;
            c.push_back(num);
        }

        //value of n (nth term to be computed in sequence)
        cin >> m >> n >> p;

        cout << compute(n - 1) - compute(m) << endl;

        b.clear();
        c.clear();
    }
    return 0;
}
