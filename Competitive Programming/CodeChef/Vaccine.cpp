#include<bits/stdc++.h>

using namespace std;

int main() {

    int d1 , d2 , v1 , v2 , p , temp = 0 , minDays = 0 , tot , diff;

    cin >> d1 >> v1 >> d2 >> v2 >> p;

    if (d1 == d2) {

        tot = v1 + v2;
        while (temp < p) {
            temp += tot;
            minDays++;
        }

        minDays += d1 - 1;
    }
    else {

        if (d1 > d2) {

            diff = d1 - d2;
            tot = v1 + v2;
            while (diff && temp < p) {
                temp += v2;
                minDays++;
                diff--;
            }

            while (temp < p) {
                temp += tot;
                minDays++;
            }
            minDays += d2 - 1;
        }

        else {
            diff = d2 - d1;
            tot = v1 + v2;
            while (diff && temp < p) {
                temp += v1;
                minDays++;
                diff--;
            }
            while (temp < p) {
                temp += tot;
                minDays++;
            }
            minDays += d1 - 1;
        }
    }

    cout << minDays;
}