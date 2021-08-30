//Heap is tree based data structure and tree is complete binary tree
//2 types of heap -> Max Heap or Min Heap
#include<bits/stdc++.h>

using namespace std;

class Heap
{
public:
    int *arr;
    int index;
    int capacity;
    int heap_size;
    Heap(int size)
    {
        capacity = size;
        arr = new int[capacity + 1];
        index = 1;
        heap_size = 0;
    }

    void Max_insert(int);

    void Min_insert(int);

    void levelorder();

    void deleteEle_Max(int);
    
    void deleteEle_Min();

    void heapSort();

    void heapSort_Max(int* , int);

    void heapSort_Min(int* , int);

    void maxHeapify(int* , int , int);
    
    void minHeapify(int* , int , int);
};

void Heap::Max_insert(int data)
{
    int n = index;

    while(n > 1 && data > arr[n / 2])
    {
        arr[n] = arr[n / 2];
        n /= 2; 
    }

    arr[n] = data;
    index++;
    heap_size++;
    cout<< heap_size << endl;
}

void Heap::Min_insert(int data)
{
    int n = index;

    while(n > 1 && data < arr[n / 2])
    {
        arr[n] = arr[n / 2];
        n /= 2; 
    }
    
    arr[n] = data;
    index++;
}

void Heap::levelorder()
{
    for(int i = 1 ; i <= heap_size ; i++)
        cout << arr[i] << " ";
}

