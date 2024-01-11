//240110
//BOJ 9663 N-Queen
//GOLD 4
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> chess;
vector<vector<pair<int, int>>> rightDown;
vector<vector<pair<int, int>>> rightUp;
int result;
int n;
void checkBoard(pair<int, int> target, int row, bool flg)
{
    int rightDownNum = target.first - target.second + n - 1;
    int rightUpNum = target.first + target.second;
    
    for(int i = 0; i<n; i++)
    {
        if(flg && chess[target.first][i] == -1)//-1 -> row
            chess[target.first][i] = row;
        else if(!flg && chess[target.first][i] == row)//row -> -1
            chess[target.first][i] = -1;
        if(flg && chess[i][target.second] == -1)//-1 -> row
            chess[i][target.second] = row; 
        else if(!flg && chess[i][target.second] == row)//row -> -1
            chess[i][target.second] = -1; 
    }
    
    for(int i = 0; i<rightDown[rightDownNum].size(); i++)
    {
        pair<int, int> cur = rightDown[rightDownNum][i];
        if(flg && chess[cur.first][cur.second] == -1)//-1 -> row
            chess[cur.first][cur.second] = row;
        else if(!flg && chess[cur.first][cur.second] == row)//row -> -1
            chess[cur.first][cur.second] = -1;
    }
    
    for(int i = 0; i<rightUp[rightUpNum].size(); i++)
    {
        pair<int, int> cur = rightUp[rightUpNum][i];
        if(flg && chess[cur.first][cur.second] == -1)//-1 -> row
            chess[cur.first][cur.second] = row;
        else if(!flg && chess[cur.first][cur.second] == row)//row -> -1
            chess[cur.first][cur.second] = -1;
    }
    
}
void setDiagonals()
{
    rightDown =  vector<vector<pair<int, int>>>(n*2, vector<pair<int, int>>());
    rightUp =  vector<vector<pair<int, int>>>(n*2, vector<pair<int, int>>());
    
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            rightDown[i-j+n-1].push_back(make_pair(i, j));
            rightUp[i+j].push_back(make_pair(i, j));
        }
    }
}
//row queen을 배치하는 함수
void putQueens(int row)
{
    if(row == n)
    {
        result++;
        return;
    }
    else
    {
        for(int i = 0; i<n; i++)
        {
            if(chess[row][i] != -1) continue;
            pair<int, int> cur = make_pair(row, i);
            checkBoard(cur, row, true);
            putQueens(row+1);
            checkBoard(cur, row, false);
        }
    }
    
    
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    chess = vector<vector<int>>(n, vector<int>(n, -1));

    setDiagonals();
    putQueens(0);
    cout << result;
}