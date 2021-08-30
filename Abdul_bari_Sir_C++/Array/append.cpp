#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct Array {
    int A[10];
    int size;
    int length;
};
//static struct Array arr={{20,3,4,5,6},10,5};
void Display(struct Array arr)
{
    int i;
    for(i=0;i<arr.length;i++)
    {
        cout<<arr.A[i]<<" ";
    }
    cout<<endl;
}

void Append(struct Array *arr,int x)
{
    if(arr->length<arr->size) {
        arr->A[arr->length++]=x;
 //       arr->length++;
    } 
}

void Insert(struct Array *arr,int index,int x)
{
    if(arr->size == arr->length){
        cout<<"Hey bro array is full";
        return ;
    }
    int i;
    if(index<arr->size && index>=0)
    {
        for(i=arr->length;i>index;i--)
        {
            arr->A[i]=arr->A[i-1];
        }
            arr->A[index]=x;
//            arr->length++;
        if(index>arr->length)
        {
            for(i=arr->length;i<index+1;i++)
            {    
                arr->length++;
            }
        }
        else
        {
            arr->length++;
        }
        
    }
}

void Delete(struct Array *arr,int index)
{
    if(arr->length<index)
    {
        cout<<"Bhai kya delete karna chata hai";
        return ;
    }
    else
    {
        for(int i=index;i<arr->length;i++)
        {
            arr->A[i]=arr->A[i+1];
        }
        arr->length--;
    }    
}

int Search(struct Array arr,int key)
{
    for(int i=0;i<arr.length;i++)
    {
        if(arr.A[i]==key)
        {
            return i;
        }
    }
    return -1;
}

