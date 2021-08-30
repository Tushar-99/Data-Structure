#include<bits/stdc++.h>

using namespace std;

bool rec_sorted_chk(int a[] , int n , int i) {

	if (n == i)
		return true;

	if (i < n && a[i - 1] > a[i])
		return  false;

	i += 1;
	cout << i << endl;
	return rec_sorted_chk(a , n , i);

}

int main() {

	int a[5] = {4 , 5 , 6 , 7 , 8};

	cout << rec_sorted_chk(a , 5 , 1);
}