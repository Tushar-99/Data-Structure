#include<bits/stdc++.h>
using namespace std;

bool isSafe(int arr[][9], int i, int j, int k, int n){
  for(int a=0; a<n; a++){
    if(arr[i][a]==k || arr[a][j]==k)  //change
      return false;
  }

  int key = sqrt(n);
  int p = (i/key)*key;
  int q = (j/key)*key;
  for(int a=p; a<p+key; a++){
    for(int b=q; b<q+key; b++){
      if(arr[a][b] == k)
	return false;
    }
  }
  return true;
}

bool solveSudoku(int arr[][9], int i, int j, int n){
  if(i==n){
    for(int a=0; a<n; a++){
      for(int b=0; b<n; b++){
	cout<<arr[a][b]<<" ";
      }
      cout<<endl;
    }
    return true;
  }
  
  if(j==n){
    return solveSudoku(arr,i+1,0,n);
  }

  if(arr[i][j]!=0)
    return solveSudoku(arr,i,j+1,n);

  else{
    for(int k=1; k<=n; k++){
      if(isSafe(arr,i,j,k,n))
      {
          arr[i][j] = k;
      
      if(solveSudoku(arr,i,j+1,n))
	        return true;
    }
    }
    arr[i][j] = 0;
    return false;
}
}

int main(){
  int n;
  cin>>n;
  int arr[9][9]=
    {
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };
  
  solveSudoku(arr,0,0,n);
  return 0;
}