void swap(int *x,int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

//tranposition
int Searchimp(struct Array *arr,int key)
{
    for(int i=0;i<arr->length;i++)
    {
        if(arr->A[i]==key)
        {
            swap(&arr->A[i],&arr->A[i-1]);
//            Display(*arr);
            return i-1;
        }
    }
    return -1; 
}

int Searchi(struct Array *arr,int key)
{
    for(int i=0;i<arr->length;i++)
    {
        if(arr->A[i]==key)
        {
            swap(&arr->A[i],&arr->A[0]);
            return 0;
        }   
    }
    return -1;
}

int BinaryS(struct Array arr,int key)
{
    int mid,l=0,h=arr.length-1;
    while(l<=h)
    {
        mid=(l+h)/2;
        if(key==arr.A[mid])
            return mid;

        else if(arr.A[mid]>key)
            h=mid-1;
        else if(arr.A[mid]<key)
        {
            l=mid+1;
        }
        else
        {
            return -1;
        }
        
    }
    return -1;
}

int get(Array arr,int index){

    int* A=new int[arr.length+1];
    A[0]=0;
    for(int i=0 ; i < arr.length ; i++){
        A[i+1]=arr.A[i];
    }
     if(index>0 && index <= arr.length)
        return A[index];
    //linear search
    // for(int i=0 ; i < arr.length ; i++){
    //     if(arr.A[i] == index){
    //         return i;
    //     }
    return -1;
}

Array setIndex(int value,int index,Array arr){
    
    // if(index > arr.size){
    //     cout<<"Buddy Array Filled";
    // }
    //      OR
    //This case is also used
    // if(arr.size == arr.length){
    //     cout<<"Buddy Array Filled";
    // }
    if (index < arr.size && index >= 0){
            if(index < arr.length){
                for(int i= arr.length-1; i >= index ; i--){      
                     arr.A[i+1]=arr.A[i];
                }
                arr.A[index]=value;
                arr.length++;
            }else{
                arr.A[index]=value;
                arr.length++;
            }
    }

    return arr;
}

int findMin(Array arr){
    int min=arr.A[0];
    for(int i=1;i<arr.length;i++){
        if(arr.A[i]<min){
            min=arr.A[i];
        }
    }
    return min;
}    

int findMax(Array arr){
    int max=arr.A[0];
    for(int i=1;i<arr.length;i++){
        if(arr.A[i]>max){
            max=arr.A[i];
        }
    }
    return max;
}    

float findSum(Array arr){
    int sum=0;

    // for(int i=0;i<arr.length;i++){
    //     sum+=arr.A[i];
    // }
    //return sum;

    for(int i=0,j=arr.length-1;i<=j && i < arr.length && j>=0;i++,j--){
            if(i == j)
                sum+=arr.A[i];
            else
                sum+=arr.A[i]+arr.A[j];
    }
    return sum;
}

float recSum(Array arr,int n){
    if(n<0){
        return 0;
    }
    else
        return recSum(arr,n-1)+arr.A[n];

    //return recSum(arr,n-1)+arr.A[n]/(arr.length);
    return 0;
}

float findAvg(Array arr){
    float sum = (float) findSum(arr);

    return sum/arr.length;
}

void Display(int B[])
{
    int i;
    for(i=0;i<14;i++)
    {
        cout<<B[i]<<" ";
    }
    cout<<endl;
}

void revFun(Array arr){

    int* B=new int[arr.length];
    for(int i=arr.length-1 ,j=0; i>=arr.length;i--,j++){//code to reverse Array 
        B[j]=arr.A[i];
    }
    for(int i=0; i<arr.length;i++){ // Code to copy again into Array
        arr.A[i]=B[i];
    }
    Display(B);
    Display(arr);
    //return B;
}

void revRevag(Array arr){
    int temp;
    for(int i=0 ,j=arr.length-1; i <  j ; i++ , j--){
        temp=arr.A[i];
        arr.A[i]=arr.A[j];
        arr.A[j]=temp;
    }
    Display(arr);
}


void LS(Array arr , int n){
    int j=arr.length-1;
    int maxshift = n;
    while(maxshift > 0){

        for(int i = 1 ; i < arr.length ; i++ ){
            arr.A[i-1]=arr.A[i];
        }
        maxshift--;
    }

    while(n > 0){
        arr.A[j] = 0;
        n--;
        j--;
    }
    Display(arr);
}

//Left shift and Right Shift mae panga par raha hai n ki value ka iski wajah se address dikha raha hai

void RS(Array arr,int n){
    int j=0;
    int maxshift = n;
    while(maxshift > 0){

        for(int i = arr.length-1; i >=0 ; i--){
            arr.A[i]=arr.A[i-1];
        }
        maxshift--;
    }

    while(n > 0){
        arr.A[j]=0;
        n--;
        j++;
    }
    Display(arr);
}
// LR --> Clockwise
// RR --> Anticlockwise
void LR(Array arr,int n){
    int temp , j = arr.length-1;
    while(n > 0){

        temp=arr.A[0];
        for(int i = 1 ; i < arr.length ; i++){
            arr.A[i-1]=arr.A[i];
        }
        arr.A[j]=temp;
        n--;
    }
    Display(arr);
}

void RR(Array arr,int n){
    int temp , j = 0;
    
    while(n > 0){

        temp=arr.A[arr.length-1];
        for(int i = arr.length-1; i >= 0 ; i--){
            arr.A[i] = arr.A[i-1];
        }
        arr.A[j]=temp;
        n--;
    }
    Display(arr);
}

//fail to put no less than first index of array

bool insSorted(Array arr,int no){
    int n=sizeof(arr.A)/sizeof(arr.A[0]);
    int i;
    if(arr.size == arr.length)
        return false;

    else{
        for(i = arr.length-1 ; i >= 0; i--){
            arr.A[i+1]=arr.A[i];

            if(arr.A[i] < no){
                arr.A[i+1] = no;
                arr.length++;
                break;
            }
        }
    }
    // arr.A[i+1] = no;
    // arr.length++;
    Display(arr);
    return true;
}

//Another method to element in sorted array have good response
bool insSort(Array arr,int no){
    int i = arr.length-1;
    
    if(arr.size == arr.length)
        return false;

    else{
        while(arr.A[i] > no && i >= 0){
        
            arr.A[i+1]=arr.A[i];
            i--;
        }
        arr.A[i+1] = no;
        arr.length++;
    }
    Display(arr);
    return true;
}

//Wrong Approach

// bool insSorttry(Array arr,int no){

//     int i = 0;
//     int j=arr.length-1;
//     if(arr.size == arr.length)
//         return false;

//     else{
//         while(arr.A[i] < no){
//             arr.A[j+1] = arr.A[j];
//             j--;
//             i++;
//         }
//     }

//     return true;
// }

bool isSorted(Array arr){
    int i;
    for(int i = 1 ; i < arr.length ;i++){
        if(arr.A[i-1] > arr.A[i])
            return false;
    }
    return true;
}

void negLeft(Array arr){

    int i = 0 , j = arr.length-1;

//Give Wrong Result in case when 0 is in array

    // while(i < j){
        
    //     if(arr.A[j] > 0)
    //         j--;

    //     if(arr.A[i] < 0)
    //         i++;
    
    //     if(arr.A[j] <= 0 && arr.A[i] > 0){
    //         swap(arr.A[i] , arr.A[j]);
    //         i++;
    //         j--;
    //     }
    // }

    while(1){
        
        while(arr.A[i] < 0 && i < j)     { i++; }
        while(arr.A[j] >= 0 && i < j)    { j--; }
        if(i < j){
            swap(arr.A[i] , arr.A[j]);
            i++;
            j--;
        }
        else
            break;
    }
    Display(arr);
}

void moveallZerosRight(Array arr){

    int pos=0;
    for(int i = 0 ; i < arr.length ; i++){

        if(arr.A[i] != 0){
            arr.A[pos] = arr.A[i];
            pos++;
        }
    }
    while(pos <  arr.length)
    { 
        arr.A[pos]=0;
        pos++;
    }
    Display(arr);
}

void moveallZerosLeft(Array arr){

    int pos = arr.length-1;

    for(int i = arr.length-1 ; i >= 0 ; i--){

        if(arr.A[i] != 0){
            arr.A[pos] = arr.A[i];
            pos--;
        }
    }
    while(pos >= 0){
        arr.A[pos] = 0;
        pos--;
    }
    Display(arr);
}

void setoperartionUnion(int *A , int *B , int n1 , int n2){

    int C[n1+n2]={};
    int j , no = n1;
    for(int i = 0 ; i < n1 ; i++){
        C[i]=A[i];
    }

    for(int i = 0 ; i < n2 ; i++){
        for( j = 0; j < n1+i ; j++){
            if(C[j] == B[i])
                break;
        }
        if(j == n1+i) {
            C[no]=B[i];
            no++;
        }
    }

    for(int i = 0 ; i < n1+n2 ; i++){
        cout<<C[i]<<" ";
    }
    cout<<endl;
}

//Merge Sort
//Here one thing is good to know how to tackle 
void unionSort(int *A , int *B , int n1 , int n2){

    sort(A,A+n1);
    sort(B,B+n2);

    int i = 0 , j = 0 , k = 0;
    int C[n1+n2] = {};
    while(i < n1 && j < n2){
        if(A[i] < B[j])
            C[k++] = A[i++];

        if(A[i] > B[j])
            C[k++] = B[j++];

        if(A[i] == B[j]){
            C[k++] = B[j++];
            i++;
        }
    }
    while(i < n1){
            C[k++] = A[i++];
    }

    while(j < n2){
        C[k++] = B[j++];
    }

    for(int l = 0 ; l < n1+n2 ; l++){
        cout<<C[l]<<" ";
    }
}

void setIntersection(int *A, int *B, int n1,int n2){

    int k = 0;
    int C[n1+n2] = {};
    for(int i = 0 ; i < n1 ; i++){
        for(int j = 0 ; j < n2 ; j++){
            if(A[i] == B[j]){
                C[k] = A[i];
                k++;
            }
        } 
    }
    for(int i = 0 ; i < n1+n2 ; i++){
        cout<<C[i];
    }
}

//Two Pointer Approach

void setIntersectionSort(int *A, int *B , int n1 ,int n2){

    sort(A , A+n1);
    sort(B , B+n2);
    
    int i = 0 ,j = 0 ,k = 0;
    int C[n1+n1]={};
    while(i < n1 && j < n2){

        //Code GALAT HAI 
        // if(A[i] == B[j]){
        //     C[k] = B[j];
        //     k++;
        // }
        // i++;
        // j++;

        if(A[i] < B[j]){
            i++;
        }

        else if(A[i] > B[j]){
            j++;
        }

        else{
            C[k++] = A[i++];
            j++;
        }
    } 
    
    for(int i = 0 ; i < n1+n2 ; i++){
        cout<<C[i];
    }
}

void setDiff(int *A , int *B , int n1 , int n2){

    //int C[n1+n2] = {};
    // C[i] = A[i];
    // for(int i = 1 ; i < n1 ; i++){
    //     for(int j = 1 ; j < n1 ; j++){
    //         if(A[j] == C[i]){
    //             break;
    //         }
    //         else{
    //             C[i+1] = A[j];
    //         }
    //     }
    // }

    // for(int i = 0 ; i < n2 ; i++){
    //     for(; j < n1+i ; j++){
    //         if(C[j] == B[i])
    //             C[j] = 0;
    //     }
    //     // if(j == n1+i){
    //     //     C[no] = B[i];
    //     //     no++;
    //     //}
    // }
    int j;
    vector<int> v; 
    for(int i = 0 ; i < n1 ; i++){
        for(j = 0; j < n2 ; j++){
            if(A[i] == B[j])
                break;
        }
        if(j == n2)
           v.push_back(A[i]);
    }

    for(int i = 0 ; i < v.size() ; i++){
        cout<<v[i];
    }
}

void setDiffPrime(int *A , int *B , int n1 , int n2){

    //int C[n1+n2] = {};
    vector<int> v;
    int j;
    for(int i = 0 ; i < n1 ; i++){
        for(j = 0 ; j < n2 ; j++){
            if(A[j] == B[i])
                break;
        }
        if(j == n2)
            v.push_back(B[i]);
    }
    for(int i = 0 ; i < v.size() ; i++){
        cout<<v[i];
    }
}

void setDiffSort(int *A , int *B , int n1 , int n2){

    sort(A,A+n1);
    sort(B,B+n1);

    vector<int> v;
    int i = 0, j = 0;
    while(i < n1 && j < n2){

        if(A[i] == B[j]){
            i++; 
            j++;
        }
        else if(A[i] < B[j]){
            i++;
        }
        else{
            v.push_back(B[j]);
            i++;
            j++;
        }
    }
    while(j < n2){
        v.push_back(B[j]);
        j++;
    } 
}

//Same as Linear Search
bool setMembership(Array arr,int no){

    int i;
    for(i = 0 ; i < arr.length ; i++){
        if(arr.A[i] == no){
            // cout<<"Dekh Bhai no toh hai kya tu padh raha hai ya nahi";
            // break;
            return true;
        }
    }
    // if(i == arr.length)
    //     cout<<"Sorry number is not there";
    return false;
}

//Same as Binary Search

bool setMemSort(Array arr,int no) {

    int mid , l = 0 , h = arr.length-1;
    sort(arr.A,arr.A+arr.length);
    for(int i = 0 ; i < arr.length ; i++){
        cout<<arr.A[i]<<" ";
    }

    cout<<endl;
    
    while(l <= h){ 
        
        mid = (l+h)/2;
        cout<<mid<<" "; 
        if(arr.A[mid] == no){
            cout<<endl;
            return true;
        }   
        else if(arr.A[mid] < no){
            l = mid+1;
        }
        else{
            h = mid-1;
        }
    }
    
    cout<<endl;
    return false;
}

//either find single or double missing number

void sdMissSort(int *A , int n1){

    int x , y;
    for(int i = 1 ; i < n1 ; i++){
        x = A[i-1];
        y = A[i];

        for(int j = x+1 ; j < y ; j++)
            cout<<j<<" ";

        cout<<endl;
    }
}

//best solution is to go for binary search take O(log(N)) time

int missNumBinSearch(){
    
}

//use hashmap

void sdMissUnsorted(int *A, int n1){


}

int main()
{
   struct Array arr={{4,0,-10,-18,21,24,0,-27},10,8};
//   Append(&arr,10);
//   Display(arr);
//   Insert(&arr,4,10);
//   index starts from 0 and length or size starts from 1 (here 4 is index)
//   Display(arr);
//   Delete(&arr,3);//here 3 is index
//   Display(arr);
//   cout<<"Element is at:"<<Search(arr,10)<<endl;//retrun index
//   cout<<"Element is at:"<<Searchimp(&arr,4)<<endl;
//   Display(arr);
//   cout<<"Element is at:"<<Searchi(&arr,5)<<endl;
//   Display(arr);
//   cout<<"Element is at:"<<BinaryS(arr,4)<<endl;
//   cout<<"Element at index 7:"<<get(arr,7)<<endl;
//   cout<<"Set Element at index 6:"<<setIndex(4,7,arr)<<endl;

//   Array arr1=setIndex(4,1,arr);
//   Display(arr1);
//   cout<<findMin(arr)<<endl;
//   cout<<findMax(arr);
//   int n=arr.length;
//   cout<<findSum(arr)<<endl;
//   cout<<recSum(arr , n-1)<<endl;
//   float avg=(int)(findAvg(arr)*100+.5);

//   cout<<(float)avg/100;

//   revRevag(arr);
//   LS(arr,3);
//   RS(arr,9);
//   LR(arr,4);
//   cout<<sizeof(arr.A)/sizeof(arr.A[0])<<endl;
//   cout<<insSorted(arr,40);
//   RR(arr,3);
//   cout<<insSort(arr,3);
//   cout<<isSorted(arr);
//   negLeft(arr);
//   moveallZerosRight(arr);
//   moveallZerosLeft(arr);
    int A[] = {1,2,3,5};
    int B[] = {2,1,7,5,6,9};

    int n1 = sizeof(A)/sizeof(A[0]);
    int n2 = sizeof(B)/sizeof(B[0]);
//  cout<<n1<<" "<<n2;
//  setoperartionUnion(A , B , n1 , n2);
//  unionSort(A , B , n1 , n2);

//  setIntersection(A , B , n1 , n2);
//  setIntersectionSort(A , B , n1 , n2);
//  setDiff(A , B , n1 , n2);
//  setDiffPrime(A , B , n1 , n2);
//  cout<<setMembership(arr,100);
//  cout<<setMemSort(arr,24);

    sdMissSort(A,n1);
    return 0;
}
