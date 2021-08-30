#include<bits/stdc++.h>

using namespace std;

int main(){

    int test = 10;

    while(test--){

    string tot , div , anst = "" , ansd = "" , add = "" , sub = "";
    cin >> tot >> div;

    int idx = 0 , temp = tot[0] - 48;
    while(temp < 2 &&idx < tot.size()){
        temp  = temp * 10 + tot[++idx] - 48;
    }

    while(idx < tot.size()){
        anst += (temp / 2) + 48;
        temp = (temp % 2) + tot[++idx] - 48;
    }

    temp = div[0] - 48;
    idx = 0;
    while(temp < 2 &&idx < div.size()){
        temp  = temp * 10 + div[++idx] - 48;
    }
    
    while(idx < div.size()){
        ansd += (temp / 2) + 48;
        temp = (temp % 2) + div[++idx] - 48;
    }

    cout << anst << " " << ansd << endl;
    int n1 = anst.size() , n2 = ansd.size() , diff = n1 - n2 , carry = 0;

    for(int i = n2 - 1 ; i >=0 ; i--){

        int sub1 = (anst[i + diff] - 48) - (ansd[i] - 48) - carry;

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
        if(anst[i] == '0' && carry){
            sub.push_back('9');
            continue;
        }

        int sub1 = ((anst[i] - 48) - carry);
        if(i > 0 || sub1 > 0)
            sub.push_back(sub1 + '0');
        
        carry = 0;
    }

    carry = 0;
    for(int i = n2 - 1 ; i >= 0 ; i--){
        int sum = (anst[i + diff] - 48) + (ansd[i] - 48) + carry;

        add.push_back(sum + '0');
        carry = sum / 10;
    }

    for(int i = n1 - n2 - 1 ; i >= 0 ; i--){
        int sum = ((anst[i] - 48) + carry);
        add.push_back(sum + '0');
        carry = sum / 10;
    }

    if(carry)
        add.push_back(carry + '0');

    for(int i = add.length() ; i >= 0 ; i++)
        cout << add[i];

    cout << endl;

    for(int i = sub.length() ; i >= 0 ; i++)
        cout << sub[i];

    }
}