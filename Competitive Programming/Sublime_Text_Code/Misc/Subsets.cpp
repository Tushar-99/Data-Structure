#include <bits/stdc++.h>
using namespace std;

int main() {

    string str;
    cin >> str;

    int n = str.length() , temp , j;
    cout << n << endl;
    for (int i = 0 ; i < (1 << n) ; i++) {
        temp = i;
        j = 0;
        while (temp > 0) {

            if ((temp & 1) == 1)
                cout << str[j];

            temp >>= 1;
            j++;
        }
        cout << endl;
    }
}
