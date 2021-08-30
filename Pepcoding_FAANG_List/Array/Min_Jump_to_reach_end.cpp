#include<bits/stdc++.h>

using namespace std;

int Min_Jump(int *arr , int n) {

	int min_j[n] , JPA[n] , j_from;
	// memset doesnot work for values other than 0 or -1 because it work for byte by byte
	// memset(min_j , INT_MAX , sizeof(min_j));
	min_j[0] = 0;

	for (int i = 1; i < n; ++i) {
		min_j[i] = INT_MAX;
	}

	for (int i = 1; i < n; ++i) {

		for (int j = 0; j < i; ++j) {

			// j_f = j;
			if ((i <= j + arr[j]) && (min_j[i] > min_j[j] + 1)) {
				min_j[i] = min_j[j] + 1;
				j_from = j;
			}
		}

		JPA[i] = j_from;
	}

	for (int i = 0; i < n; ++i) {
		cout << min_j[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < n; ++i) {
		cout << JPA[i] << " ";
	}
	cout << endl;

	return min_j[n - 1];
}

int main() {

	int n , *arr;

	cin >> n;
	arr = new int[n];

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	cout << Min_Jump(arr , n);
}