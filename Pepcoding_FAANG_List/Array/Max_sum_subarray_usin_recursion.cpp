#include<bits/stdc++.h>

using namespace std;

int max_sum(int a[] , int n) {

	if (n == 1) return a[0];

	int m = n / 2;

	int LSS = max_sum(a , m);
	int RSS = max_sum(a + m , n - m);

	int l_sum = INT_MIN , r_sum = INT_MIN , sum = 0;
	for (int i = m - 1 ; i >= 0; --i) {
		sum += a[i];
		l_sum = max(sum , l_sum);
	}

	sum = 0;
	for (int i = m ; i < n ; ++i) {
		sum += a[i];
		r_sum = max(sum , r_sum);
	}

	// cout << sum << endl;
	return max(max(LSS , RSS) , l_sum + r_sum);
}

int main() {

	int n;
	cin >> n;

	int *a = new int[n];

	for (int i = 0; i < n; ++i) {

		cin >> a[i];
	}

	cout << max_sum(a , n);
	return 0;
}