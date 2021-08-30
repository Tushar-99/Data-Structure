#include<bits/stdc++.h>

using namespace std;

void populate_sum(vector<int> &A , unordered_set<long long> &psum) {

	long long sum = 0;
	int asize = A.size();
	for (int i = 0; i < asize; i++) {
		sum += A[i];
	}

	psum.insert(sum);

	int minm = *min_element(A.begin() , A.end());
	int maxm = *max_element(A.begin() , A.end());

	if (minm == maxm) return;

	int avg = (minm + maxm) / 2;

	vector<int> lthan , gthan;

	for (int i = 0; i < asize; i++) {
		if (A[i] <= avg) lthan.push_back(A[i]);
		else gthan.push_back(A[i]);
	}

	populate_sum(lthan , psum);
	populate_sum(gthan , psum);
}

int main(int argc, char const *argv[]) {

	int t;
	cin >> t;

	while (t--) {

		int q , n;
		cin >> n >> q;

		vector<int> A(n) , Q(q);

		for (int i = 0; i < n; ++i) {
			cin >> A[i];
		}

		for (int i = 0; i < q; ++i) {
			cin >> Q[i];
		}

		unordered_set<long long> psum;

		populate_sum(A , psum);

		for (int i = 0; i < q; ++i) {
			if (psum.find(Q[i]) != psum.end())
				cout << "Yes" << endl;

			else
				cout << "No" << endl;
		}
	}

	return 0;
}