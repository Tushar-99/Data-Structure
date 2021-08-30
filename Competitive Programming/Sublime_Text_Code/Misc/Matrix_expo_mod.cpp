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