#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

// here first argument is new inserted member in string
// here second argument is all the string members in string array one by one during comparision purpose and first time 0th index string is passed
bool compare(string a , string b){
    
    int temp = a.compare(0 , b.size() , b);
    cout << temp << " " << a << " " << b << endl;
    if(temp <= 0)
        return true;

    return false;
}

int main() {
	int n;
	cin >> n;
	string s[n] = {};
	for(int i = 0 ; i < n ; i++)
		cin >> s[i];

	sort(s , s + n , compare);

	for(int i = 0 ; i < n ; i++)
		cout << s[i] << endl;
    // string str1 = "batman";
    // string str2 = "cat";
    // str1 - str2 = +1 if str1 > str2 i.e. str1 = bat and str2 = aat str1 > str2
    // str1 - str2 = -1 if str1 < str2 i.e. str1 = bat and str2 = cat str1 > str2
    // cout << str1.compare(0 , str2.size() , str2);
    // cout << str1 - str2;
	return 0;
}