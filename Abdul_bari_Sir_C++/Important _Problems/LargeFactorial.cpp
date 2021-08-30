#include<bits/stdc++.h>

using namespace std;

void lgFact(int n){

    int *arr= new int[100000];
    arr[0] = 1;
    int len = 1;
    int i = 1;
    while(i<=n){

        int rem = 0;
        for(int j = 0 ; j < len ;j++){

            int num = arr[j]*i+rem;
            arr[j] = num%10;
            rem = num/10;
        }
        while(rem != 0){

            arr[len++] = rem % 10;
            rem /= 10;
        }
        i++;
    }

    for(int i = len-1 ; i>=0 ; i--){

        cout << arr[i];
    }
    cout<<endl;
}

int main(){
    int n[20] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    int t = 0;
    while(t < 20){
    
        lgFact(n[t]);
        t++;
    }
}

// #include<bits/stdc++.h>

// using namespace std;

// int main(){
    
//     int t;
//     cin >> t;
    
//     while(t--){
        
//         int n;
//         cin>>n;
//         vector<int> v;
//         v.push_back(1);
//         for(int x = 2 ; x <= n ; x++){
//             int carry = 0;
//             for(int i = 0; i < v.size() ; i++){
//                 int mul = v[i]*x+carry;
//                 v[i] = mul%10;
//                 carry = mul/10;
//             }
        
//             while(carry){
        
//                 v.push_back(carry%10);
//                 carry = carry / 10;
//             }   
//         }
        
//         for(int j = v.size()-1 ; j >=0 ; j--){
//             cout<<v[j]
//         }
//     }
// }

// import java.util.*;
// import java.lang.*;
// import java.io.*;
// class GFG
//  {
//     static String greatProduct(String no, int mul){
        
//         int n = no.length();
//         long carry = 0;
        
//         char arr[] = no.toCharArray();
//         for (int i = n-1; i >= 0; i--){
//             long prod = (int)(arr[i] - '0') * mul;
//             prod += carry;
            
//             carry = prod/10;
//             prod = prod%10;
            
//             arr[i] = (char)(prod + '0');
//         }
        
//         String res = new String(arr);
        
//         if (carry > 0){
//             res = Long.toString(carry) + res;    
//         }
        
//         return res;
//     }
     
// 	public static void main (String[] args) throws IOException
// 	 {
// 	 BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
// 	 int tc = Integer.parseInt(bf.readLine());
	    
// 	    while(tc>0){
	        
// 	        int no = Integer.parseInt(bf.readLine());
	        
// 	        String prod = "1";
// 	        for (int i = no; i >=2; i--){
// 	            prod = greatProduct(prod,i);
// 	        }
	        
// 	        System.out.println(prod);
	        
// 	        tc--;
// 	    }
// 	  bf.close();
// 	 }
// }