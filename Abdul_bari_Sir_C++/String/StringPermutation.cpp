//Note this does not print the array in the lexicographical order 
//this only count all permutuation and print in non lecxi order
//look for youtube videos for best solution
#include<bits/stdc++.h>

using namespace std;

void swap(string &str , int l,int h){

    char temp;
    temp = str[l];
    str[l] = str[h];
    str[h] = temp;

}
 
//static int c = 0;
void permutation(string &str,int l,int h){

    if(l == h){ 
        cout<<str<<endl;
        //c++; 
        return;
    }
    
    for(int i = l ; i < h ; i++){
        swap(str , l , i);
        permutation(str , l + 1 , h);
        swap(str , l , i);
    }
}

int main(){

    string str = "abc";
    permutation(str,0,str.length());
    //cout<<c;
    return 0;
}

// #include<bits/stdc++.h>

// using namespace std;

// void swap(string &str , int l,int h){

//     char temp;
//     temp = str[l];
//     str[l] = str[h];
//     str[h] = temp;

// }
// static int c = 0;
// void permutation(string &str,int l,int h , string target){
    
//     if(l == h && str > target){ 
//         cout<<str<<endl;
//         c++; 
//     }
//     for(int i = l ; i < h ; i++){
//         swap(str,l,i);
//         permutation(str,l+1,h,target);
//         swap(str,l,i);
//     }
// }

// int main(){

//     string str,target;
//     cin >> str >> target;
//     permutation(str,0,str.length(),target);
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;

// #define io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
// int main(){
//     string a;
//     string b;

//     cin>>a;
//     cin>>b;
//     sort(a.begin(),a.end());
//     if(a.length() < b.length()){
//         cout<<"-1";
//     }

//     else{
//         while(stoi(a) <= stoi(b)){
//             next_permutation(a.begin(),a.end());
//         }
//         cout << a;
//     }
// }