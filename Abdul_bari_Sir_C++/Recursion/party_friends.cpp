#include<bits/stdc++.h>

using namespace std;

int party(int n){

    cout << n << endl;
    if(n <= 0)
        return 1;

    return party(n - 1) + (n - 1) * party(n - 2);
}

int main(){

    int n = 4;
    cout << party(n);
}
