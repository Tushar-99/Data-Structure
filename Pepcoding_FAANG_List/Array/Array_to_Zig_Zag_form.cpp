#include<bits/stdc++.h>

using namespace std;

void Zig_Zag_Print(int *arr , int n) {

	bool flag = false;
	// bool flag = true;

	// for true start with small number that is valley peak valley ------
	// for false start with large number that is peak valley peak -------
	for (int i = 0; i < n - 1; ++i) {

		// here if else is only on the basis of flag because flag decides the checking of the array consecutive numbers because if we make consecutive numbers in such a way that it need to change order it must be one at time not both i.e. if not less than then must be greater than so if we go for greater than and swap it result wrong beacuse we only check their order on the basis of flag condition if met swap otherwise do nothing that's why this if statement is wrong

		// if(flag && arr[i] > arr[i + 1])
		//    true			false
		//	  so go to else and in else become true condition and swap which we don't needed

		if (flag) { // expect i < i + 1 if not then swap
			if (arr[i] > arr[i + 1])
				swap(arr[i] , arr[i + 1]);
		}

		else { // expect i > i + 1 if not then swap
			if (arr[i] < arr[i + 1])
				swap(arr[i] , arr[i + 1]);
		}

		flag = !flag;
	}
}

int main() {

	int n , * arr;
	cin >> n;

	arr = new int[n];

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	Zig_Zag_Print(arr , n);

	for (int i = 0; i < n; ++i) {
		cout << arr[i] << " ";
	}
}