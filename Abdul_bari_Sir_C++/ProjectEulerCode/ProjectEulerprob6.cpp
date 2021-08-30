#include<bits/stdc++.h>

using namespace std;

long long findPower(int n, int p=2){

    return n*n;

//Binary Exponentiation not required here because is fixed but no in varying    
    // if(p == 0)
    //     return 1;

    // if(n % 2 == 0)
    //     return findPower(n*n,p/2);
    
    // else
    //     return n*findPower(n*n,p-1/2);
    
    // return -1;

}

int main(){
    int sumsquare=0;
    int squaresum=0;
    // for(int i = 1 ; i <= 100 ; i++){
    //     sumsquare+=i;
    // }
    // sumsquare*=sumsquare;
    // cout<<sumsquare;

    //==========================
    //use this approach also
    int n=100000;
    sumsquare=(n*(n+1)/2)*(n*(n+1)/2); // this is equivalent to sum of cubes
    cout<<sumsquare<<endl;

    squaresum=n*(n+1)*(2*n+1)/6;
    cout<<squaresum<<endl;

    cout<<sumsquare-squaresum;
}

// Java

// class SumSqDiff {

// 	public static void main(String arg[]) {

// 		int limit = 100, sumN = 0, sumN2 = 0; 
// 		for(int i = 1; i <= limit; i++) {
			
// 			sumN += i;
// 			sumN2 += i*i;

// 		}
		
// 		int diff = (sumN* sumN) - sumN2;
		
// 		System.out.println("======== difference is ========== " + diff);
	
// 	}

// }