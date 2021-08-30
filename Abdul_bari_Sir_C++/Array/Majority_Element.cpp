#include<bits/stdc++.h>

using namespace std;

int main(){

    vector<int> v;
    v.push_back(4);
    v.push_back(3);
    v.push_back(1);
    v.push_back(1);
    v.push_back(3);
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(2);
    v.push_back(1);
    v.push_back(1);
    v.push_back(2);
    v.push_back(1);
    int size = v.size();
    int count = -1;
    for(int i = 0 ; i < size ; i++){
        count = 0; 
        for(int j = 0 ; j < size ; j++){
            if(v[i] == v[j]){
                count++;
            }
        }
        if(count > size/2){
            cout<<v[i];
            break;
        }
    }
    
}