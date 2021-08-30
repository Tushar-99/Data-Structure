#include<bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin >> n;
    long A[130];

    if(n >= 130){
        cout << "Yes";
        return 0;
    }

    for(int i = 0 ; i < n ; i++){
        cin >> A[i];
    }

    if(n < 130){
        for (int i = 0; i < n; i++){
            for (int j = i + 1; j < n; j++){
                for (int k = j + 1; k < n; k++){
                    for (int l = 0; l < n; l++){
                        if(A[i] ^ A[j] ^ A[k] ^ A[l] == 0){
                            cout << "Yes";
                            return 0;
                        }
                    }
                }
            }
        }
    }
    cout << "No";
}

#include <cstdio>
 
#include <cstring>
 
#include <cstdlib>
 
#include <iostream>
 
using namespace std;
 
 
 
const int limit	=	64*2+10;
 
 
 
int main(){
 
	int n;
 	unsigned long long a[limit];
 	cin >> n;
 	if (n>=limit){
 		puts("Yes");
 		return 0;
 	}
 
	for (int i=0;i<n;++i)
 
		cin >> a[i];
 
	for (int i=0;i<n;++i)
 
		for (int j=i+1;j<n;++j)
 
			for (int k=j+1;k<n;++k)
 
				for (int l=k+1;l<n;++l)
 
				if ((a[i]^a[j]^a[k]^a[l])==0){
 
					puts("Yes");
 
					return 0;
 
				}
 
	puts("No");
 
	return 0;
 
} 

// Solution based on binary search
#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
#include<string>
#include<utility>
#include<cassert>
using namespace std;
 
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
 
#define ll long long
#define ull unsigned ll
 
ull A[100000], *A1, *A2;
ull B1[4][3000000], B2[4][3000000]; 
int B1s[4], B2s[4];
 
int main(){
  int i, j, k, l, ok;
  int n, n1, n2, a, b;
  ull x, xx, xxx, xxxx;
 
  assert( scanf("%d",&n)==1 );
  assert(4<=n && n<=100000);
  rep(i,n) assert(scanf("%llu",A+i)==1);
 
  if(n >= 2*(64+2)){ puts("Yes"); return 0; }
 
  n1 = n/2;
  n2 = n-n1;
  A1 = A; A2 = A+n1;
  rep(i,4) B1s[i] = B2s[i] = 0;
 
  rep(i,n1){
    x = A1[i];
    //cout << B1[0][B1s[0]] << "\n";
    B1[0][B1s[0]++] = x;
    //cout << B1[0][B1s[0]] << "\n";
    //cout << B1s[0] << "\n";
    REP(j,i+1,n1){
      xx = x^A1[j];
      B1[1][B1s[1]++] = xx;
      REP(k,j+1,n1){
        xxx = xx^A1[k];
        B1[2][B1s[2]++] = xxx;
        REP(l,k+1,n1){
          xxxx = xxx^A1[l];
          B1[3][B1s[3]++] = xxxx;
        }
      }
    }
  }
//   rep(i,4){
//   	cout << B1s[i] << endl;
//   	rep(j,4){
//   		cout << B1[i][j] << " ";
// 	}
// 	cout << endl;  
//   }
  rep(i,n2){
    x = A2[i];
    B2[0][B2s[0]++] = x;
    REP(j,i+1,n2){
      xx = x^A2[j];
      B2[1][B2s[1]++] = xx;
      REP(k,j+1,n2){
        xxx = xx^A2[k];
        B2[2][B2s[2]++] = xxx;
        REP(l,k+1,n2){
          xxxx = xxx^A2[l];
          B2[3][B2s[3]++] = xxxx;
        }
      }
    }
  }
 
  rep(i,4) sort(B1[i], B1[i]+B1s[i]), sort(B2[i], B2[i]+B2s[i]);
  if(B1s[3] && B1[3][0]==0){ puts("Yes"); return 0; }
  if(B2s[3] && B2[3][0]==0){ puts("Yes"); return 0; }
 
  REP(k,1,4){
    l = 4-k;
    a = b = 0;
    while(a < B1s[k-1] && b < B2s[l-1]){
      if(B1[k-1][a] == B2[l-1][b]){ puts("Yes"); return 0; }
      if(B1[k-1][a] < B2[l-1][b]) a++; else b++;
    }
  }
 
  puts("No");
 
  return 0;
}

// Test Case :- for above case 
// 10
// 5 3 1 8 12 16 10 14 18 25
// 5 10 10 5
// 5 10 10 5

// 5 3 1 8 12 0 0
// 6 4 13 9 2 11 15
// 7 14 10 12 8 1 10
// 15 11 2 0 6 0 0


// 16 10 14 18 25 0 0
// 26 30 2 9 4 24 19
// 20 8 3 12 7 27 22
// 6 13 17 21 15 0 0

// 1 3 5 8 12 0 0
// 2 4 4 6 9 9 11
// 1 5 7 7 8 10 10
// 0 2 6 11 15 0 0


// 10 14 16 18 25 0 0
// 2 4 9 11 19 23 24
// 1 3 5 7 8 12 20
// 6 13 15 17 21 0 0

// Yes


