#include<iostream>
#include<algorithm>
using namespace std;

struct Array
{
    int *A;
    int len;
}arr3;

void mergeSort(struct Array arr1,struct Array arr2)
{
	
   arr3.len=arr1.len+arr1.len;
   int i=0,j=0,k=0;
   while(i<arr1.len && j<arr2.len)
   {
       if(arr1.A[i]>arr2.A[j])
       {
           arr3.A[k++]=arr2.A[j++];
       }
  	   else  
       {
           arr3.A[k++]=arr1.A[i++];
       }
   } 
}

void display(struct Array arr)
{
    int i;
    for(i=0;i<arr.len;i++)
    {
        cout<<arr.A[i]<<endl;
    }
}


int main()
{
    struct Array arr1,arr2;
    cin>>arr1.len;
    arr1.A=new int [arr1.len];
    for(int i=0;i<arr1.len;i++)
    {
        cin>>arr1.A[i];
    }
    cin>>arr2.len;
    arr2.A=new int[arr2.len];
    for(int j=0;j<arr2.len;j++)
    {
        cin>>arr1.A[j];
    }
    sort(arr1.A,arr1.A+arr1.len-1);
    sort(arr2.A,arr1.A+arr2.len-1);
    mergeSort(arr1,arr2);
    display(arr3);
    
    return 0;
}
