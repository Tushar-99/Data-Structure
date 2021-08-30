#include<bits/stdc++.h>
#define my_sizeof(type) (char *) (&type + 1) - (char *) (&type);

using namespace std;

int main() {

	// int arr[8] = {10 , 4 , 3 , 9 , 14 , 20 , 44 , 8};

	int n , *arr;
	cin >> n;

	for (int i = 0; i < n; ++i) {

		cin >> arr[i];
	}
	int size = *(&arr + 1) - arr;


	cout << "1" << endl;
	cout << *max_element(arr + 2 , arr + 6) ;

	return 0;
}