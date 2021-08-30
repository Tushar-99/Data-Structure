// #include<bits/stdc++.h>

// using namespace std;

// /* Brand new approach developed by me but may result in error not tested for every cases */

// // for this input below algo fails
// // Input :-
// // 7
// // 8 -8 9 -9 10 -11 12

// // Output :-
// // 8 0
// // 12 0
// // 9 2
// // 10 4
// // 11 6
// // 11
// // 12

// // but here output is 22 instead of 12
// /*
// 	I tried to solve this issue but this doesn't form pattern i have to solve it in discrete random cases which is not good approach
// */

// // below wrong approach
// // aware of these kind of scenario don't try to handle discrete cases instead // start looking for pattern for as small test case possible and try to find
// // pattern as increasing no of input
// // Always try to find that edge case where your algo fails until not stop
// int max_cir_sub(int *a , int n) {

// 	int *p1 = new int[n] {0};
// 	int *p2 = new int[n] {0};

// 	// int l = 0 , r = 0;
// 	int cur_sum = 0 , K_max_sum = INT_MIN , osum = INT_MIN , r_osum = INT_MIN , sum = 0 , r_sum = 0 , e_i = 0 , e_r_i = 0;

// 	for (int i = 0; i < n; ++i) {

// 		cur_sum += a[i];

// 		if (cur_sum < 0)
// 			cur_sum = 0;

// 		if (cur_sum > K_max_sum)
// 			K_max_sum = cur_sum;
// 	}

// 	for (int i = 0; i < n; ++i) {

// 		sum += a[i];
// 		r_sum += a[n - i - 1];
// 		p1[i] = sum;
// 		p2[i] = r_sum;


// 		if (osum < sum) {
// 			osum = sum;
// 			e_i = i;
// 			cout << osum << " " << e_i << endl;
// 		}

// 		if (r_osum < r_sum) {
// 			r_osum = r_sum;
// 			e_r_i = i;
// 			cout << r_osum << " " << e_r_i << endl;
// 		}
// 	}

// 	int ans = 0 , res = 0;
// 	int oa = e_i + e_r_i + 2;

// 	// Greedy but wrong why because DP we have see all possibility may be upcoming become more positive then already taken
// 	// int l = 0 , r = 0;

// 	// for (int i = 0; i < n; ++i)
// 	// {
// 	// 	if (p1[l] == p2[r]){
// 	// 		res = p1[i] + p2[i];
// 	// 		l++;
// 	// 		r++;
// 	// 	}

// 	// 	else if(p1[l] > p2[r]){

// 	// 	}


// 	// 	else
// 	//

// 	// }

// 	if (oa <= n) {
// 		cout << "yes" << endl;
// 		ans = osum + r_osum;
// 		cout << ans << endl;
// 	}

// 	else
// 		ans = osum;

// 	cout << ans << endl;

// 	return max(K_max_sum , ans);
// }

// int main() {

// 	int *arr , n;

// 	cin >> n;
// 	arr = new int[n];

// 	for (int i = 0; i < n; ++i)
// 	{
// 		cin >> arr[i];
// 	}

// 	cout << max_cir_sub(arr , n);
// }
