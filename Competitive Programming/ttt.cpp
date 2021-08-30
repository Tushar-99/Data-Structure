#include <bits/stdc++.h>

using namespace std;

int tic_tac_toe(int board[3][3]){

    int che[8][3][2] = {
        {{0 , 0} , {1 , 1} , {2 , 2}},
        {{0 , 2} , {1 , 1} , {2 , 0}},
        {{0 , 0} , {0 , 1} , {0 , 2}},
        {{1 , 0} , {1 , 1} , {1 , 2}},
        {{2 , 0} , {2 , 1} , {2 , 2}},
        {{0 , 0} , {1 , 0} , {2 , 0}},
        {{0 , 1} , {1 , 1} , {2 , 1}},
        {{0 , 2} , {1 , 2} , {2 , 2}}
    };
    int i = 0 , j  = 0 , k = 0;
    bool draw = true;
    for(i = 0 ; i < 3 ; i++){
        for (j = 0; j < 3; j++){
            if(board[i][j] == 0){
                draw = false;
                break;
            }
        }
    }

    if(draw)
        return 3;
    
    else{
        for (i = 0; i < 8; i++){
            if((board[che[i][j][k]][che[i][j][k+1]] ==  board[che[i][j+1][k]][che[i][j+1][k+1]]) && (board[che[i][j+1][k]][che[i][j+1][k+1]] == board[che[i][j+2][k]][che[i][j+2][k+1]]) && (board[che[i][j+2][k]][che[i][j+2][k+1]] == board[che[i][j][k]][che[i][j][k+1]])){
                if(board[che[i][j][k]][che[i][j][k+1]] == 'a')
                    return 1;
                
                else if(board[che[i][j][k]][che[i][j][k+1]] == 'b')
                    return 2;
            }
        }
    }

    return 4;
}

int main(){

    int board[3][3] = {0};
    int res = 0;
    int start , color , turn , sel;
    string move;
    cout << "Press 1 to start and 0 for exit" << endl;
    cin >> start;

    if(start){

        cout << "Which one want to first move 1 for player 1 & 2 for player 2" << endl;
        cin >> turn;
        for (int i = 0; i < 9; i++){
            res = 0;
            if(turn == 1){
                sel = 'a';
                while(true){
                    cout << "Player 1 turn: ";
                    cin >> move;
                    int r = move[0] - 48;
                    int c = move[1] - 48;
                    if(r < 0 || r > 2 || c > 2 || c < 0){
                        cout << "Plz enter correct range" << endl;
                        continue;
                    }

                    if(board[r][c] == 0){
                        board[r][c] = sel;
                        break;
                    }
                    else
                        cout << "Board already occupied" << endl;
                }
            }
            
            else if(turn == 2){
                sel = 'b';
                while(true){
                    cout << "Player 2 turn: ";
                    cin >> move;
                    int r = move[0] - 48;
                    int c = move[1] - 48;
                    if(r < 0 || r > 2 || c > 2 || c < 0){
                        cout << "Plz enter correct range" << endl;
                        continue;
                    }
                    if(board[r][c] == 0){
                        board[r][c] = sel;
                        break;
                    }
                    else
                        cout << "Board already occupied" << endl;
                }
            }

            if(i >= 4){
                res = tic_tac_toe(board);
                if(res == 1){
                    cout << "Player 1 win" << endl;
                    break;
                }  

                else if(res == 2){
                    cout << "Player 2 win" << endl;
                    break;
                } 

                else if(res == 3){
                    cout << "Game Draw" << endl;
                    break;
                }    
            }

            if(turn == 1)
                turn++;
            
            else
                turn--;
        }
    }

    else
        return 0;
}