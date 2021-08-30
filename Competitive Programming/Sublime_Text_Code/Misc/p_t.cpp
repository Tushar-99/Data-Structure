#include<bits/stdc++.h>

using namespace std;

int main() {

	int t;
	cin >> t;

	while (t--) {
		int x , y , k , n;
		cin >> x >> y >> k >> n;

		if (x == y)
			cout << "Yes" << endl;

		else {
			if (x < y) {
				while (x <= y) {
					if (x == y) {
						cout << "Yes" << endl;
						break;
					}
					x += k;
					y -= k;
				}
				if (x > y)
					cout << "No" << endl;
			}

			else {
				while (x >= y) {
					if (x == y) {
						cout << "Yes" << endl;
						break;
					}
					x -= k;
					y += k;
				}
				if (x < y)
					cout << "No" << endl;
			}
		}
	}
}