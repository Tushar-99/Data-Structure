#include<bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){
        char temp;
        string str1 , str2 , res = "";

        cin >> str1 >> str2;
        // cout << str1 << " " << str2 << endl;
        int n = str1.length();
        // cout << n;
        // cout << str1[3] << " " << str2[3];
        for(int i = 0 ; i < n ; i++){
            //cout << str1[i] << "^" << str2[i] << "-->" << (str1[i] ^ str2[i]) << endl;
            cout << (str1[i] ^ str2[i]);
        }

        cout << endl;
    }
}