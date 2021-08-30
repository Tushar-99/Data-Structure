// #include<bits/stdc++.h>

// using namespace std;

// #define ll long

// ll pre[1000005];
// ll res[1000005];
// int main(){

//     ios_base::sync_with_stdio(0);
//     cin.tie(0);

//     int t;
//     cin >> t;

//     while(t--){

//         int n , num;
//         cin >> n;
//         memset(pre , 0 , sizeof(pre));
//         pre[0] = 1;
//         int sum = 0 , i = 0;

//         while(i < n){
//             cin >> num;
//             sum += num;
//             sum %= n;
//             sum = (sum + n) % n;
//             pre[sum]++;
//             res[i] = sum;
//             i++;
//         }

//         for (i = 0; i < n; i++){
//             cout << pre[i] << " ";
//         }
//         cout << endl;
//         for (i = 0; i < n; i++){
//             cout << res[i] << " ";
//         }
        
//         cout << endl;
//         int ans;
//         bool flag = false;
//         for(i = 0 ; i < n ; i++){
//             if(pre[i] > 1){
//                 ans = i;
//                 flag = true;
//                 break;
//             }
//         }

//         int loc2;
//         if(flag){
//             loc2 = ans;
//             i = ans;
//             while(i < n){
//                 if(res[i] == ans){
//                     loc2 = i;
//                     break;
//                 }
//                 i++;
//             }

//             cout << loc2 - ans + 1 << endl;

//             ans++;
//             loc2++;
//             while (ans <= loc2){
//                 cout << ans << " ";
//                 ans++;
//             }

//             cout << endl;
//         }

//         else{
//             cout << "-1";
//         }
//     }
// }

#pragma warning(disable:4996)
#include<stdio.h>
// #include<bits/stdc++.h>

// using namespace std;

int n, P[100010], TC, p1, p2;
long long S;
int main()
{
	int i, a;
	scanf("%d", &TC);
	while (TC--){
		P[0] = 1;
		S = 0;
		scanf("%d", &n);
		for (i = 1; i <= n; i++){
			scanf("%d", &a);
			S += a;
			if (P[S%n]){
                // like fibonacci series
				p1 = P[S%n];    // starting index
				p2 = i;         // ending index 
			}
			P[S%n] = i + 1;
		}
		if (!p2){
			printf("-1\n");
		}
		else{
			printf("%d\n", p2 - p1 + 1);
			for (i = p1; i <= p2; i++)printf("%d ", i);
			printf("\n");
		}
		for (i = 1; i <= n; i++)P[i] = 0;
	}
}