#include<bits/stdc++.h>

using namespace std;

int main(){

    char C[3][5];
    int i = 0;
    while(i < 3){
        C[i][4] = '.';
    }
    i = 0;
    while(i < 3){ 
        C[i][0] = '#';
    }
    i = 0;
    while(i < 3){
        C[i][1] = '*';
    }

    while(i < 3){
        C[i][2] = '*';
    }

    while(i < 3){
        C[i][3] = '*';
    }

    for(i = 0 ; i < 5 ; i++){

        if(C[0][i] == '#' && C[1][i] == '#' && C[2][i] == '#')
            cout<<"#";
        
        else if(C[0][i] == '.' && C[1][i] == '.' && C[2][i] == '.')
            continue;

        else{
            if(i < 3 && C[0][i] == '*' && C[0][i+1] == '*' && C[0][i+2] == '*'
            && C[1][i] == '*' && C[1][i+1] == '*' && C[1][i+2] == '*'
            && C[2][i] == '*' && C[2][i+1] == '*' && C[2][i+2] == '*'){
                cout<<"E";
                i +=2;
            }

            if(i < 3 && C[0][i] == '*' && C[0][i+1] == '*' && C[0][i+2] == '*'
            && C[1][i] == '*' && C[1][i+1] == '.' && C[1][i+2] == '*'
            && C[2][i] == '*' && C[2][i+1] == '*' && C[2][i+2] == '*'){
                cout<<"O";
                i +=2;
            }

            if(i < 3 && C[0][i] == '*' && C[0][i+1] == '.' && C[0][i+2] == '*'
            && C[1][i] == '*' && C[1][i+1] == '.' && C[1][i+2] == '*'
            && C[2][i] == '*' && C[2][i+1] == '*' && C[2][i+2] == '*'){
                cout<<"U";
                i +=2;
            }

            if(i < 3 && C[0][i] == '*' && C[0][i+1] == '*' && C[0][i+2] == '*'
            && C[1][i] == '.' && C[1][i+1] == '*' && C[1][i+2] == '.'
            && C[2][i] == '*' && C[2][i+1] == '*' && C[2][i+2] == '*'){
                cout<<"I";
                i +=2;
            }

            if(i < 3 && C[0][i] == '.' && C[0][i+1] == '*' && C[0][i+2] == '.'
            && C[1][i] == '*' && C[1][i+1] == '*' && C[1][i+2] == '*'
            && C[2][i] == '*' && C[2][i+1] == '.' && C[2][i+2] == '*'){
                cout<<"A";
                i +=2;
            }             
            
        }
    }
}
    
    