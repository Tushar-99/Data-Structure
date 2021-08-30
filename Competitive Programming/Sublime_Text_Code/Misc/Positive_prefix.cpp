#include<bits/stdc++.h>

using namespace std;

int main() {

	int t;
	cin >> t;

	while (t--) {

		int N , K , sum = 0;
		cin >> N >> K;

		if (N == K) {
			for (int i = 0; i < N; i++) {
				cout << i + 1 << " ";
			}
			cout << endl;
		}
		else {
			int arr[N];

			for (int i = 0 ; i < N; i++) {
				arr[i] = (i + 1) * pow(-1 , i + 1);
			}

			int sum = 1 , count;
			count  = floor((double)N / 2);

			for (int i = 1; i < N; i++) {
				sum += arr[i];

				if (sum > 0) {
					if (count < K) {
						for (int j = N - 1 ; j >= 0; j--) {
							if (arr[j] < 0) {
								arr[j] = arr[j] * (-1);
								count++;
								if (count == K)
									break;
							}
						}
					}

					else if (count > K) {
						for (int j = N - 1; j >= 0; j--) {
							if (arr[j] > 0) {
								arr[j] = arr[j] * -1;

								count--;
								if (count == K)
									break;
							}
						}
					}
				}
			}

			for (int i = 0; i < N; i++) {
				cout << arr[i] << " ";
			}

			cout << endl;
		}
	}
}