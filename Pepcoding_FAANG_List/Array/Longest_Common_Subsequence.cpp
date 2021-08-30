#include<bits/stdc++.h>

using namespace std;

int c = 0;

int static dp[6][8];

// Bottom Up
// Memoization
int LCS(string str1 , string str2 , int i = 0 , int j = 0) {

	// c++;

	if (str1[i] == '\0' || str2[j] == '\0')
		return 0;

	if (dp[i][j] != -1) {
		return dp[i][j];
	}

	if (str1[i] == str2[j]) {
		dp[i][j] = 1 + LCS(str1 , str2 , i + 1 , j + 1);
		return dp[i][j];
	}

	else {
		dp[i][j] = max(LCS(str1 , str2 , i + 1 , j) , LCS(str1 , str2 , i , j + 1));
		return dp[i][j];
	}

	return dp[i][j];
}

// LCS using DP

int LCS_DP(string str1 , string str2) {

	int L[str1.length() + 1][str2.length() + 1];

	// cout << str1.length() << " " << str2.length() << endl;
	memset(L , 0 , sizeof(L));

	for (int i = str1.length() - 1; i >= 0 ; i--) {

		for (int j = str2.length() - 1; j >= 0  ; j--) {

			c++;
			if (str1[i] == str2[j])
				L[i][j] = 1 + L[i + 1][j + 1];

			else {

				L[i][j] = max(L[i + 1][j] , L[i][j + 1]);
			}
		}
	}

	return L[0][0];
}

int main() {

	memset(dp , -1 , sizeof(dp));

	string str1 , str2;

	cin >> str1 >> str2;

	cout << LCS_DP(str1 , str2) << endl;

	cout << c;
}