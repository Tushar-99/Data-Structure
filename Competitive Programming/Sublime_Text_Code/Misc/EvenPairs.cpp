#include<bits/stdc++.h>

using namespace std;

#define ll long long
int main() {

	int t;
	cin >> t;
	while (t--) {

		ll A , B , o_no , res;
		cin >> A >> B;

		res = (A / 2) * B;

		if (A & 1) {
			if (B & 1)
				res += (B / 2) + 1;

			else
				res += (B / 2);
		}
		cout << res << endl;
	}
	return 0;
}