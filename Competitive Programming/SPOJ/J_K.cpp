#include<bits/stdc++.h>

using namespace std;

int main(){

    int test = 10;

    while(test--){

        string tot , div , sub = "" , ans = "" , add = "";
        cin >> tot >> div;

        int n1 = tot.size() , n2 = div.size() , diff = n1 - n2 , carry = 0;

        // cout << n1 << " " << n2 << endl;
        for(int i = n2 - 1 ; i >=0 ; i--){

            int sub1 = (tot[i + diff] - 48) - (div[i] - 48) - carry;

            if(sub1 < 0){
                sub1 += 10;
                carry = 1;
            }
            else{
                carry = 0;
            }
            sub.push_back(sub1 + '0');    
        }

        for(int i = n1 - n2 - 1 ; i >= 0 ; i--){
            if(tot[i] == '0' && carry){
                sub.push_back('9');
                continue;
            }

            int sub1 = ((tot[i] - 48) - carry);
            if(i > 0 || sub1 > 0)
                sub.push_back(sub1 + '0');
        
            carry = 0;
        }

        reverse(sub.begin() , sub.end());
        // cout << sub << endl;
        int idx = 0 , temp = (sub[0] - 48);
        while(temp < 2 && idx < sub.size()){
            temp  = temp * 10 + sub[++idx] - 48;
        }

        while(idx < sub.size()){
            ans += (temp / 2) + 48;
            temp = (temp % 2) * 10 + sub[++idx] - 48;
        }

        carry = 0;
        n1 = ans.length();
        diff = n1 - n2;
        for(int i = n2 - 1 ; i >= 0 ; i--){
            int sum = (ans[i + diff] - 48) + (div[i] - 48) + carry;

            add.push_back((sum % 10) + '0');
            carry = sum / 10;
        }

        for(int i = n1 - n2 - 1 ; i >= 0 ; i--){
            int sum = ((ans[i] - 48) + carry);
            add.push_back(sum % 10 + '0');
            carry = sum / 10;
        }

        if(carry)
            add.push_back(carry + '0');

        reverse(add.begin() , add.end());

        cout << add << endl << ans << endl;
    }
}
