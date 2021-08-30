#include<bits/stdc++.h>

using namespace std;

int main(){

    int no , temp , val;
    bool flag = false;
    cin >> no;

    if(no < 0)
        cout << "Wrong Input";
    
    else
    {
        val = no;
        temp = no * no;

        while(val != 0 && temp != 0)
        {
            val %= 10;
            temp %= 10;
            
            if(val == temp)
            {
                flag = true;
                val /= 10;
                temp /= 10;
            }
            else
            {
                flag = false;  
                break;
            }
        }

        if(flag)
            cout << "Correct Number";
        
        else
            cout << "Incorrect Number";
    }
}