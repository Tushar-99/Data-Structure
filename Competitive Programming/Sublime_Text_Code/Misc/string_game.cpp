#include<bits/stdc++.h>

using namespace std;



int main() {

#ifdef ONLINE_JUDGE
    //for getting input from input.txt
    freopen("inputf.in" , "r", stdin);
    //for wrtiting output to output.txt
    freopen("outputf.in" , "w" , stdout);
#endif
    //cin reads a string upto first space where as getline reads upto whole line i.e.
    //until "\n" is encountered and it also read spaces from the line
    int pos , min = INT_MAX , diff , i = 0 , j  = 0 , len = 0 , found = -1 , count = 0 , sz = 0 , setPos = 0;
    bool flag = false , milS = false;
    string str1 , str2;
    set<int> s;
    //string str3, str4;
    getline(cin , str1);
    getline(cin , str2);
    // cin >> str3;
    // cin >> str4;
    // for (int i = 0; i < str1.length() ; i++) {
    //     cout << str1.at(i);
    // }
    // cout << endl;
    // cout << str3 << endl;
    // cout << str4;

    if (str1.length() < str2.length())
        cout << "No String" ;

    else {

        while (len < str1.length()) {
            found = str1.find(str2.at(0) , found + 1);
            if (found != string::npos)
                s.insert(found);
            len++;
        }

        diff = str1.length() - str2.length();
        int sizeSet = s.size();
        auto it = s.begin();

        while (sz < sizeSet) {
            i = *it;
            count = 0;
            setPos = 0;
            while (i <= str1.length() - diff && j < str2.length()) {

                if (str1.at(i) == str2.at(j)) {

                    if (str1.at(i) == str2.at(0)) {
                        pos = i;
                    }

                    else if (str1.at(i) == str2.at(str2.length() - 1))
                        break;

                    j++;
                    diff--;
                }

                if (count >= str2.length() && min > count && str1.at(i) == str2.at(str2.length() - 1)) {
                    min = count;
                    setPos = pos;
                    flag = true;
                    break;
                }

                else
                    flag = false;

                i++;
                count++;
            }
            it++;
            sz++;
        }
    }

    if (flag) {
        while (min--) {
            cout << str1.at(setPos++);
        }
    }
    else
        cout << "No String";
}
