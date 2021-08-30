#include<bits/stdc++.h>

using namespace std;

int main() {

	int t;
	cin >> t;

	while (t--) {

		string A;
		cin >> A;

		int size = A.size() , zero = 0 , one = 0 , count = 0;

		for (int i = 0; i < size; ++i) {
			if (A[i] == '0')
				zero++;

			else
				one++;
		}

		// cout << zero << " " << one << endl;
		if (zero == one)
			cout << 0 << endl;

		else {
			if (size % 2 || zero == 0 || one == 0)
				cout << -1 << endl;

			else if (zero > one)
				cout << (zero - one) / 2 << endl;

			else
				cout << (one - zero) / 2 << endl;
		}
	}
}