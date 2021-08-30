#include<bits/stdc++.h>

using namespace std;

int main() {

	int *a , n , curr_sum = 0 , max_sum = INT_MIN , s_i = 0 , e_i = 0 , s_v = 0;

	cin >> n;

	a = new int[n];

	for (int i = 0; i < n; ++i)
		cin >> a[i];

	for (int i = 0; i < n; ++i) {

		// both handle all -ve elements case

		// if at this place then all -ve cases still not handled
		// if (curr_sum > max_sum)
		// 	max_sum = curr_sum;

		// if (curr_sum >= 0)
		// 	curr_sum += a[i];

		// else {
		// 	curr_sum = a[i];
		// 	s_v = i;
		// }

		// if (curr_sum > max_sum) {
		// 	max_sum = curr_sum;
		// 	s_i = s_v;
		// 	e_i  = i;
		// }


		// curr_sum += a[i];

		// if at this place then all -ve cases still not handled
		// if (curr_sum < 0)
		// 	curr_sum = 0;

		// if (curr_sum > max_sum) {
		// 	max_sum = curr_sum;
		// 	s_i = s_v;
		// 	e_i = i;
		// }

		// if (curr_sum < 0) {
		// 	curr_sum = 0;
		// 	s_v = i + 1;
		// }

		// less intutive way
		// curr_sum = max(curr_sum + a[i], a[i]);
		// max_sum = max(curr_sum, max_sum);
	}

	// int res = max_sum;

	// if (max_sum <= 0)
	// 	s_i = e_i;

	// else {

	// 	for (int i = e_i; i >= 0; --i) {

	// 		res -= a[i];
	// 		if (res == 0) {
	// 			s_i = i;
	// 			break;
	// 		}
	// 	}
	// }

	cout << max_sum << endl;
	cout << s_i << " " << e_i << endl;
}