// https://www.geeksforgeeks.org/subarraysubstring-vs-subsequence-and-programs-to-generate-them/

// Time Complexity --> O((n * (n + 1) / 2) or O(N ^ 2)
// Space Complexity --> O(1)

// #include<bits/stdc++.h>
// #include<string>

// using namespace std;

// int main() {

// 	int t , *a , N , K ;
// 	string str;
// 	std::vector<string> v;
// 	vector<string>::iterator it;
// 	cin >> t;

// 	while (t--) {

// 		cin >> N >> K;

// 		a = new int[N];

// 		// v.clear();
// 		v.erase(v.begin() , v.end());
// 		for (int i = 0; i < N; ++i) {

// 			cin >> a[i];
// 		}

// 		for (int i = 0; i < N; ++i) { // track start of subarray

// 			for (int j = i; j < N ; ++j) { // track end of subarrray
// 				// track of total possible subarray from that start in one slot
// 				// here various size array is innitiated dependin upon the starting point
// 				str = "";
// 				for (int k = i; k <= j; ++k) { // print individual subarray in that case
// 					str += to_string(a[k]);
// 					cout << a[k] << " ";
// 				}

// 				v.push_back(str);
// 				cout << endl;
// 			}
// 		}

// 		// here std::unique not work because it is only for consecutive duplicates not any duplicate at any random poistion
// 		// it = std::unique(v.begin(), v.end());
// 		// v.resize(std::distance(v.begin() , it));
// 		// v.erase(it , v.end());
// 		// cout << endl;

// 		std::vector<std::string> uniques;
// 		for (std::string name : v) {

// 			if (std::find(uniques.begin() , uniques.end() , name) == uniques.end())
// 				uniques.push_back(name);
// 		}

// 		for (it = uniques.begin(); it != uniques.end(); ++it) {
// 			cout << *it << endl;
// 		}
// 	}
// }

