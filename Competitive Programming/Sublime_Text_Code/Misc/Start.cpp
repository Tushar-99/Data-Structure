#include<bits/stdc++.h>

using namespace std;

void bubbleSort(int *A, int size) {

	int temp;
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size - 1 - i ; ++i)
		{
			if (A[j] > A[j + 1]) {
				temp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = temp;
			}
		}
	}
}

int main() {

#ifdef ONLINE_JUDGE
	//for getting input from input.txt
	freopen("inputf.in" , "r", stdin);
	//for wrtiting output to output.txt
	freopen("outputf.in" , "w" , stdout);
#endif

	int count;
	cin >> count;
	int *A = new int[count];
	bubbleSort(A, count);

	for (int i = 0; i < count; ++i)
	{
		cin >> A[i];
	}

	for (int i = 0; i < count; ++i)
	{
		cout >> A[i];
	}

}