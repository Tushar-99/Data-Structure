#include<bits/stdc++.h>

using namespace std;

int Max_sum_LIS(int *arr , int n) {

	int dp[n] , osum = INT_MIN , curr_max;
	dp[0] = arr[0];


	if (n == 0)
		return 0;

	for (int i = 1; i < n; ++i) {

		curr_max = INT_MIN;
		for (int j = 0; j < i; ++j) {

			if (arr[i] >= arr[j] && dp[j] > curr_max)
				curr_max = dp[j];
		}

		if (curr_max == INT_MIN)
			dp[i] = arr[i];

		else
			dp[i] = arr[i] + curr_max;

		osum = max(dp[i] , osum);
	}

	for (int i = 0; i < n; ++i)
	{
		cout << dp[i] << " ";
	}
	cout << endl;

	// return *max_element(dp , dp + n);
	return osum;
}

int main() {

	int n , *arr;

	cin >> n;

	arr = new int[n];

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	cout << Max_sum_LIS(arr , n);
}