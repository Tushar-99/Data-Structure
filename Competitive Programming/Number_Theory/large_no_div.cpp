#include<bits/stdc++.h>

using namespace std;

int main(){

    string dvd , ans = ""; 
    int dvs , idx = 0 , temp;

    cin >> dvd >> dvs;
    temp = dvd[0] - 48;
    while(temp < dvs && idx < dvd.size())
        temp = temp * 10 + dvd[++idx] - 48;

    while(dvd.size() > idx){
        ans += (temp / dvs) + 48;
        temp = (temp %  dvs) * 10 + dvd[++idx] - 48;
    }

    if(ans.length() == 0)
        cout << 0;
    
    else
        cout << ans;
}