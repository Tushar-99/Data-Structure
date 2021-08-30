#include<string.h>
#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

int main(){

    // char str[] = "Hi, I am teaching about strings, in C++";
    // char *ptr;

    // strtok function signature
    // char *strtok (char *str, char *delimiters); --> Splits string into tokens
    // A sequence of calls to this function split str into tokens which are sequences of contiguous characters seperated by any of the characters that are part of delimiters 

    // On a first call , the function expects a C string as argument for str,
    // In subsequent calls the function expects a NULL pointer.
    
    // ptr = strtok(str , " ");
    // cout<<ptr<<endl;
// Documentation recommend we have to call this function again for same string than we have to pass the NULL refernce 
    // ptr = strtok(NULL , " ");
    // cout<<ptr<<endl;

    // ptr = strtok(NULL , " ");
    // cout<<ptr<<endl;
    // In strtok there is a static variable which basically store the state of the string in previous function call
    // while(ptr){
    //     cout<<ptr<<endl;
    //     ptr = strtok(NULL , " ");//NULL as a parameter signifies -> extract strings from the original string
    // }

    // int i = 0;
    // string a = "Tushar";
    // string b = "rhasTs";

    // sort(a.begin(),a.end());
    // sort(b.begin(),b.end());

    // if(a.length() == b.length()){
    //     for(i = 0 ; i < a.length() ; i++){
    //         if(a[i] == b[i])
    //             continue;

    //         else
    //             break;
    //     }
    // }
    //     if(i == a.length())
    //         cout<<"ANAGRAM"<<endl;
    //     else
    //        cout<<"NOT ANAGRAM"<<endl;

    // int *s = new int[256] {0};
    // // char *str2 = new char[256];

    // string str1,str2;
    // // cin>>str1;
    // // cin>>str2;
    // getline(cin,str1);
    // getline(cin,str2);

    // int alen = str1.length();
    // int blen = str2.length();
    // int i = 0;

    // if(alen == blen){
    //     for(;i < str1.length(); i++){
    //         if(str1[i] != 32){
    //             int index = (int) str1[i];
    //             s[index]++;
    //         }
    //     }

    //     for(i = 0 ; i < str1.length(); i++){
    //         if(str2[i] != 32){
    //             int index = (int) str2[i];
    //             s[index]--;
    //         }
    //     }

    //     for(i = 0 ; i < 256; i++){
    //         if(s[i] == 0)
    //             continue;

    //         else
    //             break;
    //     }
    //     if(i == 256)
    //         cout<<"ANAGRAM"<<endl;
    // }
    // else
    //     cout<<"Not ANAGRAM"<<endl;

    // // a.replace(2,4,b);
    // // cout<<a<<endl;

    // vector<string> s;
    // s.push_back("dog");
    // s.push_back("god");
    // s.push_back("cat");
    // s.push_back("tac");
    // s.push_back("listen");
    // s.push_back("silent");
    // s.push_back("act");

    // int len = s.size();
    // unordered_map<string, vector<string>> m;
    // string strp;
    // for(string str : s){
    //     strp = str;
    //     sort(str.begin(),str.end());
    //     m[str].push_back(strp);                
    // }
    
    // for(auto itr = m.begin() ; itr != m.end() ; itr++){
        
    //     for(auto itt : itr->second)
    //         cout<< itt <<" ";

    //     cout<<endl;
    // }

    // vector<string> s;
    // s.push_back("dog");
    // s.push_back("god");
    // s.push_back("cat");
    // s.push_back("tac");
    // s.push_back("listen");
    // s.push_back("silent");
    // s.push_back("act");

    // unordered_map<vector<char> , vector<string>> ump;

    // for(string str : s){
    //     ump 
    // }

    // string s = "Aniket is a Good boy";
    // cout<< s.size();    
    // string s = "Aniket is a Good boy";
    // vector<string> reversed;
    //     bool seen = false;
    //     int j = s.size()-1;
    //     for (int i = s.size()-1; i >= 0; i--) {
    //         if (s[i] != ' ' && !seen) {
    //             seen = true;
    //             j = i;
    //         }
    //         if (s[i] == ' ' && seen) {
    //             reversed.push_back(s.substr(i+1,j-i));
    //             seen = false;
    //         }
    //         else if (i == 0 && seen) {
    //             reversed.push_back(s.substr(i,j-i+1));
    //         }
    //     }
        
    //     string res = "";
    //     for (int i = 0; i < reversed.size(); i++) {
    //         res += reversed[i]+(i == reversed.size()-1 ? "" : " ");
    //     }

    //     cout<<res;

    // string s = "   hello   world";
    // cout<<s.length()<<endl;
    // vector<string> rev;

    // int j = s.length()-1;
    // int i = j;
    // bool seen = false;
    // while(i >= 0){
    //     if(s[i] != ' ' && !seen){
    //         seen = true;
    //         j = i;
    //     }
    //     if(s[i] == ' ' && seen){
    //         rev.push_back(s.substr(i+1,j-i));
    //         seen = false;
    //     }
    //     else if(i == 0 && seen){
    //         rev.push_back(s.substr(i,j-i+1));
    //     }
    //     i--;
    // }

    // string res = "";

    // for(int i = 0 ; i < rev.size() ; i++){
    //     res += rev[i]+(i == rev.size()-1 ? "" : " ");
    // }
    // cout<<res<<" "<<res.length()<<endl;

    // vector<int> nums;
    // int target = 14;
    // nums.push_back(2);
    // nums.push_back(8);
    // nums.push_back(12);
    // nums.push_back(14);
    // nums.push_back(6);
    // vector<int> ans;
    // unordered_map<int , int> mpp;
    // for(int i = 0 ; i < nums.size() ; i++){
    //     if(mpp.find(target - nums[i]) != mpp.end()){
    //         ans.push_back(mpp[target - nums[i]]);
    //         ans.push_back(i);
    //         break;
    //     }
    //     mpp[nums[i]] = i; //insertion of data into key
    // }
    // int i = 0;
    // while(i < ans.size()){
    //     cout<<ans[i]<<" ";
    //     i++;
    // }

    // int a[] = {1,2,3,89,2,1};
    // int size = *(&a + 1) - a;
    // // int size = sizeof(a) / sizeof(a[0]); // galat hai hamesha 1 dega size
    // cout<<size<<endl;
    // sort(a , a+size);
    // for(int i = 0 ; i < size ; i++){
    //     cout<<a[i]<<" ";
    // }

    
    // int i=5,j=10;
    // i=i&=i&=j&&0;
    // cout<<i<<" "<<j<<endl;
    // cout<<i^j;
    // int i=4, j=8;
    // printf("%d, %d, %d\n", i|j&j|i, i|j&j|i, i^j);

    // int a = -1 , b = 0 , c = 1;
    // int z = a||c;
    // int f = b&&a;
    // cout<< z <<" "<< f <<endl;

    // short int i = 0;
    // for(i<=5 && i>=-1; ++i; i>0)
    //     printf("%u,", i);

    int i , res = 0;
    
    int input1 = 1000000000;
    for(i = 1 ; i < input1 ; i++) {

        res = res + i * (input1 - i);
    }
    
    cout<<res;
}

