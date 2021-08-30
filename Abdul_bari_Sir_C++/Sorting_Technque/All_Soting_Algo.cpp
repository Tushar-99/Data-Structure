#include<bits/stdc++.h>

using namespace std;

void swap(int *a,int *b){
    
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

//Bubble Sort--> in this algo we move the highest element in first pass 
void bubbleSort(int *A,int size){

    // int temp , np , n = size-1 , i = 0 , j = 1 ;

    // while(n){
    //     i = 0;
    //     j = 1;
    //     np = n; // important statement --> conveys no. of comparision = no. of swap checking

    //     while(np--){            
        
    //         if(A[i] > A[j]){ // in sorting previous element is smamller than next element
    //             temp = A[i];
    //             A[i] = A[j];
    //             A[j] = temp;
    //         }
    //         i++;
    //         j++;
    //     }
    //     n--;
    // }
//Adaptive --> in every pass we place one element at its correct position but in first any swap is not done this means that no element is in wrong order according to algo so list is already ok then simply retrun without checking for upcoming passes
// Bubble Sort is Adaptive.
    int temp , count = 0;
    bool flag;
    for(int i = 0 ; i < size-1 ; i++){
        flag = true;
        for(int  j = 0 ; j < size-i-1 ; j++){
            if(A[j] > A[j+1]){
                // temp = A[j+1];
                // A[j+1] = A[j];
                // A[j] = temp;
                swap(&A[j] , &A[j+1]);
                flag = false;
            }
            count++;
        }
        if(flag){
            break;
        }
    }
    cout<<count<<endl;
}

//insertionSort

void insertionSort(int *A,int size){

    int temp , j , i;
    for(i = 1 ; i < size ; i++){
        temp = A[i];
        for(j = i-1 ; j >= 0 ; j--){
            if(temp < A[j]){
                A[j+1] = A[j];
            }
            else{
                break;
            }
        }
        A[j+1] = temp;
    }
}

//Selection sort --> in this algo in first pass at 0th index smallest element is come
void selectionSort(int *A,int size){

// more swap based selection sort algo
    // int temp;
    // for(int i = 0 ; i < size-1 ; i++){
    //     for(int j = i+1 ; j < size ; j++){
    //         if(A[i] > A[j]){ // for descending order A[i] < A[j]
    //             temp = A[i]; 
    //             A[i] = A[j];
    //             A[j] = temp;
    //         }
    //     }
    // }

// comparision based 
// two pointer based approach
    int temp , k , j , i;
    for(i = 0 ; i < size-1 ; i++){
        k = i;
        for(j = i+1 ; j < size ; j++){
            if(A[k] > A[j]){ 
                k = j;
            }
        }
        // temp = A[i]; 
        // A[i] = A[k];
        // A[k] = temp;

        swap(&A[k] , &A[i]);
    }
}

int thirdLar(int *A,int len){

    int fl = A[0] , sl = A[0] , tl = A[0];

    for(int i = 1 ; i < len ; i++){
        if(fl < A[i]){
            fl = A[i];
        }
    }
    
    for(int i = 1 ; i < len ; i++){
        if(sl < A[i] && A[i] != fl){
            sl = A[i];
        }
    }
    
    for(int i = 1 ; i < len ; i++){
        if(tl < A[i] && (A[i] != sl && A[i] != fl)){
            tl = A[i];
        }
    }
    return tl;
}

int partitionS(int *A,int l,int h){

    int pivot = A[l];
    int i = l , j = h;

    while(i < j){

        while(A[i] <= pivot) i++;
        while(A[j] > pivot) j--;

        if(i < j)
            swap(&A[i] , &A[j]);
    }
    
    swap(&A[j] , &A[l]);

    return j;
}

void quickSort(int *A,int l,int h){

    int j;

    if(l < h){
        j = partitionS(A , l , h);
        quickSort(A , l , j - 1);
        quickSort(A , j + 1 , h);
    }
}

//when end element is selected as pivot

int partitionExc(int *A , int l , int h){

    int pivot = A[h];
    int i = l , j = h;

    while(i < j){
        while(A[i] < pivot)  i++;  
        while(A[j] >= pivot)   j--; 
        // 8 , 5 , 7 , 11 , 12 , 8 , 9 , 4 , 2 , 5
        if(i < j)
            swap(&A[i] , &A[j]);
    }
    
    swap(&A[h] , &A[i]);
    
    return i;
}

void quickSortEP(int *A,int l,int h){

    int i;

    if(l < h){

        i = partitionExc(A , l , h);
        quickSortEP(A , l , i - 1);
        quickSortEP(A , i + 1 , h);
    }
}

// mid as pivot

int partitionE(int *A , int l , int h){

    int mid = l + (h - l / 2);
    int pivot = A[mid];
    int i = l , j = h;

    while(i < j){
        while(i != h && A[i] <= pivot)  i++;  
        while(j != l && A[j] >= pivot)   j--; 
        // 8 , 5 , 7 , 11 , 12 , 8 , 9 , 4 , 2 , 5
        if(i < j)
            swap(&A[i] , &A[j]);
    }
    
    swap(&A[mid] , &A[i]);
    
    return i;
}

void quickSortMP(int *A,int l,int h){

    int i;

    if(l < h){

        i = partitionE(A , l , h);
        quickSortEP(A , l , i - 1);
        quickSortEP(A , i + 1 , h);
    }
}

int partitionR(int *A , int l , int h){

    srand(time(NULL));
    int rnd = rand() % h + 1;
    int pivot = A[rnd];
    int i = l , j = h;

    while(i < j){
        while(i != h && A[i] <= pivot)  i++;  
        while(j != l && A[j] >= pivot)   j--; 
        // 8 , 5 , 7 , 11 , 12 , 8 , 9 , 4 , 2 , 5
        if(i < j)
            swap(&A[i] , &A[j]);
    }
    
    swap(&A[rnd] , &A[i]);
    
    return i;
}

void quickSortR(int *A,int l,int h){

    int i;

    if(l < h){

        i = partitionR(A , l , h);
        quickSortEP(A , l , i - 1);
        quickSortEP(A , i + 1 , h);
    }
}


// pseudo-random number generator is not truely random number number generator it is based on some formulas

void shuffle(int *A , int s , int e){
    
    srand(time(NULL));
    int i , j ;
    for(int i = e ; i > 0 ; i--){
        //Create one random index
        j = rand() % (i+1);
        swap(&A[i] , &A[j]);
    }
}

//When high is pivot
// int tedhaP(int *A , int l , int h){

//     int pivot = A[h];
//     int partitionIndex = l;
//     int i = l;
//     while(i < h){

//         if(A[i] <= pivot){

//             swap(&A[i] , &A[partitionIndex]);
//             partitionIndex++;
//         }
//         i++;
//     }
//     swap(&A[partitionIndex] , &A[h]);
//     return partitionIndex;
// }

// void quickS(int *A , int l , int h){

//     int partitionIndex;
//     if(l < h){
//         partitionIndex = tedhaP(A , l , h);
//         quickS(A , l , partitionIndex - 1);
//         quickS(A , partitionIndex + 1 , h);
//     }
// }

//When low is pivot
// int tedhaP(int *A , int l , int h){

//     int pivot = A[l];
//     int partitionIndex = h;
//     int i = h;
//     while(i > l){

//         if(A[i] >= pivot){

//             swap(&A[i] , &A[partitionIndex]);
//             partitionIndex--;
//         }
//         i--;
//     }
//     swap(&A[partitionIndex] , &A[l]);
//     return partitionIndex;
// }

// void quickS(int *A , int l , int h){

//     int partitionIndex;
//     if(l < h){
//         partitionIndex = tedhaP(A , l , h);
//         quickS(A , l , partitionIndex - 1);
//         quickS(A , partitionIndex + 1 , h);
//     }
// }

//When mid is pivot
int tedhaP(int *A , int l , int h){

    int mid = l + (h - l / 2);
    int pivot = A[mid];
    int partitionIndex = l;
    int i = l;
    while(i < h){

        if(A[i] < pivot){

            swap(&A[i] , &A[partitionIndex]);
            partitionIndex++;
        }
        i++;
    }
    
    swap(&A[partitionIndex] , &A[mid]);
    return partitionIndex;
}

void quickS(int *A , int l , int h){

    int partitionIndex;
    if(l < h){

        partitionIndex = tedhaP(A , l , h);
        quickS(A , l , partitionIndex - 1); // tail recursion
        quickS(A , partitionIndex + 1 , h);
    }
}

void merge(int *A , int l , int mid , int h){

    int i = l , j = mid + 1 , k = l;
    int B[h + 1];

    while(i <= mid && j <= h) {
        
        if(A[i] < A[j])
            B[k++] = A[i++];

        else 
            B[k++] = A[j++];
        
    }

    while(i <= mid)
        B[k++] = A[i++];
    
    while(j <= h)
        B[k++] = A[j++];

    i = l;
    while(i <= h){
        A[i] = B[i];
        i++;
    }
}

void mergeSort(int *A , int n){

    int i , p , mid , l , h;
    
    for(p = 2 ; p <= n ; p *= 2) { // log[base 2] (n) passes  

        for(i = 0 ; i + p - 1 < n ; i += p){
            
            l = i;
            h = i + p - 1;
            mid = floor(l + (h - l) / 2);

            merge(A , l , mid , h);
        }
    }

    if(p / 2 < n)
        merge(A , 0 , p / 2 - 1 , n);

}

void RmergeSort(int *A , int l , int h){

    if(l < h){
        int mid = (l + h) / 2;
        RmergeSort(A , l , mid);
        RmergeSort(A , mid + 1 , h);
        merge(A , l , mid , h); // post order (traversal) merging
    }
}

// countSort is like count the occurances of the elements in the array which is to be sorted
// linear time taking algorithm but take so much space
void countSort(int *A , int size){

    int max = A[0];
    for(int i = 1 ; i < size ; i++){
        if(A[i] > max)
            max = A[i];
    }

    int B[max + 1];

    for(int i = 0 ; i < max + 1 ; i++)
        B[i] = 0;

    for(int i = 0 ; i < size ; i++)
        B[A[i]]++;

    int j = 0;
    int i = 0;
    // for(int i = 0 ; i < max + 1 ; i++){
        // while(B[i]--)
        //     A[j++] = i;
    while(i < max + 1){

        if(B[i] > 0){
            A[j++] = i;
            B[i]--;
        }

        else
            i++;

    }    
}

int findMax(int *A , int size){

    int max = A[0];
    for(int i = 1 ; i < size ; i++){
        if(A[i] > max)
            max = A[i];
    }

    return max;
}

class Node {

public:
    int data;
    Node *next;

public:
    Node(){
        data = 0;
        next = NULL;
    }
};

void binSort(int *A , int size){

// bin ki value pae ek address para hua hai aur us address pae ek aur address para hua hai
// Bin is array of linked lists
// here no comparision is occur
    Node *temp;
    Node *N;
    int max = findMax(A , size);
    // cout << max << endl;
    Node **Bin = new Node*[max + 1];

    for(int i = 0 ; i < max + 1 ; i++)
        Bin[i] = NULL;
    
    for(int i = 0 ; i < size ; i++){

        cout << i << endl;
        N = new Node();
        N->data = A[i];
        temp = Bin[A[i]];
        cout << Bin[A[i]]->data << endl;
        cout << Bin[A[i]]->next << endl;
        cout << temp << endl;
        if(!temp->next){
            temp->next = N;
            cout << temp->data << endl;
        }

        else {
            while(temp->next){
                cout << temp->data << endl;
                temp = temp->next;
            }
            temp->next = N;
        }
    }

    int j = 0;
    for(int i = 0 ; i < max + 1 ; i++){
        temp = Bin[i]->next;
        while(temp){
            A[j] = temp->data;
            temp = temp->next;
            j++;
        }
    }
}

//Radix Sort

void radixSort(int *A , int size){


}

//shellSort is insertion Sort with gap
// this algo is little bit wrong
void shellSort(int *A , int size){

    int gap = size / 2;
    int j , t;
    while(gap >= 1){
        j = 0;
        while(j < size - 1){

            if(A[j] > A[j + gap])
                swap(&A[j] , &A[j + gap]);
            
            t = j;
            while(2 * t  >= 2 * gap && A[t] < A[t - gap]){
                swap(&A[t] , &A[t - gap]);
                t -= gap;
            }
            j++;
        }
        gap /= 2;
    }
    swap(&A[j + 1] , &A[j]);
}

void shellSortR(int *A , int n){

    int i , j , temp , gap;
    for(gap = n / 2; gap >= 1 ; gap /= 2){

        for(i = gap ; i < n ; i++){

            temp = A[i];
            j = i - gap;
            while(j >= 0 && A[j] > temp){
                A[j + gap] = A[j];
                j -= gap; 
            }
            A[j + gap] = temp;
        }
    }
}

// left sorting --> radixSort , bucketSort

int main(){

    int A[] = {15,2,5,2,7,9,8,23,12,21,45,54,67,76,89,90,101,33,23,66};
    
    int size = sizeof(A) / sizeof(int);

    // shuffle(A , 0 , size - 1);
    // srand(1); --> gives same result every time so we have to initialize it with current time to generate the random no
    // srand(time(NULL));
    // cout << "The no is : " << rand() % 11 << endl; 
    // bubbleSort(A , size - 1);
    // insertionSort(A , size - 1);
    // selectionSort(A , size - 1);
    // cout<<thirdLar(A , size - 1)<<endl;
    // quickSort(A , 0 , size - 1);
    // quickSortEP(A , 0 , size - 1);
    // quickSortMP(A , 0 , size - 1);
    // quickSortR(A , 0 , size - 1);
    // quickS(A , 0 , size - 1);
    // mergeSort(A , 0 ,size - 1); 
    // RmergeSort(A , 0 ,size - 1); 
    // countSort(A , size);
    // binSort(A , size);
    // radixSort(A , size);
    // shellSort(A , size - 1);
    shellSortR(A , size);
    for(int i = 0 ; i < size ; i++)
        cout<<A[i]<<" ";

}