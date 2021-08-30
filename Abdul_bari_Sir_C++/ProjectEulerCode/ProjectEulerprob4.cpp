#include<iostream>

using namespace std;

//================================
//RIGHT approach Time and space may be sucks seek for better approach
//error Segmentation fault
bool isPal(int n){
    // int n1=n%10;
    // int n2=n1%100;
    // int n3=n2/1000;
    // int n4=n3/10000;
    // int n5=n4/100000;
    // int n6=n5/1000000;
    int i,j;
    int A[6]={0};
    for(int i=0;i<6;i++){
        A[i] = n%10;
        n /= 10;
        //A[i]=n/10;
    }

    if(A[0] == A[5]){
        for(i=1,j=4;i < j; i++,j--){
            if(A[i]==A[j]){
                continue;
            }
            else{
                break;
            }
        }
        
        if(i >= j){
            return true;
        }
    }

    return false;
}

bool isPallindrome(int n){
    
    int rev_num = 0,c = n;
    while(c > 0){
        rev_num *= 10 + c % 10;
        c /= 10;
    }

    if(rev_num == n){
        return true; 
    }

    return false;
}

int main(){
    
//    cout<<isPallindrome(9009);
    int max=0;
    int n,n1,n2=999;
    for(n1=999 ; n1 > 100 && n2 > 100 ;n1--){
        n2=999;
        while(n2 >= n1){
            n = n2 * n1;
            if(isPal(n))
            {
                if(max < n)
                    max=n;
                
                //break;
            }
            n2--;
        }
    }
    cout<<max<<endl;
//    cout<<isPal(n);
    return 0;
}