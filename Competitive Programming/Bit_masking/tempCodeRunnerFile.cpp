#include<bits/stdc++.h>

using namespace std;

int main(){

    bool flag = true;
    int N , cnt = 0 , ind = 0;
    cin >> N;
    int temp = N;
    while(temp){

        int num = temp % 10;
        if(num != 4 && num != 7){
            flag = false;
            break;
        }
        temp /= 10;
        cnt++;
    }

    if(flag){
        
        while(cnt){
            ind += (1 << cnt);
            cnt--;
        }
        cout << ind << endl;
    }
}