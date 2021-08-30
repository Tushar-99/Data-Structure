//Wrong Code but don't Worry
// #include<bits/stdc++.h>

// using namespace std;

// void swap(int *arr, int i, int j){

//     int temp = arr[i];
//     arr[i] = arr[j];
//     arr[j] = temp;
// }

// int main(){

//     int n , k , maxIn = 0 , count = 0;
//     map<int , int , greater<int>> m;
//     cin >> n >> k;

//     int *perm = new int[n];

//     for(int i = 0 ; i < n ; i++)
//         cin >> perm[i];

//     int *temp = perm;

//     for(int i = 0 ; i < n ; i++)
//         m[perm[i]] = i;
    
//     sort(temp , temp + n , greater<int>());

//     for(int i = 0 ; i < n ; i++){

//         if(perm[i] == temp[i])
//             continue;

//         else if(count < k){
            
//             int init = perm[i];
//             swap(perm , i , m[temp[i]]);
//             m[init] = m[temp[i]];
//             m[temp[i]] = i;
//             count++;
//         }
        
//         else
//             break;
//     }

//     for(int i = 0 ; i < n ; i++)
//         cout << perm[i] << " ";
// }


// #include <bits/stdc++.h> 
// using namespace std; 

// // Function returns the minimum number 
// // of swaps required to sort the array 
// // This method is taken from below post 
// // https:// www.geeksforgeeks.org/ 
// // minimum-number-swaps-required-sort-array/ 
// int minSwapsToSort(int arr[], int n) 
// { 
// 	// Create an array of pairs where first 
// 	// element is array element and second 
// 	// element is position of first element 
// 	pair<int, int> arrPos[n]; 
// 	for (int i = 0; i < n; i++) { 
// 		arrPos[i].first = arr[i]; 
// 		arrPos[i].second = i; 
// 	} 

// 	// Sort the array by array element 
// 	// values to get right position of 
// 	// every element as second 
// 	// element of pair. 
// 	sort(arrPos, arrPos + n); 

// 	// To keep track of visited elements. 
// 	// Initialize all elements as not 
// 	// visited or false. 
// 	vector<bool> vis(n, false); 

// 	// Initialize result 
// 	int ans = 0; 

// 	// Traverse array elements 
// 	for (int i = 0; i < n; i++) { 
// 		// Already swapped and corrected or 
// 		// already present at correct pos 
// 		if (vis[i] || arrPos[i].second == i) 
// 			continue; 

// 		// Find out the number of node in 
// 		// this cycle and add in ans 
// 		int cycle_size = 0; 
// 		int j = i; 
// 		while (!vis[j]) { 
// 			vis[j] = 1; 

// 			// move to next node 
// 			j = arrPos[j].second; 
// 			cycle_size++; 
// 		} 

// 		// Update answer by adding current 
// 		// cycle. 
// 		ans += (cycle_size - 1); 
// 	} 

// 	// Return result 
// 	return ans; 
// } 

// // method returns minimum number of 
// // swap to make array B same as array A 
// int minSwapToMakeArraySame( 
// 	int a[], int b[], int n) 
// { 
// 	// Map to store position of elements 
// 	// in array B we basically store 
// 	// element to index mapping. 
// 	map<int, int> mp; 
// 	for (int i = 0; i < n; i++) 
// 		mp[b[i]] = i; 

// 	// now we're storing position of array 
// 	// A elements in array B. 
// 	for (int i = 0; i < n; i++) 
// 		b[i] = mp[a[i]]; 

// 	/* We can uncomment this section to 
// 	print modified b array 
// 	for (int i = 0; i < N; i++) 
// 		cout << b[i] << " "; 
// 	cout << endl; */

// 	// Returing minimum swap for sorting 
// 	// in modified array B as final answer 
// 	return minSwapsToSort(b, n); 
// } 

// // Function to calculate largest 
// // permutation after atmost K swaps 
// void KswapPermutation(int arr[], int n, int k){
     
// 	int a[n]; 

// 	// copy the array 
// 	for (int i = 0; i < n; i++) 
// 		a[i] = arr[i]; 

// 	// Sort the array in descending order 
// 	sort(arr, arr + n, greater<int>()); 

