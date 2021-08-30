#include<bits/stdc++.h>

using namespace std;

// int smallOf3Index(int *A , int *B , int *C , int i , int j ,int k){

//     int index;

//     bool c = A[i] < B[j] ? true : false;

//     index = A[i] < B[j] ? i : j;
    
//     if(c)
//         index = A[i] < C[k] ? i : k;

//     else
//         index = B[j] < C[k] ? j : k;

//     return index;
// }

// int *point[2];

void smallOf3(int *A , int *B , int *C , int *i , int *j ,int *k , int **point){

    // int **point = new int*[2];
    bool c = A[*i] < B[*j] ? true : false;

    point[0] = A[*i] < B[*j] ? i : j;
    point[1] = A[*i] < B[*j] ? A : B;
    
    if(c){
        point[0] = A[*i] < C[*k] ? i : k;
        point[1] = A[*i] < C[*k] ? A : C;
    }

    else{
        point[0] = B[*j] < C[*j] ? j : k;
        point[1] = B[*j] < C[*k] ? B : C;
    }

}

void merge(int *A , int *B , int *C , int sizeA , int sizeB , int sizeC , int *fin){

    int i = 0 , j = 0 , k = 0 , l = 0;
    int *arr;
    int **point = new int*[2];

    while(i < sizeA && j < sizeB && k < sizeC){
        
        smallOf3(A , B , C , &i , &j , &k , point);
        arr = point[1];
        fin[l++] = arr[*point[0]];
        (*point[0])++;
    }

    // bool check1 = i != sizeA ? true : false;
    // bool check2 = j != sizeB ? true : false;
    // bool check3 = k != sizeC ? true : false;

    // if()
}

int main(){

    int A[] = {1,8,9,10,12};
    int B[] = {2,4,11,15,20};
    int C[] = {3,5,6,13,16};

    int sizeA = sizeof(A) / sizeof(A[0]);
    int sizeB = sizeof(B) / sizeof(B[0]);
    int sizeC = sizeof(C) / sizeof(C[0]);
    int sizefin = sizeA + sizeB + sizeC;
    int fin[sizefin];

    merge(A , B , C , sizeA , sizeB , sizeC , fin);

    for(int i = 0 ; i < sizefin ; i++)
        cout << fin[i] << " ";
}