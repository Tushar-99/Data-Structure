//#1 Use Prime factorization approach
//#2 Use basic pattern based approach to find lcm
//#3 Use first find GCD then use formula to find LCM LCM(a,b,c)=a*b*c/gcd(a,b)*gcd(b,c) *gcd(c,a)

#include <bits/stdc++.h> 

using namespace std;  

bool prime[20+1];

bool* sievePrime(int limit){
    //int n=20;
    //bool prime[limit+1];

    memset(prime,true,sizeof(prime));
    for(int i=4 ; i <= limit ; i+=2){
        prime[i]=false;
    }

    for(int i = 3 ; i*i <= limit ; i += 2){

        if(prime[i]){

            for(int j = i*i ; j <= limit ; j += i)
                prime[j]=false;
        }
    }

    prime[0]=prime[1]=false;
    //prime[2]=true;
    for(int i=2 ; i <= limit ; i++){
        if(prime[i]){
            cout<<i<<" ";
        }
    }
    cout<<endl;
    return prime;
}

int findLCM(int x,int y){

    if( x == 0 || y == 0){
        return 0;
    }

    int max = (x > y) ? x : y;
    int n = max;

    for(; max <= x * y; max += n){
        if(max % x == 0 && max % y == 0)
            return  max;
    }

    return -1;   
}

int findArrayLCM(int arr[]){
    //int n1=arr[0];
    int result = arr[0];
    
    for(int i=1 ; i < 20 ; i++){
            result=findLCM(result,arr[i]);
    }

    return result;
}

int findGCD(int x,int y){

    //int num1 , num2;
    if(y == 0)
        return x;
    
    return findGCD(y , x % y);

    // else{
    //     while(y != 0){
    //         x = y;
    //         y = x % y;
    //     }        
    // }    

    // return x;
}


int findLCMNew(int x,int y){
    
    return x * y / findGCD(x , y);
}

int findGCDNew(int x,int y){

    int r=0;
    int min = x < y ? x : y;

    for(int i = min ; i > 0 ; i--){
        if(x % i == 0 && y % i == 0){
            return i;       
        } 
    }
    
    return -1;
}

long long findLCMusingGCD(int A[]){

    long long lcm = A[0];

    for(int i = 1 ; i < 20 ; i++){
        // lcm=A[i-2]*A[i-1]*A[i]/findGCD(A[i-2],A[i-1])*findGCD(A[i-1],A[i])*findGCD(A[i],A[i-2]);

        lcm = lcm*A[i] / findGCD(lcm , A[i]);
    }

    return lcm;
}

int main(){
    // int limit=20;
    // bool* prime=sievePrime(limit);
    // vector<int> v;
    // for(int i=2 ; i <= limit ; i++){
    //     if(prime[i]){
    //         v.push_back(i); 
    //     }
    // }

    // for(int x:v){
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    // for(int i=2 ; i <= 20 ; i++){
    //     if(prime[i]==false)
    //     {
    //         cout<<i<<" ";
    //     }
    // }

    // int A[20]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};

    // cout<<findArrayLCM(A)<<endl;
    //cout<<findLCM(236847,246347)<<endl;
    //cout<<findLCM(23,23)<<endl;
    //cout<<findGCD(2368479091,2463478913)<<endl;//thora slow hai recursion vala

    //cout<<findGCDNew(2368479091,2463478913);//fast hai
    //cout<<findGCDNew(23,23);

    cout<<findLCMNew(65,133)<<endl;

    int A[20] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    cout<<findLCMusingGCD(A);
    return 0;
}