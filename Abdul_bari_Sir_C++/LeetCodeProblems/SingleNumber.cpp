#include<iostream>

using namespace std;

int isSingle(int* a){
        int i=0,j;
        cout<<*(&a+1)-a;
        bool b[sizeof(a)/sizeof(a[0])]={true};
        int n=a[i];
        for(int j=1;j< sizeof(a)/sizeof(a[0]) && b[j] == true;j++){
            if(a[i]==a[j] && b[j] == true){
                b[i]=b[j]=false;
                i++;
                cout<<"l";
            }
            if(b[j])
                return a[j];
        }
        return -1;
}

int main(){

    int a[]={2,2,1,1,1,1,4};
    cout<<isSingle(a);
}