// #include<bits/stdc++.h>

// using namespace std;
// void rotate(int wall_size,char &mat[]) 
// { 
//     int row = 0, col = 0; 
//     int prev, curr; 
  
//     while (row < wall_size && col < wall_size) 
//     { 
  
//         if (row + 1 == wall_size || col + 1 == wall_size) 
//             break; 
  
//         // Store the first element of next row, this 
//         // element will replace first element of current 
//         // row 
//         prev = mat[row + 1][col]; 
  
//          /* Move elements of first row from the remaining rows */
//         for (int i = col; i < wall_size; i++) 
//         { 
//             curr = mat[row][i]; 
//             mat[row][i] = prev; 
//             prev = curr; 
//         } 
//         row++; 
  
//         /* Move elements of last column from the remaining columns */
//         for (int i = row; i < wall_size; i++) 
//         { 
//             curr = mat[i][wall_size-1]; 
//             mat[i][wall_size-1] = prev; 
//             prev = curr; 
//         } 
//         wall_size--; 
  
//          /* Move elements of last row from the remaining rows */
//         if (row < wall_size) 
//         { 
//             for (int i = wall_size-1; i >= col; i--) 
//             { 
//                 curr = mat[wall_size-1][i]; 
//                 mat[wall_size-1][i] = prev; 
//                 prev = curr; 
//             } 
//         } 
//         wall_size--; 
  
//         /* Move elements of first column from the remaining rows */
//         if (col < wall_size) 
//         { 
//             for (int i = wall_size-1; i >= row; i--) 
//             { 
//                 curr = mat[i][col]; 
//                 mat[i][col] = prev; 
//                 prev = curr; 
//             } 
//         } 
//         col++; 
//     } 
  
//     for (int i=0; i<wall_size; i++) 
//     { 
//         for (int j=0; j<wall_size; j++) 
//           cout << mat[i][j] << " "; 
//         cout << endl; 
//     } 
// } 

// int main(){

//     int wall_size,count , i, j , final = 0;
//     cin >> wall_size;
//     char wall[wall_size][wall_size];
//     int m = wall_size;

//     for(int i = 0 ; i < wall_size ; i++){
//         for(int j = 0 ; i <wall_size ; i++){
//         cin >> wall[i][j];
//         }
//     }

//     for(i = 0 ; i < wall_size ; i++){
//         for(j = 0 ; i <wall_size ; i++){
//         if(wall[i][j] == 'C'){
//             count++;
//         }
//     } 
//     count = 0;
//     if(i == wall_size && j == wall_size){
//         cout << wall_size;
//     } 
//     else{
//         while(m--){
//             rotate(wall_size,wall);
//             for(i = 0 ; i < wall_size ; i++){
//                 for(j = 0 ; i <wall_size ; i++){
//                     if(wall[i][j] == 'D'){
//                     wall[i][j] = '-';
//                     }
//                 }
//             }
//             for(i = 0 ; i < wall_size ; i++){
//                 for(j = 0 ; i < wall_size ; i++){
//                     if(final < count){
//                         final = count;
//                     }
//                     if(wall[i][j] == 'C'){
//                         count++;
//                         break;
//                     }
//                 }
//             }
//         }   
//     }
//     cout<<final;
// }

// // #include<bits/stdc++.h>

// // using namespace std;

// // int main(){

// //     int wall_size , count = 0 , final;
// //     cin >> wall_size;
// //     char wall[wall_size][wall_size];
// //     for(int i = 0; i <wall_size ; i++){
// //         for(int j = 0 ; j < wall_size ; j++){
// //             cin >> wall[i][j];
// //         }
// //     }
// //     for(int i = 0; i <wall_size ; i++){
// //         for(int j = 0 ; j < wall_size ; j++){
// //             if (wall[i][j] == 'D'){
// //                 count++;
// //             }
// //         }
// //     }

// //     final = floor(sqrt(count));
// //     cout << final;
// // }




// // C++ program to find all subsets of given set. Any 
// // repeated subset is considered only once in the output 
// #include <bits/stdc++.h> 
// using namespace std; 

// // Utility function to split the string using a delim. Refer - 
// // http://stackoverflow.com/questions/236129/split-a-string-in-c 
// vector<string> split(const string &s, char delim) 
// { 
// 	vector<string> elems; 
// 	stringstream ss(s); 
// 	string item; 
// 	while (getline(ss, item, delim)) 
// 		elems.push_back(item); 

// 	return elems; 
// } 

// // Function to find all subsets of given set. Any repeated 
// // subset is considered only once in the output 
// void printPowerSet(int arr[], int n) 
// { 
// 	vector<string> list; 

// 	/* Run counter i from 000..0 to 111..1*/
// 	for (int i = 0; i < (int) pow(2, n); i++) 
// 	{ 
// 		string subset = ""; 

// 		// consider each element in the set 
// 		for (int j = 0; j < n; j++) 
// 		{ 
// 			// Check if jth bit in the i is set. If the bit 
// 			// is set, we consider jth element from set 
// 			if ((i & (1 << j)) != 0) 
// 				subset += to_string(arr[j]) + "|"; 
// 		} 

// 		// if subset is encountered for the first time 
// 		// If we use set<string>, we can directly insert 
// 		if (find(list.begin(), list.end(), subset) == list.end()) 
// 			list.push_back(subset); 
// 	} 

// 	// consider every subset 
// 	for (string subset : list) 
// 	{ 
// 		// split the subset and print its elements 
// 		vector<string> arr = split(subset, '|'); 
// 		for (string str: arr) 
// 			cout << str << " "; 
// 		cout << endl; 
// 	} 
// } 

// // Driver code 
// int main() 
// { 
//     int size;
//     cin >> size;
// 	int arr[size]; 
//     for(int i = 0 ; i < size ; i++){
//         cin>>arr[i];
//     }

// 	printPowerSet(arr, size); 

// 	return 0; 
// } 

// C++ program to print distinct subset sums of 
// a given array. 
#include<bits/stdc++.h> 
using namespace std; 

// Uses Dynamic Programming to find distinct 
// subset sums 
void printDistSum(int arr[], int n) 
{ 
	int sum = 0; 
	for (int i=0; i<n; i++) 
		sum += arr[i]; 

	// dp[i][j] would be true if arr[0..i-1] has 
	// a subset with sum equal to j. 
	bool dp[n+1][sum+1]; 
	memset(dp, 0, sizeof(dp)); 

	// There is always a subset with 0 sum 
	for (int i=0; i<=n; i++) 
		dp[i][0] = true; 

	// Fill dp[][] in bottom up manner 
	for (int i=1; i<=n; i++) 
	{ 
		dp[i][arr[i-1]] = true; 
		for (int j=1; j<=sum; j++) 
		{ 
			// Sums that were achievable 
			// without current array element 
			if (dp[i-1][j] == true) 
			{ 
				dp[i][j] = true; 
				dp[i][j + arr[i-1]] = true; 
			} 
		} 
	} 

	// Print last row elements 
	for (int j=0; j<=sum; j++) 
		if (dp[n][j]==true) 
			cout << j << " "; 
} 


// Driver code 
int main() 
{ 
	int arr[] = {2, 3, 4, 5, 6}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	printDistSum(arr, n); 
	return 0; 
} 

