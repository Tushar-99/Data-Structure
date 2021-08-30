#include<bits/stdc++.h>

using namespace std;

int main(){

    int t , no , temp;
    cin >> t;

    while(t--){
        cin >> no;

        if(no % 2 == 0){
            for(int i = no ; i > 0 ; i--)
            cout << i << " ";
        }
        else{
            temp = (no / 2) + 1;
            for(int i = no ; i > 0 ; i--){

                if(i == temp)
                    cout << i - 1 << " ";
                
                else if(i == temp - 1)
                    cout << i + 1 << " ";
                    
                else
                    cout << i << " ";
                
            }
        }
        cout << endl;
    }
}