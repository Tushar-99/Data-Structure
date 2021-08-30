#include<bits/stdc++.h>

using namespace std;

int main() {

	int t;
	cin >> t;

	while (t--) {
		char c;
		int m , n;
		cin >> n >> m;
		vector<vector<int>> v(n, vector<int>(m));

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cin >> c;

				if (c == '*')
					v[i][j] = 1;
			}
		}

		for (int i = 0; i < n ; ++i) {
			for (int j = 0; j < m; ++j) {
				cout << v[i][j] << " ";
			}
			cout << endl;
		}

		int ans = 0;
		for (int i = n - 2; i >= 0; i--) {
			for (int j = m - 2; j >= 1; j--) {
				if (v[i][j] == 1)
					v[i][j] = 1 + min({v[i + 1][j - 1] , v[i + 1][j] , v[i + 1][j + 1]});
			}
		}

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				ans += v[i][j];
			}
		}

		cout << ans << endl;
	}
}