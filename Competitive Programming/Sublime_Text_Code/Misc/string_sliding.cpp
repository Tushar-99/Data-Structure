#include <bits/stdc++.h>

using namespace std;

unordered_map<char , int> frqCal(string s , int start , int end) {

    unordered_map<char , int> M;

    //for (int i = start ; s[i] != s[end] ; i++) {

    while (start < end) {

        if (M.find(s[start]) == M.end())
            M.insert(make_pair(s[start] , 1));

        else
            M[s[start]]++;

        start++;
    }
    return M;
}

int main() {

#ifdef ONLINE_JUDGE
    //for getting input from input.txt
    freopen("inputf.in" , "r", stdin);
    //for wrtiting output to output.txt
    freopen("outputf.in" , "w" , stdout);
#endif
    unordered_map<char , int> wd_count1;
    unordered_map<char , int> wd_count2;
    string str1 , str2;
    getline(cin , str1);
    getline(cin , str2);

    int l = 0 , r = 1 , fs = INT_MAX , fe = INT_MAX , i = 0 , count1 = INT_MIN , count2 = INT_MIN;
    int len1 = str1.length();
    int len2 = str2.length();
    // for (int i = 0 ; str1[i] ; i++)
    //  cout << str1[i];

    // wd_count1 = frqCal(str1 , 0 , 8);
    wd_count2 = frqCal(str2 , 0 , str2.length());

    // for (auto x : wd_count2)
    //  cout << x.first << " " << x.second << endl;

    // cout << endl;
    // wd_count1 = frqCal(str1 , l , 2);
    // for (auto x : wd_count1)
    //  cout << x.first << " " << x.second << endl;

    // for(int i = 0 ; str2[i] != str2[len2 - 1] ; i++){

    //  wd_count1 = frqCal(str1 , l , r);
    //  if(wd_count1.find(str2[i]))
    // }

    while (r < str1.length()) {

        wd_count1 = frqCal(str1 , l , r);

        while (i < str2.length()) {
            auto it1 = wd_count1.find(str2[i]);

            if (it1 != wd_count1.end()) {
                count1 = it1->second;
                count2 = wd_count2.find(str2[i])->second;
            }

            else if (count1 > count2) {
                l++;
                break;
            }

            else {
                r++;
                break;
            }
        }
    }
}