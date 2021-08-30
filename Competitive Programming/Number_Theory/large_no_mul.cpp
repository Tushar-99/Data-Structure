#include<bits/stdc++.h>

using namespace std;

int main(){

    string num1 , num2;

    cin >> num1 >> num2;

    // cout << num1 << " " << num2 <<endl;
    
    if(num1.length() > num2.length())
        swap(num2 , num1);
    
    // cout << num1 << " " << num2 <<endl;
    int len1 = num1.length() , len2 = num2.length(), carry , i_n1 = 0 , i_n2 = 0 , n1 , n2 , sum , res[len1 + len2] = {0};
    for(int i = len1 - 1 ; i >= 0 ; i--){

        n1 = num1[i] - 48;
        i_n2 = 0;
        sum = 0;
        carry = 0;
        for(int j = len2 - 1 ; j >= 0 ; j--){
            n2 = num2[j] - 48;

            sum = n1 * n2 + carry + res[i_n1 + i_n2];
            res[i_n1 + i_n2] = sum % 10;
            carry = sum / 10;
            i_n2++;
        }

        if(carry){
            res[i_n1 + i_n2] += carry;
            carry /= 10;
        }
        i_n1++;
    }

    for(int i = len1 + len2 - 1 ; i >= 0 ; i--)
        cout << res[i];
}