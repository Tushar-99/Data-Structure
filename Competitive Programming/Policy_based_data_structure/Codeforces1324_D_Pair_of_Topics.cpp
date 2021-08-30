// #include<iostream>

// using namespace std;

// int main()
// {
//     int *tec , *stu , size;
//     long long int count = 0;

//     cin >> size;
//     tec = new int[size];
//     stu = new int[size];
//     for(int i = 0 ; i < size ; i++)
//         cin >> tec[i];

//     for(int i = 0 ; i < size ; i++)
//         cin >> stu[i];


//     for(int i = 0 ; i < size ; i++)
//     {
//         for(int j = i + 1 ; j < size ; j++)
//         {
//             if(tec[i] + tec[j] > stu[i] + stu[j])
//                 count++;
//         }
//     }
//     cout << count ;
// }

//Improved one using pbds

// #include<iostream>
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp>  

// using namespace std;
// using namespace __gnu_pbds;

// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> new_data_set; 

// int main()
// {
//     int n, count = 0, ans = 0;
//     new_data_set s;

//     int tec[] = { 4, 8, 2, 6, 2 }; 
//     int stu[] = { 4, 5, 4, 1, 3 }; 
//     int c[n] = {0};
//     n = sizeof(tec)/sizeof(int);

//     for(int i = 0 ; i < n ; i++)
//     {
//         c[i] = tec[i] - stu[i];
//         count += s.size() - s.order_of_key(-c[i]);
//         cout << count << " ";
//         s.insert(c[i]);
//     }
//     cout << endl;
//     cout << count ;
// }


// #include<iostream>
// #include<limits.h>
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp>  

// using namespace std;
// using namespace __gnu_pbds;

// typedef tree<pair<int , int> , null_type, less<pair<int , int>>, rb_tree_tag, tree_order_statistics_node_update> new_data_set; 

// int main()
// {
//     int n, temp;
//     new_data_set s;
    
//     cin >> n;
    
//     int *a = new int[n];
//     int *b = new int[n];

//     for(int i = 0 ; i < n ; i++)
//         cin >> a[i];

//     for(int i = 0 ; i < n ; i++)
//         cin >> b[i];

//     long long int count = 0;
//     for(int i = 0 ; i < n ; i++)
//     {
//         temp = a[i] - b[i];
//         count += s.size() - s.order_of_key({-temp,INT_MAX});
//         s.insert({temp,i});
//     }
//     cout << count ;
// }


#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (auto &it : a) cin >> it;
	for (auto &it : b) cin >> it;
	vector<int> c(n);
	for (int i = 0; i < n; ++i) {
		c[i] = a[i] - b[i];
	}
	sort(c.begin(), c.end());
	
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		if (c[i] <= 0) continue;
		int pos = upper_bound(c.begin(), c.end(), -c[i]) - c.begin();
		ans += i - pos;
	}
	
	cout << ans << endl;
	
	return 0;
}