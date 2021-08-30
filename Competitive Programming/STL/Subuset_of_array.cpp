#include<bits/stdc++.h>

using namespace std;

typedef long long int lli;

int main(){

    lli n , *arr; 
    lli sum = 0;
    cin >> n ;
    //arr = new lli[n];
    //for(int i = 0 ; i < n ; i++)
    //    cin >> arr[i];

    lli lim = n / 2;
    lli i;
    for(i = 1 ; i <= lim ; i++)
        sum += i * (n - i + 1);

    sum *= 2;
    if(n % 2 == 1){
        sum += i * (n - i + 1);
        cout << sum;
    }

    else
        cout << sum;
}

// C++ program to calculate sum of lengths of subarrays 
// of distinct elements. 
// #include<bits/stdc++.h> 

// using namespace std;

// int sumoflength(int arr[], int n) 
// { 
// 	unordered_set<int> s; 

// 	int j = 0, ans = 0; 

// 	for (int i=0; i<n; i++) 
// 	{ 
// 		while (j < n && s.find(arr[j]) == s.end()) 
// 		{ 
// 			s.insert(arr[j]); 
// 			j++; 
// 		} 
// 		ans += ((j - i) * (j - i + 1))/2; 
// 		s.erase(arr[i]); 
// 	} 

// 	return ans; 
// } 

// int main() 
// { 
//     int n , *arr , sum = 0;
//     cin >> n ;
//     arr = new int[n];
//     for(int i = 0 ; i < n ; i++)
//         cin >> arr[i];

//     cout << sumoflength(arr , n);
// } 