void swap(int* x ,int* y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

//in heap there is always deletion of root element 
//Max Heap and Min Heap mae ek garbar hai ye last 3 elements ke liye galat swap kar rahe hai
void Heap::deleteEle_Max(int i)
{
    int j = 2 * i , val;

    swap(&arr[1] , &arr[index]);

    while(j <= heap_size)
    {
        if(arr[j + 1] > arr[j])
            j += 1;
        
        if(arr[i] < arr[j])
        {
            swap(&arr[i] , &arr[j]);
            i = j;
            j *= 2;
        }
        else
            break;
    }
    index--;
}

void Heap::heapSort()
{
    index -= 1;
    while(index > 0){
        deleteEle_Max(1);
    }
}

void Heap::deleteEle_Min()
{
    int i = 1 , j = 2 * i , temp;
    
    if(index > 3)
    {
        int val = arr[1];
        arr[1] = arr[index - 1];
        arr[index - 1] = val;
    }

    while(j < index - 2)
    {
        if(arr[j + 1] < arr[j])
            j += 1;
        
        if(arr[i] > arr[j])
        {
            swap(arr[i] , arr[j]);
            i = j;
            j *= 2;
        }
        else
            break;
    }
    if(index == 3)
    {
        int val = arr[1];
        arr[1] = arr[index - 1];
        arr[index - 1] = val;
    }
}

// void Heap::heapify(int* H , int n)
// {
//Wrong Code
    // int j = n;
    // int temp = j;
    // int ind = n / 2;

    // while(ind >= 1 && (H[j] < max(H[2 * j]  , H[(2 * j) + 1])) )
    // {
    //     if((2 * ind) + 1 >= n && H[2 * ind] > H[(2 * ind) + 1])
    //     {   
    //         j -= 1;
    //         temp = j;
    //     }

    //     if(H[j] > H[ind])
    //     {
    //         swap(H[j] , H[ind]);

    //         if((2 * j) + 1 >= n && (H[j] < max(H[2 * j]  , H[(2 * j) + 1])))
    //         {
    //             ind = temp;
    //             j = (2 * ind) + 1;
    //         }

    //         else
    //         {
    //             ind--;
    //             j = (2 * ind) + 1;
    //         }
    //     }
    // }
//}

void Heap::maxHeapify(int *H , int n , int i)
{
    int lar = i;
    int l = 2 * i;
    int r = 2 * i + 1;
    if(l <= n && H[lar] < H[l])
        lar = l;

    if(r <= n && H[lar] < H[r])
        lar = r;

    if(lar != i)
    {
        swap(&H[lar] , &H[i]);
        maxHeapify(H , n , lar);
    }
}

void Heap::minHeapify(int *H , int n , int i)
{
    int lar = i;
    int l = 2 * i;
    int r = 2 * i + 1;
    if(l <= n && H[lar] > H[l])
        lar = l;

    if(r <= n && H[lar] > H[r])
        lar = r;

    if(lar != i)
    {
        swap(&H[lar] , &H[i]);
        minHeapify(H , n , lar);
    }
}

void Heap::heapSort_Max(int *H , int n)
{   
    int par = n / 2;
    for(int i = par ; i > 0 ; i--)
        maxHeapify(H , 7 , i);

    for(int i = n ; i > 0 ; i--)
    {
        swap(&H[1] , &H[i]);
        maxHeapify(H , i - 1 , 1);
    }
}

void Heap::heapSort_Min(int *H , int n)
{   
    int par = n / 2;
    for(int i = par ; i > 0 ; i--)
        minHeapify(H , 7 , i);

    for(int i = n ; i > 0 ; i--)
    {
        swap(&H[1] , &H[i]);
        minHeapify(H , i - 1 , 1);
    }
}

int main()
{
    //Heap(size);
    Heap *h = new Heap(10);
    h->Max_insert(10);
    h->Max_insert(20);
    h->Max_insert(30);
    h->Max_insert(25);
    h->Max_insert(5);
    h->Max_insert(40);
    h->Max_insert(35);
    h->Max_insert(50);

    h->levelorder();
    cout << endl;
    h->heapSort();
    h->levelorder();

    // Heap *h1 = new Heap(10);
    // h1->Min_insert(10);
    // h1->Min_insert(20);
    // h1->Min_insert(30);
    // h1->Min_insert(25);
    // h1->Min_insert(5);
    // h1->Min_insert(40);
    // h1->Min_insert(35);
    // h1->Min_insert(50);
    
    // cout << endl;
    // h1->levelorder();  

    // cout << endl;
    // h1->heapSort_Min();
    // //h1->deleteEle_Min();
    // h1->levelorder();

    // Heap *h1 = new Heap(12);
    // h1->Max_insert(12);
    // h1->Max_insert(11);
    // h1->Max_insert(5);
    // h1->Max_insert(9);
    // h1->Max_insert(7);
    // h1->Max_insert(2);
    // h1->Max_insert(3);
    // h1->Max_insert(1);
    // h1->Max_insert(4);
    // h1->Max_insert(8);
    // h1->Max_insert(6);
    // h1->Max_insert(10);
    // cout << endl;
    // h1->levelorder(); 
    // cout << endl;
    // h1->heapSort_Max();
    // h1->levelorder();  

    // Heap *h1 = new Heap(10);
    // int H[] = {0 , 5 , 10 , 30 , 20 , 35 , 40 , 15};

    // for(int i = 3 ; i > 0 ; i--)
    //     h1->maxHeapify(H , 7 , i);

    // for(int i = 7 ; i > 0 ; i--)
    // {
    //     swap(&H[1] , &H[i]);
    //     h1->maxHeapify(H , i - 1 , 1);
    // }
    
    // h1->heapSort_Max(H , 7);
    // for(int i = 1 ; i < 8 ; i++)
    //     cout << H[i] << " ";

    // cout << endl;

    // h1->heapSort_Min(H , 7);
    // for(int i = 1 ; i < 8 ; i++)
    //     cout << H[i] << " ";

//Output -->

// 5 10 15 20 30 35 40
// 40 35 30 20 15 10 5

}

// Output -->
//Max Heap ->
// 50 40 35 25 5 20 30 10

//After deletion 0f 50 ->
// 40 25 35 10 5 20 30

//Min Heap ->
// 5 10 30 25 20 40 35 50

//After Deletion of 5->
// 10 20 30 25 50 40 35

//Heap Sort -->

//Max Heap ->
// 50 40 35 25 5 20 30 10 0

//After Sorting ->
// 5 10 20 25 30 35 40 50 0

//Min Heap ->
// 5 10 30 25 20 40 35 50 0

// After Sorting ->
// 50 40 35 30 25 20 10 5 0