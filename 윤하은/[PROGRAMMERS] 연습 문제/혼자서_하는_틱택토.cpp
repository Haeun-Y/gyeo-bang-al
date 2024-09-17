//230315
//PROGRAMMERS 혼자서 하는 틱택토
//Lv.2
#include <bits/stdc++.h>
using namespace std;
vector<string> board2(3, "...");
vector<vector<bool>> isUsed(3, vector<bool>(3, false));
int oNum;
int xNum;
int result;
bool isFinishedGame(vector<string>& board)
{
    for(int i = 0; i<3; i++)
    {
        if(board[i] == "OOO" || board[i] == "XXX") return true;
        if(board[0][i] != '.' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true;
    }
    if(board[0][0] != '.' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;
    if(board[0][2] != '.' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true;
    
    return false;
}
void backtracking(bool isO, int curONum, int curXNum, vector<string>& board)
{
    if((curONum == oNum && curXNum == xNum))
    {
        bool isSameBoard = true;
        for(int i = 0; i<3; i++)
        {
            if(board2[i] != board[i])
            {
                isSameBoard = false;
                break;
            }
        }
        if(isSameBoard) result++;
        return;
    }
    else if(isFinishedGame(board2))
        return;
    else
    {
        for(int i = 0; i<3; i++)
        {
            for(int j = 0; j<3; j++)
            {
                if(board2[i][j] != '.') continue;
                if(isO)
                {
                    board2[i][j] = 'O';
                    backtracking(!isO, curONum+1, curXNum, board);
                }
                else
                {
                    board2[i][j] = 'X';
                    backtracking(!isO, curONum, curXNum+1, board);
                }
                
                board2[i][j] = '.';
            }
            
            
        }
    }
    
    
}
int solution(vector<string> board) {
    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j<3; j++)
        {
            if(board[i][j] == 'O') oNum++;
            else if(board[i][j] == 'X') xNum++;
        }
    }
    if(oNum < xNum) return 0;
    backtracking(true, 0, 0, board);
    if(result >= 1) return 1;//result 에 대해서 다시 생각해보기
    else return 0;
    
}