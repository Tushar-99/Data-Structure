#include<bits/stdc++.h>

// using namespace std;

// int main() {

// 	int *a , n , curr_sum = 0 , max_sum = INT_MIN , s_i = 0 , e_i = 0 , s_v = 0;

// 	cin >> n;

// 	a = new int[n];

// 	for (int i = 0; i < n; ++i)
// 		cin >> a[i];

// 	for (int i = 0; i < n; ++i) {

// 		// both handle all -ve elements case

// 		// if at this place then all -ve cases still not handled
// 		// if (curr_sum > max_sum)
// 		// 	max_sum = curr_sum;

// 		if (curr_sum > 0)
// 			curr_sum *= a[i];

// 		else {
// 			curr_sum = a[i];
// 			s_v = i;
// 		}

// 		if (curr_sum > max_sum) {
// 			max_sum = curr_sum;
// 			s_i = s_v;
// 			e_i  = i;
// 		}


// 		// curr_sum += a[i];

// 		// if at this place then all -ve cases still not handled
// 		// if (curr_sum < 0)
// 		// 	curr_sum = 0;

// 		// if (curr_sum > max_sum) {
// 		// 	max_sum = curr_sum;
// 		// 	s_i = s_v;
// 		// 	e_i = i;
// 		// }

// 		// if (curr_sum < 0) {
// 		// 	curr_sum = 0;
// 		// 	s_v = i + 1;
// 		// }

// 		// less intutive way
// 		// curr_sum = max(curr_sum + a[i], a[i]);
// 		// max_sum = max(curr_sum, max_sum);
// 	}

// 	// int res = max_sum;

// 	// if (max_sum <= 0)
// 	// 	s_i = e_i;

// 	// else {

// 	// 	for (int i = e_i; i >= 0; --i) {

// 	// 		res -= a[i];
// 	// 		if (res == 0) {
// 	// 			s_i = i;
// 	// 			break;
// 	// 		}
// 	// 	}
// 	// }

// 	cout << max_sum << endl;
// 	cout << s_i << " " << e_i << endl;
// }


// C++ program to find Maximum Product Subarray
#include <bits/stdc++.h>
using namespace std;

/* Returns the product of max product subarray.*/
// int maxSubarrayProduct(int arr[], int n)
// {
// 	// Initializing result
// 	int result = arr[0];

// 	for (int i = 0; i < n; i++)
// 	{
// 		int mul = 1;
// 		// traversing in current subarray
// 		for (int j = i; j < n; j++)
// 		{
// 			// updating result every time
// 			// to keep an eye over the maximum product

// 			mul *= arr[j];
// 			result = max(result, mul);
// 		}
// 		// updating the result for (n-1)th index.
// 		// result = max(result, mul);
// 	}
// 	return result;
// }

// Better Solution

int max_s_p(int *a , int n) {

	int max_p = a[0];
	int min_p = a[0];
	int omax = 1;
	int temp;

	for (int i = 1; i < n; ++i) {

		if (a[i] == 0) {
			max_p = 1;
			min_p = 1;
		}

		else {
			temp = max_p;
			max_p = max(a[i] , max(a[i] * max_p , a[i] * min_p));
			min_p = min(a[i] , min(a[i] * temp , a[i] * min_p));
		}

		if (omax < max_p)
			omax = max_p;
	}

	int maxi = *max_element(a , a + n);

	if (maxi <= 0)
		omax = maxi;

	return omax;
}

// Driver code
int main()
{
	int arr[] = { -20 , -10 , 0 , -5 , 4 , 1 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Maximum Sub array product is "
	     << max_s_p(arr, n);
	return 0;
}

// This code is contributed by yashbeersingh42
