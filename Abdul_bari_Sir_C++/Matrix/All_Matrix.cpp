//Note band Mtrix left some cases are done but not all things are ok
#include<bits/stdc++.h>

using namespace std;

class Matrix{

private:
    int *A;
    int n;

public:
    Matrix(){
        n = 2;
        A = new int[n];
    }

    // Matrix(int n){
    //     this->n = n;
    //     A = new int[n];
    // }

    // Matrix(int n){
    //     this->n = n;
    //     A = new int[n*(n+1)/2];
    // }
    
    // Matrix(int n){
    //     this->n = n;
    //     A = new int[3*n-2];
    // }

    // Matrix(int n,int band){
    //     this->n = n;
    //     A = new int[n+(n*(n-1)-(n-band)*(n-band-1))];
    // }

    Matrix(int n){
        this->n = n;
        A = new int[n+(n-1)];
    }

    void setDiagonal(int ,int ,int);
    
    int getDiagonal(int ,int);

    void setLowerTri(int ,int ,int);

    int getLowerTri(int , int);
    
    void setUpperTri(int ,int ,int);

    int getUpperTri(int , int);

    void setSymmetric(int ,int ,int);

    int getSymmetric(int , int);

    void setTriDiagonal(int ,int ,int);

    int getTriDiagonal(int , int);

    void setSqBand(int ,int ,int, int);
    
    int getSqBand(int ,int , int);

    void setToeplitz(int ,int ,int);
    
    int getToeplitz(int ,int);
    
    void diagonalDisplay();
    
    void lowerTriDisplay();
    
    void upperTriDisplay();

    void symmetricDisplay();
    
    void triDiagonalDisplay();

    void sqBandDisplay();

    void toeplitzDisplay();

    ~Matrix()
    {
        delete []A;
    }
};

void Matrix::setDiagonal(int element,int i,int j){

        if (i >= 0 && j >= 0 && i < n && j < n && i == j && element != 0){
            A[i] = element;
        }

        else{
            cout<<"Plz give non zero element with in valid dimension range"<<endl;
            return;
        }
    }
    
int Matrix::getDiagonal(int i ,int j){

    if (i >= 0 && j >= 0 && i < n && j < n && i == j){
        return A[i];
    }

    else if(i != j && i >= 0 && j >= 0 && i < n && j < n){
        return 0;
    }
    return -1;
}

void Matrix::diagonalDisplay(){

    int i , j;
    for(i = 0 ; i < n ; i++){
        for(j = 0 ; j < n ; j++){
            if(i != j){
                cout<<"0 ";
            }
            else{
                cout<<A[i] <<" ";
            }
        }
        cout<<endl;
    }
}

void Matrix::setLowerTri(int element,int i, int j){

    if(i >= j && i >= 0 && j >= 0 && i < n && j < n && element != 0){
        //A[i*(i+1)/2+j] = element;//Row Major
        A[(n*j)-(j*(j-1)/2)+(i-j)] = element;//Column Major
    }
    else{
        cout<<"plz Enter matrix non zero element and with in valid range of Matrix"<<endl;
    }
}

int Matrix::getLowerTri(int i,int j){

        if(i >= j && i >= 0 && j >= 0 && i < n && j < n){
            //return A[i*(i+1)/2+j];//Row Major
            return A[(n*j)-(j*(j-1)/2)+(i-j)];//Column Major
        }
        else if(i < j && i >= 0 && j >= 0 && i < n && j < n){
            return 0;
        }
        else{
            return INT32_MIN;
        }
        
    return INT32_MIN;
}

void Matrix::lowerTriDisplay(){

    int i , j;
    for(i = 0 ; i < n ; i++){
        for(j = 0 ; j < n ; j++){
            if(i < j){
                cout<<"0 ";
            }
            else{
                //cout<<A[i*(i+1)/2+j] <<" ";//Row Major
                cout<<A[(n*j)-(j*(j-1)/2)+(i-j)]<<" ";//Column Major
            }
        }
        cout<<endl;
    }
}

void Matrix::setUpperTri(int element,int i, int j){

    if(i <= j && i >= 0 && j >= 0 && i < n && j < n && element != 0){
        //A[(n*i)-((i-1)*i)/2+(j-i)] = element;
        A[i*(i+1)/2+j] = element;
    }
    else{
        cout<<"plz Enter matrix non zero element and with in valid range of Matrix"<<endl;
    }
}

int Matrix::getUpperTri(int i,int j){

        if(i >= j && i >= 0 && j >= 0 && i < n && j < n){
            //return A[(n*i)-((i-1)*i)/2+(j-i)];
            return A[i*(i+1)/2+j];
        }
        else if(i < j && i >= 0 && j >= 0 && i < n && j < n){
            return 0;
        }
        else{
            return INT32_MIN;
        }
        
    return INT32_MIN;
}

