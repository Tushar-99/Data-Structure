#include<bits/stdc++.h>

using namespace std;

int main(){
    int n = 12;
    cout << log2(n & -n) + 1;
}