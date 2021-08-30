// #include<bits/stdc++.h>

// using namespace std;

// int main() {

// 	int n , *a , l = 0 , r = 0 , sum = 0 , g_sum , curr_sum;
// 	cin >> n;

// 	a = new int[n];
// 	for (int i = 0; i < n; ++i) {
// 		cin >> a[i];
// 		sum += a[i];
// 		// cout << sum << endl;
// 	}
// 	cin >> g_sum;



// 	curr_sum = a[0];
// 	// sum = 0;
// 	// GFG approach not good one but you consider it also this approach does not give you all subarrays which have sum equal to K

// 	for (int i = 1; i <= n; ++i) {

// 		while (curr_sum > g_sum && l < i - 1) {
// 			curr_sum -= a[l];
// 			l++;
// 		}

// 		if (curr_sum == g_sum) {
// 			cout << "given sum is in between " << l << " " << i - 1;
// 			break;
// 		}

// 		if (i < n)
// 			curr_sum += a[i];
// 	}

// 	return 0;
// }

// #include<bits/stdc++.h>

// using namespace std;

// int main() {

// 	int n , *a , l = 0 , r = 0 , sum = 0 , g_sum , curr_sum = 0 , i , flag = 0;
// 	cin >> n;

// 	a = new int[n];

// 	for (i = 0; i < n; ++i) {
// 		cin >> a[i];
// 		// sum += a[i];
// 		// cout << sum << endl;
// 	}

// 	cin >> g_sum;

// 	i = 0;
// 	// wrong approach because i keep track of sliding window

// 	// if (g_sum > sum)
// 	// 	cout << "Not Possible" << endl;

// 	// else {

// 	while (l < n && r < n) {

// 		curr_sum += a[r];

// 		// for all -ve numbers the approach is this
// 		// while (g_sum > curr_sum && l < r) --> this condition will give you all subarrays possible but not work for all positive

// 		while (g_sum < curr_sum && l < r) {

// 			curr_sum -= a[l];
// 			cout << curr_sum << endl;
// 			l++;
// 		}

// 		if (g_sum == curr_sum) {

// 			cout << " Given sum is in between " << l << " " << r << endl;
// 			flag = 1;
// 		}

// 		r++;
// 	}

// 	if (!flag)
// 		cout << "Not Possible" << endl;

// 	return 0;
// }

// if all elements are positive and given sum is negative then what we havr to do
// 8
// 15 3 -4 -8 -7 -5 -10 5
// -15


// Another solution using hashmap works for both -ve and +ve numbers
// #include<bits/stdc++.h>

// using namespace std;

// int main() {

// 	unordered_map<int , int> m;

// 	int n , *a , curr_sum = 0 , g_sum , flag = 0;

// 	cin >> n;
// 	a = new int[n];

// 	for (int i = 0; i < n; ++i) {
// 		cin >> a[i];
// 	}
// 	cin >> g_sum;

// 	for (int i = 0; i < n; ++i) {

// 		curr_sum += a[i];

// 		if (curr_sum == g_sum) {
// 			cout << "Sum lie between " << "0" << " " << i << endl;
// 		}

// 		if (m.find(curr_sum - g_sum) != m.end()) {
// 			cout << "Sum lie between " << m[curr_sum - g_sum] + 1 << " " << i << endl;

// 			flag = 1;
// 		}

// 		m[curr_sum] = i;
// 	}

// 	if(!flag)
// 		cout << "Sum not there in the Array" << endl;
// }


// Give Wrong Result for given Test Case
// One of the best case
// Time Complexity :- O(N)
// Space Complexity :- O(1)

// C++ program to check if subarray with sum
// exists when negative elements are also present

#include <bits/stdc++.h>
using namespace std;

// Function to check if subarray with sum
// exists when negative elements are also present
void subArraySum(int arr[], int n, int sum)
{
	int minEle = INT_MAX , l = 0 , r = 0 , flag = 1 , start = 0 , i;

	// Find minimum element in the array
	for (int i = 0; i < n; i++)
		minEle = min(arr[i], minEle);

	// Initialize curr_sum as value of first element
	// and starting point as 0
	int curr_sum = arr[0] + abs(minEle);

	// Starting window length will be 1,
	// For generating new target sum,
	// add abs(minEle) to sum only 1 time
	int targetSum = sum;

	// Add elements one by one to curr_sum
	// and if the curr_sum exceeds the
	// updated sum, then remove starting element
	for (i = 1; i <= n; i++) {

		// If curr_sum exceeds the sum,
		// then remove the starting elements
		while (curr_sum - (i - start) * abs(minEle) > targetSum && start < i) {
			curr_sum = curr_sum - arr[start] - abs(minEle);
			// cout << curr_sum << endl;
			start++;
		}

		// If curr_sum becomes equal to sum, then return true
		if (curr_sum - (i - start) * abs(minEle) == targetSum) {
			cout << "Sum found between indexes " << start << " and " << i - 1;
			return;
		}

		// Add this element to curr_sum
		if (i < n) {
			curr_sum = curr_sum + arr[i] + abs(minEle);
			// cout << curr_sum << endl;
		}
	}

	// If we reach here, then no subarray
	cout << "No subarray found";

	// while (l < n && r < n) {

	// 	curr_sum += a[r];

	// 	while (targetSum < curr_sum - (r - l + 1) * abs(minEle) && l < r) {

	// 		curr_sum -= a[l];
	// 		// cout << curr_sum << endl;
	// 		l++;
	// 	}

	// 	if (targetSum == curr_sum - (r - l + 1) * abs(minEle)) {

	// 		cout << " Given sum is in between " << l << " " << r << endl;
	// 		flag = 1;
	// 	}

	// 	r++;
	// }

	// if (!flag)
	// 	cout << "Not Possible" << endl;
}

// Driver Code
int main()
{
	int arr[] = { 10, -12, -2, 2, -20, 10 };
	int n = sizeof(arr) / sizeof(arr[0]);

	int sum = -10;

	subArraySum(arr, n, sum);

	return 0;
}



