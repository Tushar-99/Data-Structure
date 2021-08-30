#include<bits/stdc++.h>

using namespace std;

#define ll long

ll pre[1000005];

int main() {

	ios_base::sync_with_stdio(0); // making cin faster
	cin.tie(0);
	int t;
	cin >> t;

	while (t--) {
		int n , num;
		cin >> n;

		memset(pre , 0 , sizeof(pre));

		pre[0] = 1;
		int sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> num;
			sum += num;
			sum %= n;
			sum = (sum + n) % n;	//to safe from -ve index
			pre[sum]++;
		}

		ll ans = 0;
		for (int i = 0; i < n; i++) {
			ll m = pre[i];
			ans += (m) * (m - 1) / 2;
		}

		cout << ans << endl;
	}
}