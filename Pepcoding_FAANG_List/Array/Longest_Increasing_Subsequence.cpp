// Approach 1 -> Using Recursion
// (i)  Using Recursion Inside Loop
// Space Complexity -> O(Internal Stack Size) Time Complexity -> O(2 ^ n)

#include<bits/stdc++.h>

using namespace std;

int lis(int arr[] , int n , int *max_ref) {

	if (n == 1)
		return 1;

	int res , m_e = 1;

	for (int i = 0; i < n; ++i) {

		res = lis(arr , i , max_ref);

		if (arr[i - 1] < arr[n - 1] && res + 1 > m_e)
			m_e = res + 1;
	}

	if (*max_ref < m_e)
		*max_ref = m_e;

	return m_e;
}

// (ii) Using Include Exclude Element from array and then Checking
// Space Complexity -> O(Internal Stack Size) Time Complexity -> O(2 ^ n)


/* 1-D DP
  Approach 2-> Using DP Time Complexity -> O(n ^ 2) Space Complexity -> O(n)
*/

int LIS_DP(int *a , int n) {

	int dp[n]  , omax = INT_MIN;
	// memset(dp , 1 , sizeof(dp));

	for (int i = 0; i < n; ++i) {
		dp[i] = 1;
		cout << dp[i] << " " ;
	}

	cout << endl;
	for (int i = 1; i < n; ++i) {

		for (int j = 0; j < i; ++j) {

			if (a[i] > a[j] && dp[i] < dp[j] + 1)
				dp[i] = dp[j] + 1;
		}

		if (dp[i] > omax)
			omax = dp[i];
	}

	for (int i = 0; i < n; ++i) {
		cout << dp[i] << " " ;
	}

	cout << endl;
	return omax;
}

/*
	2-D DP
	Approach 3-> Using DP by implementing LCS(Longest Common Subsequence) Time Complexity -> O(n ^ 2) , Space Complexity -> O(n ^ 2)

*/


/*
	Approach 4-> Using Binary Search Varient
 	Space Complexity -> O(n) Time Complexity -> O(n * log(n))
*/

/*
	Approach 5-> Using Binary Search Varient But also find Elements in LIS
 	Space Complexity -> O(n + n) Time Complexity -> O(n * log(n))
*/

int main() {

	int n , max = 1 , *arr;
	cin >> n;

	arr = new int[n];
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	// int g = lis(arr , n , &max);

	cout << LIS_DP(arr , n);
}
// Java Solution :-
// Bindaas Method Gives LIS + Elements of LIS also in O(n * log(n))
// Other methods are also there which gives only length of LIS not elements
// On top of this approach it is bit difficult but wide application of the Binary
// Search
// This method is tremendous if so then practice it more may help to target another
// varient

// package com.interview.array;

// import java.util.Arrays;

/**
 * Date 08/01/2015
 * @author Tushar Roy
 *
 * Given an array, find longest increasing subsequence in nlogn time complexity
 *
 * References
 * http://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/
 * http://www.geeksforgeeks.org/construction-of-longest-monotonically-increasing-subsequence-n-log-n/
 */
// public class LongestIncreasingSubSequenceOlogNMethod {

//     /**
//      * Returns index in T for ceiling of s
//      */
//     private int ceilIndex(int input[], int T[], int end, int s){
//         int start = 0;
//         int middle;
//         int len = end;
//         while(start <= end){
//             middle = (start + end)/2;
//             if(middle < len && input[T[middle]] < s && s <= input[T[middle+1]]){
//                 return middle+1;
//             }else if(input[T[middle]] < s){
//                 start = middle+1;
//             }else{
//                 end = middle-1;
//             }
//         }
//         return -1;
//     }

//     public int longestIncreasingSubSequence(int input[]){
//         int T[] = new int[input.length];
//         int R[] = new int[input.length];
//         for(int i=0; i < R.length ; i++) {
//             R[i] = -1;
//         }
//         T[0] = 0;
//         int len = 0;
//         for(int i=1; i < input.length; i++){
//             if(input[T[0]] > input[i]){ //if input[i] is less than 0th value of T then replace it there.
//                 T[0] = i;
//             }else if(input[T[len]] < input[i]){ //if input[i] is greater than last value of T then append it in T
//                 len++;
//                 T[len] = i;
//                 R[T[len]] = T[len-1];
//             }else{ //do a binary search to find ceiling of input[i] and put it there.
//                 int index = ceilIndex(input, T, len,input[i]);
//                 T[index] = i;
//                 R[T[index]] = T[index-1];
//             }
//         }

//         //this prints increasing subsequence in reverse order.
//         System.out.print("Longest increasing subsequence ");
//         int index = T[len];
//         while(index != -1) {
//             System.out.print(input[index] + " ");
//             index = R[index];
//         }

//         System.out.println();
//         return len+1;
//     }

//     public static void main(String args[]){
//         //int input[] = {2,5,3,1,2,10,6,7,8};
//         int input[] = {2 , 5 , 3 , 7 , 11 , 9 , 10 , 13 , 6};
//         LongestIncreasingSubSequenceOlogNMethod lis = new LongestIncreasingSubSequenceOlogNMethod();
//         System.out.println("Maximum length " + lis.longestIncreasingSubSequence(input));
//     }
// }