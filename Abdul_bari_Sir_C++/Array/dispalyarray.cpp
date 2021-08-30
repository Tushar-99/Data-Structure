#include<iostream>

using namespace std;

struct Array
{
    int *A;
    int size;
    int lenght;
};

// void Append(struct Array *arr,int x)
// {
        
// }
void Display(struct Array arr1)
{
    int i;
    for(i=0;i<arr1.lenght;i++)
    {
        cout<<arr1.A[i]<<endl;
    }
}



int main()
{
    struct Array arr;
    int n=0,i;
    cout<<"Enter the size of the array";
    cin>>arr.size;

    arr.A=new int [arr.size];
    arr.lenght=0;

    cout<<"Enter the number of numbers";
    cin>>n;
    if(n<=arr.size){
    cout<<"Enter the elements";
    for(i=0;i<n;i++)
    {
        cin>>arr.A[i];
    }
    arr.lenght=n;       
    Display(arr);
  }
   else{
       cout<<"Chalak mat ban";
   }
   return 0;
}