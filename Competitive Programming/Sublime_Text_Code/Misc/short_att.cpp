#include<bits/stdc++.h>

using namespace std;

int main() {

	int t;
	cin >> t;
	while (t--) {
		int N , pre = 0;
		string B;
		cin >> N;
		cin >> B;

		for (int i = 0 ; i < N ; i++) {
			if (B[i] == '1')
				pre++;
		}
		if ((pre + (120 - N)) >= 90)
			cout << "YES" << endl;

		else
			cout << "NO" << endl;
	}
}