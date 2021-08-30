#include<bits/stdc++.h>

using namespace std;

#define lli long long int

int main(){

    // int N , j;
    // lli ans , A , B , temp , cnt = 0; 
    // cin >> N >> A >> B;
    // int *sub_set = new int[N];

    // for(int i = 0 ; i < N ; i++)
    //     cin >> sub_set[i];

    // for(int i = 1 ; i < (1 << N) ; i++){
    //     temp = i;
    //     j = 0;
    //     ans = 0;
    //     while(temp > 0){

    //         if(temp & 1)
    //             ans += sub_set[j];
            
    //         j++;
    //         temp >>= 1;
    //     }

    //     if(ans >= A && ans <= B)
    //         cnt++;
    // }

    // if(A <= 0 && B >= 0)
    //     cnt++;

    // cout << cnt;

//     int N , j , ans = 0;
//     lli A , B , sum , temp;

//     cin >> N >> A >> B;
//     int n1 = N / 2;
//     int n2 = N - n1;

//     vector<lli> v1 , v2 , ans1 , ans2;

//     for(int i = 0 ; i < n1 ; i++){
//         lli num;
//         cin >> num;
//         v1.push_back(num);
//     }

//     for(int i = 0 ; i < n2 ; i++){
//         lli num;
//         cin >> num;
//         v2.push_back(num);
//     }

//     for(int i = 0 ; i < (1 << n1) ; i++){
//         temp = i;
//         j = 0;
//         sum = 0;
//         while(temp > 0){

//             if(temp & 1)
//                 sum += v1[j];
            
//             j++;
//             temp >>= 1;
//         }

//         ans1.push_back(sum);
//     }

//     for(int i = 0 ; i < (1 << n2) ; i++){
//         temp = i;
//         j = 0;
//         sum = 0;
//         while(temp > 0){

//             if(temp & 1)
//                 sum += v2[j];
            
//             j++;
//             temp >>= 1;
//         }

//         ans2.push_back(sum);
//     }    

//     sort(ans2.begin() , ans2.end());
    
//     for(int i = 0 ; i < ans2.size() ; i++){
//         int st = A - v1[i];
//         int en = B - v1[i];

//         auto it1 = lower_bound(ans2.begin() , ans2.end() , st);
//         auto it2 = upper_bound(ans2.begin() , ans2.end() , en);

//         lli l = it1 - ans2.begin();
//         lli h = it2 - ans2.begin();
//         ans += (h - l);
//     }

//     cout << ans;
// }



#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <map>
#include <list>
#include <stack>

using namespace std;

long long ans=0;
long long a,b;

vector<long long> getSubsets(vector<long long> &s, int start, int siz){
	vector<long long> temp;
	for(int j=0;j<pow(2,siz);++j){
		long long sum=0;
		for(int i=start;i<=start+siz;++i){
			if(j&(1<<(i-start))){
				sum+=s[i];
			}
		}
		temp.push_back(sum);
	}
	return temp;
}
void printv(vector<long long> s){
	for(int i=0;i<s.size();++i){
		cout<<s[i]<<" ";
	}
}

void subsets(vector<long long> &s){
	int n=s.size();
	vector<long long>::iterator low,high;
	vector<long long> left=getSubsets(s,0,n/2);
	vector<long long> right=getSubsets(s,n/2,n&1?n/2+1:n/2);
	sort(right.begin(),right.end());
	for(int i=0;i<left.size();++i){
		low=lower_bound(right.begin(),right.end(),a-left[i]);
		high=upper_bound(right.begin(),right.end(),b-left[i]);
		ans+=(high-right.begin())-(low-right.begin());
	}
}

int main(){
	int n;
	scanf("%d%lld%lld",&n,&a,&b);
	vector<long long> s(n,0);
	for(int i=0;i<n;i++){
		scanf("%lld",&s[i]);
	}
	sort(s.begin(),s.end());
	subsets(s);
	printf("%lld\n",ans);
	return 0;
}