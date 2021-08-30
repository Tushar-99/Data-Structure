#include<bits/stdc++.h>

using namespace std;

bool rec_pal(string str , int l , int r) {

	if (l >= r)
		return true;

	if (str[l] != str[r])
		return false;

	return rec_pal(str , ++l , --r);
}

int main() {

	string str;

	getline(cin , str);

	cout << str << endl;
	cout << str.length() - 1 << endl;

	// int l = 0 , r = str.size() - 1;
	// while (l < r) {

	// 	if (str[l] == str[r]) {
	// 		l++;
	// 		r--;
	// 	}
	// 	else
	// 		break;
	// }

	// if (l >= r)
	// 	cout << "Pallindrome" << endl ;

	// else
	// 	cout << "Not Pallindrome" << endl ;

	bool res = rec_pal(str , 0 , str.length() - 1);

	if (res == 1)
		cout << "Pallindrome" << endl ;

	else
		cout << "Not Pallindrome" << endl ;
}