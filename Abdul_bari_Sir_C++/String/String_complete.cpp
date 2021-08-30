//Note here approach i am using is full of error and warning so be aware of using this in the actual programming context

#include<bits/stdc++.h>

using namespace std;

class String{

private:
    int length;
    char const *A;
public:
    String(){
        length = 0;
        A = NULL;
    }

    void setString(char M[]){
        A = M;
    }
    
    int strLength(char M[]){
        length = 0;
        int i;
       for(i = 0 ; M[i] != '\0' ; i++){
           length++;
        }
        return length; 
    }
    
    int countWhiteSpace(){

    }
    int countLetter(){

    }
    //here count Character without space
    int countActualCharacters(){
        
    }
    
    ~String(){
        delete A;
    }
};

int main(){

    // int i;
    // char A[] = "Welcome";//it automatically added '\0' for String
    // //char *B = "Hello";//it automatically added '\0' for String

    // for(i = 0 ; A[i] != '\0' ; i++){
    // }
    // cout<<i;
    String S;
    char C[] = "\0";
    cout<<"Enter a string";
    cin>>C;
    S.setString(C);
    //forget about it. it only calculate the length of the first char only not whole string i.e. after white space get fail to count
    cout<<S.strLength(C);    
}
