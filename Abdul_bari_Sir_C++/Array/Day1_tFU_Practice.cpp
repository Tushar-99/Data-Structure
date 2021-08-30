#include<iostream>
#include<algorithm>
using namespace std;

int  main(){

    int A[9]={2,5,9,6,3,8,9,7,1};

    int B[9]={0};

    int n;
    //Approach 1--> time O(n) | space O(n) 
    // for(int i=0 ; i < 9 ; i++){
    //     n=A[i];
    //     if(B[n]==0){
    //         B[n]=1;
    //     }else{
    //         cout<<"Duplicate No."<<n;
    //         break;
    //     }
    // }

    //Approach #2 --> time O(nlogn) | space O(1)
    int s=sizeof(A)/sizeof(A[0]);
    sort(A,A+s);

    for(int i=1 ; i < s ; i++){
        if(A[i]==A[i-1]){
             cout<<"Duplicate No."<<A[i];
        }else{
            continue;
        }
    }
    return 0;

    //Aproach #3 --> Optimized one clear many concepts like slow and fast pointer cum two pointer cum tortoise method same as linked list floyd cycle detection

    
}