void Matrix::upperTriDisplay(){

    int i , j;
    for(i = 0 ; i < n ; i++){
        for(j = 0 ; j < n ; j++){
            if(i > j){
                cout<<"0 ";
            }
            else{
                //cout<<A[(n*i)-((i-1)*i)/2+(j-i)] <<" ";
                cout<<A[i*(i+1)/2+j]<<" "; 
            }
        }
        cout<<endl;
    }
}

void Matrix::setSymmetric(int element,int i, int j){

    if(i >= j && i >= 0 && j >= 0 && i < n && j < n && element != 0){
        A[i*(i+1)/2+j] = element;//Row Major
        //A[(n*j)-(j*(j-1)/2)+(i-j)] = element;//Column Major
    }
    else{
        cout<<"plz Enter matrix non zero element and with in valid range of Matrix"<<endl;
    }
}

int Matrix::getSymmetric(int i,int j){

        if(i >= j && i >= 0 && j >= 0 && i < n && j < n ){
            return A[i*(i+1)/2+j];//Row Major
            //return A[(n*j)-(j*(j-1)/2)+(i-j)];//Column Major
        }
        else if(i < j && i >= 0 && j >= 0 && i < n && j < n){
            return A[j*(j+1)/2+i];//transpose simply reverse i and j position
        }
        else{
            return INT32_MIN;
        }
        
    return INT32_MIN;
}

void Matrix::symmetricDisplay(){

    int i , j;
    for(i = 0 ; i < n ; i++){
        for(j = 0 ; j < n ; j++){
            if(i < j){
                cout<<A[j*(j+1)/2+i] <<" ";
            }
            else{
                cout<<A[i*(i+1)/2+j] <<" ";//Row Major
                //cout<<A[(n*j)-(j*(j-1)/2)+(i-j)]<<" ";//Column Major
            }
        }
        cout<<endl;
    }
}

void Matrix::setTriDiagonal(int element,int i, int j){

    if(i >= 0 && j >= 0 && i < n && j < n && element != 0){
        
        if(i - j == 0)
            A[n-1+i] = element;
                
        else if(i - j == 1)
            A[j] = element;
                
        else if(i - j == -1 && i < n-1)
            A[2*n-1+i] = element;
        else{
            cout<<"we are trying to optimize memory";
        }
    }
    else{
        cout<<"plz Enter valid range of Matrix"<<endl;
    }
}

int Matrix::getTriDiagonal(int i,int j){

    if(i >= 0 && j >= 0 && i < n && j < n){
        if(i - j == 0)
            return A[n-1+i];
                
        else if(i - j == 1)
            return A[j];
                
        else if(i - j == -1 && i < n-1)
            return A[2*n-1+i];

        else
             return 0;
        
    }        

    return INT32_MIN;
}

void Matrix::triDiagonalDisplay(){

    int i , j;
    for(i = 0 ; i < n ; i++){
        for(j = 0 ; j < n ; j++){
            if(i >= 0 && j >= 0 && i < n && j < n){
                if(i - j == 0)
                    cout<<A[n-1+i]<<" ";
                
                else if(i - j == 1)
                    cout<<A[j]<<" ";
                
                else if(i - j == -1 && i < n-1)
                    cout<<A[2*n-1+i]<<" ";
                
                else
                    cout<<0<<" ";
                       
            }
        }
        cout<<endl;
    }
}

void Matrix::setToeplitz(int element,int i,int j){

    if(i >= 0 && j >=0 && i < n && j < n){
        if(i <= j){
            A[j-i] = element;
        }
        else if(i > j){
            A[n+i-j-1] = element;
        }
        else{
            cout<<"Plz enter valid Range";
        }
    }
    else{
        return ;
    }
}

int Matrix::getToeplitz(int i,int j){

    if(i >= 0 && j >=0 && i < n && j < n){
        if(i <= j){
           return A[j-i];
        }
        else if(i > j){
            return A[n+i-j-1];
        }
        else{
            cout<<"Plz enter valid Range";
            return INT32_MIN;
        }
    }
    else{
        return INT32_MIN;
    }
}

void Matrix::toeplitzDisplay(){

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(i >= 0 && j >=0 && i < n && j < n){
                if(i <= j){
                    cout<<A[j-i]<<" ";
                }
                else if(i > j){
                    cout<<A[n+i-j-1]<<" ";
                }
            }
        }
        cout<<endl;
    }
}

