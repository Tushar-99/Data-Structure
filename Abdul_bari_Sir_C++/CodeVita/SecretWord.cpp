#include<bits/stdc++.h>

using namespace std;

int main(){
    string str , word1,word2;
    cin >> str;
    
    int n;
    cin >> n;
    map<string,string> sw;
    map<string,string>::iterator itr;

    for(int i = 0 ; i < n ; i++){
        cin>>word1>>word2;
        sw.insert({word1,word2});
    }

    // for(itr = sw.begin() ; itr!= sw.end() ; ++itr){
    //     cout<<itr->first<<" "<<itr->second<<endl;
    // }
}