#include<iostream>
#include<iomanip>

using namespace std;
const int D=5;

bool canPlace(int board[D][D],int n, int r,int c){
    return
        r>=0 && r<n &&
        c>=0 && c<n &&
        board[r][c] ==0;
}

void printBoard(int board[D][D],int n){
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cout<< setw(3)<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool solveKnightMove(int board[D][D],int n,int move_no,int curRow,int curCol)
{
    if(move_no == n*n)
    {   
        printBoard(board,n);
        cout << "=============================\n";
        return true;
    }
    int rowDir[]={+2,+1,-1,-2,-2,-1,+1,+2};
    int colDir[]={+1,+2,+2,+1,-1,-2,-2,-1};
    for(int curDir = 0; curDir <8; ++curDir)
    {
        int nextRow=curRow+rowDir[curDir];           
        int nextCol=curCol+colDir[curDir];
        if(canPlace(board,n,nextRow,nextCol)==true){
            board[nextRow][nextCol]=move_no+1;
            bool isSuccessful = solveKnightMove(board,n,move_no+1,nextRow,nextCol);
            // if(isSuccessful == true) 
            // {
            //     return true;
            // }
            board[nextRow][nextCol]=0;
        }           
    }
    return false;
}


int main()
{
    int board[D][D]={0};
    int n;
    cin>>n;
    board[0][0] =1;
    bool ans = solveKnightMove(board,n,1,0,0);
    // if(ans == true)
    // {
    //     printBoard(board,n);
    // }
    // else{
    //     cout<<"Sorry man! Can't visit your board";
    // }
}