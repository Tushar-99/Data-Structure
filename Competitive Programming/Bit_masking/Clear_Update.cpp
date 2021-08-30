#include<bits/stdc++.h>
#include<stdio.h>
#include<conio.h>

using namespace std;

int main(){

    int N = 1024 , sTemp , M = 21 , i = 2 , j = 6;
    cout << ((N | (M << i)) | (N &((-1 << j + 1) | ((1 << i) - 1)))); 
    getch();
}