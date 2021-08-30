#include <bits/stdc++.h>

using namespace std;

int main() {

	int t;
	cin >> t;
	while (t--) {

		int n , d , *age , risk = 0 , days = 0 , n_risk;

		cin >> n >> d;
		age = new int[n];

		for (int i = 0 ; i < n ; i++)
			cin >> age[i];

		if (d == 1)
			cout << n << endl;

		else {

			for (int i = 0; i < n; ++i)
				if (age[i] >= 80 || age[i] <= 9)
					risk++;

			n_risk = n - risk;
			days = (n_risk / d) + (risk / d);

			if (risk % d)
				days++;

			if (n_risk % d)
				days++;

			cout << days << endl;
		}
	}
}