//230314
//PROGRAMMERS 리코쳇 로봇
//Lv.2
#include <bits/stdc++.h>
using namespace std;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
typedef struct
{
    int x;
    int y;
    int move;
}block;
block moveRobot(block pos, pair<int, int> dir, vector<string>& board)
{
    block newBlock = pos;
    newBlock.move++;
    
    while(1)
    {
        int nx = newBlock.x + dir.first;
        int ny = newBlock.y + dir.second;
        
        if(nx < 0 || nx >= board.size() || ny < 0 || ny >= board[0].length())
            return newBlock;
        else if(board[nx][ny] == 'D')
            return newBlock;
        else
        {
            newBlock.x = nx;
            newBlock.y = ny;
        }
    }
    return newBlock;
    
}
int solution(vector<string> board) {
    pair<int, int> startPos;
    pair<int, int> endPos;
    int row = board.size();
    int col = board[0].length(); 
    
    for(int i = 0; i<row; i++)
    {
        for(int j = 0; j<col; j++)
        {
            if(board[i][j] == 'R')
                startPos = {i, j};
            if(board[i][j] == 'G')
                endPos = {i, j};
        }
    }
    
    vector<vector<bool>> isVisited(row, vector<bool>(col, false));
    queue<block> q;
    q.push({startPos.first, startPos.second, 0});
    isVisited[startPos.first][startPos.second] = true;
    
    while(!q.empty())
    {
        block cur = q.front();
        q.pop();
        
        for(int i = 0; i<4; i++)
        {
            block newBlock = moveRobot(cur, {dx[i], dy[i]}, board);
            if(isVisited[newBlock.x][newBlock.y]) continue;
            if(newBlock.x == endPos.first && newBlock.y == endPos.second)
                return newBlock.move;
            q.push(newBlock);
            //cout << "pushed in q : (" << newBlock.x << ", " << newBlock.y << ")\n";
            isVisited[newBlock.x][newBlock.y] = true;
        }
    }
    
        
    return -1;
}