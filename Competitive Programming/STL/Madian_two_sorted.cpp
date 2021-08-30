#include<iostream>

using namespace std;

int main() {

	int n , i , j = 0 , k = 0 , n1 , n2 , res;
	cin >> n;
	int *A = new int[n];
	int *B = new int[n];
	int *C = new int[n + n];
	
    for(i = 0 ; i < n ; i++)
		cin >> A[i];

	for(i = 0 ; i < n ; i++)
		cin >> B[i];
	
    i = 0;
	while(i < n && j < n){

		if(A[i] <= B[j])
            C[k++] = A[i++];

        else if(A[i] > B[j])
            C[k++] = B[j++];
    }
    	
	while(i < n)
        C[k++] = A[i++];

	while(j < n)
    	C[k++] = B[j++];
    
    // for(int i = 0 ; i < n + n ; i++)
    //     cout << C[i] << " ";

    // cout << endl;

    int val = n + n;
    if(val % 2 == 0)
    {
        n1 = val / 2 ;
        // n2 = (val / 2) + 1;
        //cout << C[n1] << " " << C[n2] << endl;
        res = (C[n1] + C[n1 - 1]) / 2;
    }
    else
    {
        n1 = val / 2;
        res = C[n1];
    }
    cout << res;
	return 0;
}