int main(){

    // Matrix *diagonal = new Matrix(5);
    // diagonal->setDiagonal(5,0,0);
    // diagonal->setDiagonal(5,1,1);
    // diagonal->setDiagonal(5,2,2);
    // diagonal->setDiagonal(5,3,3);
    // diagonal->setDiagonal(5,4,4);

    // diagonal->Display(5);

    // Matrix diagonal(5);
    // diagonal.setDiagonal(5,0,0);
    // diagonal.setDiagonal(5,1,1);
    // diagonal.setDiagonal(5,2,2);
    // diagonal.setDiagonal(5,3,3);
    // diagonal.setDiagonal(5,4,4);
    // diagonal.setDiagonal(5,5,5);
    // diagonal.diagonalDisplay();
    // cout<<diagonal.getDiagonal(3,3)<<endl;

    // Matrix lowerTri(5);
    // lowerTri.setLowerTri(1,0,0);
    // lowerTri.setLowerTri(2,1,0);
    // lowerTri.setLowerTri(3,1,1);
    
    // // for(int i = 0 ; i < 6 ; i++){
    // //     for(int j = 0 ; j < 6 ; j++){
    // //         cout<<lowerTri.getLowerTri(i,j)<<endl;
    // //     }
    // // }
    // // //cout<<lowerTri.getLowerTri(i,j)<<endl;
    // //lowerTri.lowerTriDisplay();
    // lowerTri.setLowerTri(4,2,0);
    // lowerTri.setLowerTri(5,2,1);
    // lowerTri.setLowerTri(6,2,2);
    // lowerTri.setLowerTri(7,3,0);
    // lowerTri.setLowerTri(8,3,1);
    // lowerTri.setLowerTri(9,3,2);
    // lowerTri.setLowerTri(10,3,3);
    // lowerTri.setLowerTri(11,4,0);
    // lowerTri.setLowerTri(12,4,1);
    // lowerTri.setLowerTri(13,4,2);
    // lowerTri.setLowerTri(14,4,3);
    // lowerTri.setLowerTri(15,4,4);

    // cout<<lowerTri.getLowerTri(4,3)<<endl;
    // cout<<lowerTri.getLowerTri(3,4)<<endl;
    // cout<<lowerTri.getLowerTri(4,4)<<endl;
    // cout<<lowerTri.getLowerTri(3,2)<<endl;
    // cout<<lowerTri.getLowerTri(5,5)<<endl;
    
    // lowerTri.lowerTriDisplay();

    // Matrix upperTri(5);
    // upperTri.setUpperTri(1,0,0);
    // upperTri.setUpperTri(2,0,1);
    // upperTri.setUpperTri(3,0,2);
    // upperTri.setUpperTri(4,0,3); 
    // upperTri.setUpperTri(5,0,4);
    // upperTri.setUpperTri(6,1,1);
    // upperTri.setUpperTri(7,1,2);
    // upperTri.setUpperTri(8,1,3);
    // upperTri.setUpperTri(9,1,4);
    // upperTri.setUpperTri(10,2,2);
    // upperTri.setUpperTri(11,2,3);
    // upperTri.setUpperTri(12,2,4);
    // upperTri.setUpperTri(13,3,3);
    // upperTri.setUpperTri(14,3,4);
    // upperTri.setUpperTri(15,4,4);

    // cout<<upperTri.getUpperTri(4,3)<<endl;
    // cout<<upperTri.getUpperTri(3,4)<<endl;
    // cout<<upperTri.getUpperTri(4,4)<<endl;
    
    // upperTri.upperTriDisplay();
    
    // int k = 1;
    // Matrix upperTri(5);
    // for(int i = 0 ; i < 5 ; i++){
    //     for(int j = 0 ; j < 5 ; j++){
    //         upperTri.setUpperTri(k++,i,j);
    //     }
    // }
    
    // for(int i = 0 ; i < 5 ; i++){
    //     for(int j = 0 ; j < 5 ; j++){
    //         cout<<upperTri.getUpperTri(i,j)<<endl;
    //     }
    // }
    // upperTri.upperTriDisplay();

//     int k = 1;
//     Matrix symmetric(5);
//     for(int i = 0 ; i < 5 ; i++){
//         for(int j = 0 ; j < 5 ; j++){
//             symmetric.setSymmetric(k++,i,j);
//         }
//     }
    
//     for(int i = 0 ; i < 5 ; i++){
//         for(int j = 0 ; j < 5 ; j++){
//             cout<<symmetric.getSymmetric(i,j)<<endl;
//         }
//     }

//    symmetric.symmetricDisplay();

//     int k = 1;
//     Matrix tridiagonal(5);
//     for(int i = 0 ; i < 5 ; i++){
//         for(int j = 0 ; j < 5 ; j++){
//             tridiagonal.setTriDiagonal(k++,i,j);
//         }
//     }
    
//     for(int i = 0 ; i < 5 ; i++){
//         for(int j = 0 ; j < 5 ; j++){
//             cout<<tridiagonal.getTriDiagonal(i,j)<<endl;
//         }
//     }

//    tridiagonal.triDiagonalDisplay();

//     int band = 3;

    int k = 1;
    Matrix toeplitz(5);
    for(int i = 0 ; i < 5 ; i++){
        for(int j = 0 ; j < 5 ; j++){
            toeplitz.setToeplitz(k++,i,j);
        }
    }
    
    for(int i = 0 ; i < 5 ; i++){
        for(int j = 0 ; j < 5 ; j++){
            cout<<toeplitz.getToeplitz(i,j)<<endl;
        }
    }

   toeplitz.toeplitzDisplay();
}