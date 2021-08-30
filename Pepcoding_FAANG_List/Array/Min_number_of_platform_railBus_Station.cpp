#include<bits/stdc++.h>

using namespace std;

int no_of_plat(int *arr , int *dep , int n) {

	int res = 1 , plat = 1;

	for (int i = 0; i < n; ++i) {

		plat = 1;

		for (int j = i + 1; j < n; ++j) {

// here logic is either j index arrival time lie inbetween arrival and departure time of i index or j index departure time lie inbetween arrival and departure time of i index.

			// if ((arr[i] <= arr[j] && dep[i] >= arr[j]) || (arr[i] <= dep[j] && dep[j] <= dep[i]))
			// 	plat++;

// one more thinking process either 2 lie in 1 or 1 lie in 2 that is jth index arr time lie inbetween ith index arr and dep time or ith index arr time lie inbetween jth index arr and dep time respectively
			if ((arr[i] <= arr[j] && dep[i] >= arr[j]) || (arr[j] <= arr[i] && arr[i] <= dep[j])) {
				plat++;
			}
		}

		if (plat > res)
			res = plat;
	}

	return res;
}

int better_Min_plat() {


}

int main() {

	int n , *arr , *dep;

	cin >> n;

	arr = new int[n];
	dep = new int[n];

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; ++i) {
		cin >> dep[i];
	}

	cout << no_of_plat(arr , dep , n);
}