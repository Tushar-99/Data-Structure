#include<bits/stdc++.h>

using namespace std;

int main() {

	int t;
	cin >> t;
	while (t--) {

		int n , m;
		cin >> n >> m;

		vector<int> A(n);
		vector<pair<int , double>> B(m);

		for (int i = 0; i < n; ++i)
			cin >> A[i];

		for (int i = 0; i < m; ++i) {
			cin >> B[i].first;
			cin >> B[i].second;
		}

		int mismatch = -1;

		for (int i = 0; i < n; ++i) {
			if ((A[i] - 1) != i)
				mismatch = i;
		}

		if (mismatch == -1) {
			cout << 1 << endl;
			continue;
		}
		double tot = 1;
		for (int i = 0; i < m; ++i) {
			if (mismatch < B[i].first) {
				tot *= (1 - B[i].second);
			}
		}

		cout << setprecision(15) << fixed << 1 - tot << endl;
	}
}