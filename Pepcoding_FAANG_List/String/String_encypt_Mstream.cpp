#include<bits/stdc++.h>

using namespace std;

string encrypt(int n , string code , int k) {

	string cw = "";
	int num , flag = 0;
	char curr_c;

	for (int i = 0; i < n; i++) {

		curr_c = code[i];
		num = curr_c;
		if (num >= 65 && num <= 90) {
			num = code[i] + k;

			// while (num > 90)
			// 	num -= 26;

			if (num > 90) {
				num -= 65;
				num %= 26;
				flag = 1;
			}

			if (flag)
				curr_c = (num + 65);

			else
				curr_c = num;

			cw += curr_c;

		}
		else if (num >= 97 && num <= 122) {
			num = code[i] + k;
			// while (num > 122)
			// 	num -= 26;

			if (num > 122) {
				num -= 97;
				num %= 26;
				flag = 1;
			}

			if (flag)
				curr_c = (num + 97);

			else
				curr_c = num;

			cw += curr_c;
		}

		else
			cw += curr_c;

	}

	return cw;
}

int main() {

	int n , k;

	cin >> n;
	string code;
	cin >> code;
	//char *code = new char[n];

	// for (int i = 0; i < n ; ++i)
	// {
	// 	cin >> code[i];
	// }
	cin >> k;

	cout << encrypt(n , code , k);
}