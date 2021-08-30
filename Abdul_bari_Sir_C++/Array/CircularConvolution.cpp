#include<iostream>

using namespace std;

int main(){

    int x_size , h_size ,temp =0 , i , j;
    cout<<"Enter size of array1"<<endl;
    cin >> x_size;
    cout<<"Enter size of array2"<<endl;
    cin >> h_size;
    int padding;
    int *x = new int[x_size];
    int *h = new int[h_size];
   
    cout<<"Enter elements of Array1:"<<endl;
    for(int i = 0 ; i < x_size ; i++){
        cin>>x[i];
    }
    
    cout<<"Enter elements of Array2:"<<endl;
    for(i = 0 ; i < h_size ; i++){
        cin>>h[i];
    }

    if(x_size > h_size){
        padding = x_size;
    }
    else{
        padding = h_size;
    }
    int M[padding][padding] = {0};
    int *y = new int[padding];
    
    if(x_size < h_size){
        for(int i  = x_size ; i < h_size ; i++)
            x[i] = 0;
    } else if(x_size > h_size){
        for(int i  = h_size ; i < x_size ; i++)
            h[i] = 0;
    }
    

    for(i = 0 ; i < padding ; i++){
        M[i][0] = x[i];
    }

    for(j = 0 ; j < padding-1 ; j++){
        temp = M[padding-1][j];
        for(int i = 0 ; i < padding ; i++){
            M[i+1][j+1] = M[i][j];
        }
        M[0][j+1] = temp;
    }

    for(i = 0 ; i < padding ; i++){
        for(int j = 0 ; j < padding ; j++){
            cout << M[i][j] <<" ";
        }
        cout<<endl;
    }
    for(i = 0 ; i < padding ; i++){
        for(j = 0 ; j < padding ; j++){
            y[i] = y[i]+(M[i][j]*h[j]);
        }
    }
    
    for(i = 0 ; i < padding ; i++){
        cout<<y[i]<<endl;
    }

    return 0;
}