//Brute force approach takes more time so seek for optimization

// #include<bits/stdc++.h>

// using namespace std;

// int main(){

//     int n=1,c;

//     for(int i=2 ; i < 100000 ; i++){
//             c=0;
//             n += i;
//             //cout<<n;
//         for(int j=1 ; j < sqrt(n) ; j++){
//             if(n % j == 0){
//                 c+=2;
//             }
//             if(sqrt(n) * sqrt(n) == n)
//                 c--;
//             if(n == j){
//                 break;
//             }
//         }
//         if(c > 500){
//             cout<<c<<endl;
//             cout<<n<<" ";
//             break;
//         }
        
//     }
// }


#include<bits/stdc++.h>

using namespace std;

int NumberOfDivisors(int number) {
    int nod = 0;
    int sqrtnum = (int) sqrt(number);
 
    for(int i = 1; i <= sqrtnum ; i++){
        if(number % i == 0){
            nod += 2;
        }
    }
    
    //Correction if the number is a perfect square
    if (sqrtnum * sqrtnum == number) {
        nod--;
    }
 
    return nod;
}

int main(){

    int number = 0;
    int i = 1;
 
    while(NumberOfDivisors(number) < 500){
        number += i;
        i++;
    }
    
    cout<<number;
}


// #include<bits/stdc++.h>

// using namespace std;

// vector<int> findDivisors(int number) {
    
//     int nod = 0;
//     vector<int> v;
//     int sqrtnum = (int) sqrt(number);
 
//     for(int i = 1; i<= sqrtnum ; i++){
//         if(number % i == 0){
//            cout<<i<<endl;
//            if(number/i == i){
               
//            }
    
//             else    
//                 v.push_back(number/i);
//             // cout << i <<"*" << number/i<<endl;
//             nod += 2;
//         }
//     }
//     //Correction if the number is a perfect square
//     if (sqrtnum * sqrtnum == number) {
//         nod--;
//     }
//     cout <<nod<<endl;
//     return v;
// }

// int main(){

//     int number = 70;

//     vector<int> v; 
//     v = findDivisors(number);
//     sort(v.begin(),v.end());
//     for(int i = 0 ; i < v.size() ; i++){
//         cout<<v[i]<<endl;
//     }
// }pyt 34457