// 	// generate permutation in lexicographically 
// 	// decreasing order. 
// 	do { 
// 		// copy the array 
// 		int a1[n], b1[n]; 
// 		for (int i = 0; i < n; i++) { 
// 			a1[i] = arr[i]; 
// 			b1[i] = a[i]; 
// 		} 

// 		// Check if it can be made same in k steps 
// 		if ( 
// 			minSwapToMakeArraySame( 
// 				a1, b1, n) 
// 			<= k) { 
// 			// Print the array 
// 			for (int i = 0; i < n; i++) 
// 				cout << arr[i] << " "; 
// 			break; 
// 		} 

// 		// move to previous permutation 
// 	} while (prev_permutation(arr, arr + n)); 
// } 

// int main() 
// { 
//     int n , k , maxIn = 0 , count = 0;
//     cin >> n >> k;

//     int *perm = new int[n];

//     for(int i = 0 ; i < n ; i++)
//         cin >> perm[i];

// 	KswapPermutation(perm , n , k); 
// 	return 0; 
// } 


// Efficient One

#include<bits/stdc++.h>

using namespace std;

int main(){

	int n , k;
	cin >> n >> k;

	int *perm = new int[n];
	int *pos = new int[n + 1];

	for(int i = 0 ; i < n ; i++)
		cin >> perm[i];

	for(int i = 0 ; i < n ; i++)
		pos[perm[i]] = i;

	for(int i = 0 ; i < n && k ; i++){

		if(perm[i] == n - i)
			continue;

		int temp = pos[n - i];

		pos[perm[i]] = pos[n - i];
		pos[n - i] = i;

		swap(perm[temp] , perm[i]);
		--k;
	}

	for(int i = 0 ; i < n ; i++)
		cout << perm[i] << " ";	
}

// #include <iostream>
// #include <vector>
// typedef long long ll;
// using namespace std;
// void print(vector<ll> v){
//     for(ll i:v){
//         cout<<i<<" ";
//     }
// }
// int main() {
//     ll n,k;
//     cin>>n>>k;
//     vector<ll> v(n);
//     for(ll i=0;i<n;i++)
//     {
//         cin>>v[i];
//     }
//     if(n==1){
//         print(v);
//         return 0;
//     }

//     while(k--){
        
//         ll i=n-2,maxRight=-1,maxRightIdx=-1;
//         //STEP 1 : find the index of right size maximum element such that arr[i]<arr[i+1]
//         while(i>=0){
//             if(v[i]<v[i+1] && v[i+1]>maxRight){
//                 maxRight = v[i+1];
//                 maxRightIdx = i+1;
//             }
//             i--;
//         }
//         if(maxRightIdx==-1){
//             // already maxForm
//             print(v);
//             return 0;
//         }
//         //STEP 2 : Now find the first element from left<=maxItem;
//         i=0;
//         while(i<n){
//             if(v[i]<=maxRight){
//                 break;
//             }
//             i++;
//         }
//         // STEP 3: swap
//         swap(v[i], v[maxRightIdx]);
//     }
//     print(v);
//     return 0;
// }

// #include <iostream>
// #include <vector>
// #include <queue>
// #include <unordered_map>
// using namespace std;
// typedef long long int ll;

// int main() {
//     ll n,k;
//     cin>>n>>k;
//     vector<ll> v(n);
//     for(ll i=0;i<n;i++){
//         cin>>v[i];
//     }
//     unordered_map<ll,ll> u_map;
//   	// I am using map beacuse I want to update the indices of items, which I cant do in heap
//     priority_queue<ll> pq;
//   	// using for taking Right side maximum item in constant time.

//   	// Storing the index as value in Map and also pushing the items to priority Queue 
//     for(ll i=0;i<n;i++){
//         u_map[v[i]]=i;// index as value
//         pq.push(v[i]);// Heap
//     }

//     for(ll i=0;i<n;i++){
//         if(pq.top()!=v[i]){
//             k--; // decrement the K whenever 1 operation performed
//             ll index_swap = u_map[pq.top()]; 
//           	// take the maximum items index from where current item has be swapped
//             swap(v[i],v[index_swap]);
//           	// also update the index of swapped item.
//             u_map[v[index_swap]] = index_swap;
//         }
//         pq.pop(); 
//       	// If number of swaps done before array finishes, stop the loop.
//         if(k==0){
//             break;
//         }
//     }
//     for(ll item:v){
//         cout<<item<<" ";
//     }

// }