// Time Complexity --> O(n)
// Space Complexity --> O(1)

// #include<bits/stdc++.h>

// using namespace std;

// long long max_sum_subarr(long long *arr , int N) {

// 	long long max_so_far = INT_MIN , x = 0;
// 	long long max_ending = 0;
// 	long long max_element = arr[0];

// 	for (int i = 0; i < N; ++i) {
// 		max_ending = max(max_ending + arr[i] , x);
// 		max_so_far = max(max_ending , max_so_far);
// 		max_element = max(max_element , arr[i]);
// 	}

// 	if (max_so_far == 0)
// 		max_so_far = max_element;

// 	return max_so_far;
// }

// int main() {

// 	int t , N , K;
// 	long long *arr , *arr_2 , res , sum;

// 	cin >> t;

// 	while (t) {

// 		cin >> N >> K;

// 		arr = new long long[N];
// 		sum = 0;
// 		for (int i = 0 ; i < N ; i++) {
// 			cin >> arr[i];
// 			sum += arr[i];
// 		}

// 		long long size = 2 * N;
// 		arr_2 = new long long[size];
// 		for (int i = 0; i < N; ++i){
// 			arr_2[i] = arr[i];
// 		}

// 		for (int i = 0; i < N; ++i){
// 			arr_2[i + N] = arr[i];
// 		}

// 		if (K == 1)
// 			res = max_sum_subarr(arr , N);

// 		else if (sum < 0) {
// 			res = max_sum_subarr(arr_2 , (2 * N));
// 		}

// 		else {
// 			res = max_sum_subarr(arr_2 , (2 * N)) + ((K - 2) * sum);
// 		}
// 		cout << res << endl;

// 		t--;
// 	}
// }


//Best solution

// #include <bits/stdc++.h>

// using namespace std;

// const int MX = 100000;

// int a[MX];

// int main() {
// 	int T;
// 	ignore = scanf("%d", &T);
// 	while (T--) {
// 		int n, k;
// 		ignore = scanf("%d %d", &n, &k);
// 		for (int i = 0; i < n; i++) ignore = scanf("%d", a + i);

// 		long long ans = *max_element(a, a + n), sum = 0;
// 		for (int i = 0; i < n; i++) {
// 			sum += a[i];
// 			if (sum < 0) sum = 0;
// 			else ans = max(ans, sum);
// 		}

// 		if (k > 1) {
// 			long long p = 0, s = 0, pref = 0, suff = 0;
// 			for (int i = 0; i < n; i++) {
// 				p += a[i];
// 				s += a[n - 1 - i];
// 				pref = max(pref, p);
// 				suff = max(suff, s);
// 			}

// 			if (pref + suff > 0) {
// 				long long sum = max(accumulate(a, a + n, 0ll), 0ll);
// 				ans = max(pref + suff + (k - 2) * sum, ans);
// 			}
// 		}

// 		printf("%lld\n", ans);
// 	}

// 	return 0;
// }#include <bits/stdc++.h>

// using namespace std;

// const int MX = 100000;

// int a[MX];

// int main() {
// 	int T;
// 	ignore = scanf("%d", &T);
// 	while (T--) {
// 		int n, k;
// 		ignore = scanf("%d %d", &n, &k);
// 		for (int i = 0; i < n; i++) ignore = scanf("%d", a + i);

// 		long long ans = *max_element(a, a + n), sum = 0;
// 		for (int i = 0; i < n; i++) {
// 			sum += a[i];
// 			if (sum < 0) sum = 0;
// 			else ans = max(ans, sum);
// 		}

// 		if (k > 1) {
// 			long long p = 0, s = 0, pref = 0, suff = 0;
// 			for (int i = 0; i < n; i++) {
// 				p += a[i];
// 				s += a[n - 1 - i];
// 				pref = max(pref, p);
// 				suff = max(suff, s);
// 			}

// 			if (pref + suff > 0) {
// 				long long sum = max(accumulate(a, a + n, 0ll), 0ll);
// 				ans = max(pref + suff + (k - 2) * sum, ans);
// 			}
// 		}

// 		printf("%lld\n", ans);
// 	}

// 	return 0;
// }


