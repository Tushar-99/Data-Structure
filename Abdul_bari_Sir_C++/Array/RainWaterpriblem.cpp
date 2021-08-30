#include<bits/stdc++.h>

using namespace std;

int trap(const vector<int> &A) {
    
    int size = A.size();
    int left_Max[size];
    int right_Max[size];
    left_Max[0] = A[0];
    for(int i = 1 ; i < size ; i++){
        left_Max[i] = max(left_Max[i-1],A[i]);
    }
    right_Max[size-1] = A[size-1];
    for(int i = size-2 ; i >= 0 ; i--){
        right_Max[i] = max(right_Max[i+1],A[i]);
    }

    int water = 0;
    for(int i = 0 ; i < size ; i++){
        water += min(left_Max[i],right_Max[i])-A[i];
    }
    return water;
}

int main(){

    vector<int> v;
    v.push_back(4);
    v.push_back(3);
    v.push_back(2);
    v.push_back(1);
    v.push_back(3);
    v.push_back(4);
    // v.push_back(1);
    // v.push_back(3);
    // v.push_back(2);
    // v.push_back(1);
    // v.push_back(1);
    // v.push_back(2);
    // v.push_back(1);
    cout << trap(v);
}