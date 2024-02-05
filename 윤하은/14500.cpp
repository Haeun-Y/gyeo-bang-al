//240205
//BOJ 14500
//GOLD 4
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int row, col;
vector<vector<int>> paper;
vector<vector<vector<bool>>> tetromino;

void printTetromino()
{
    for(int i = 0; i<tetromino.size(); i++)
    {
        for(int j =0 ; j<tetromino[i].size(); j++)
        {
            for(int k =0; k<tetromino[i][j].size(); k++)
            {
                if(tetromino[i][j][k]) cout << "#";
                else cout << ".";
            }
            cout << "\n";
        }
        cout << "\n\n";
    }
}
void printV2(vector<vector<bool>>& v)
{
    for(int i = 0; i<v.size(); i++)
    {
        for(int j = 0; j<v[i].size(); j++)
        {
            if(v[i][j]) cout << "#";
            else cout << ".";
            
        }
        cout<< "\n";
    }
    
}
void setTetromino()
{
    vector<vector<bool>> t(1, vector<bool>(4, true));
    tetromino.push_back(t);
    
    t = vector<vector<bool>>(4, vector<bool>(1, true));
    tetromino.push_back(t);
    
    t = vector<vector<bool>>(2, vector<bool>(2, true));
    tetromino.push_back(t);
    
    t = vector<vector<bool>>(3, vector<bool>(2, true));
    t[0][1] = t[1][1] = false;
    tetromino.push_back(t);
    
    t[0][1] = t[1][1] = true;
    t[1][0] = t[2][0] = false;
    tetromino.push_back(t);
    
    t[0][0] = false;
    t[2][0] = true;
    tetromino.push_back(t);
    
    t[0][0] = t[1][0] = true;
    t[1][1] = t[2][1] = false;
    tetromino.push_back(t);
    
    t[0][1] = false;
    t[1][1] = true;
    tetromino.push_back(t);
    
    t[0][0] = false;
    t[0][1] = true;
    tetromino.push_back(t);
    
    t[2][0] = false;
    t[2][1] = true;
    tetromino.push_back(t);
    
    t[0][0] = true;
    t[0][1] = false;
    tetromino.push_back(t);
    
    t = vector<vector<bool>>(2, vector<bool>(3, true));
    t[1][1] = t[1][2] = false;
    tetromino.push_back(t);
    
    t[1][0] = false;
    t[1][2] = true;
    tetromino.push_back(t);
    
    t[0][2] = false;
    t[1][1] = true;
    tetromino.push_back(t);
    
    t[0][0] = false;
    t[1][0] = true;
    tetromino.push_back(t);
    
    t[0][1] = false;
    t[0][0] = true;
    tetromino.push_back(t);
    
    t[0][0] = false;
    t[0][2] = true;
    tetromino.push_back(t);
    
    t[1][2] = false;
    t[0][1] = true;
    tetromino.push_back(t);
    
    t[1][0] = false;
    t[0][0] = true;
    tetromino.push_back(t);
    
}
int computeSum(pair<int, int> leftUpPos, int tetrominoIdx)
{
    int sum = 0;
    for(int i = 0; i<tetromino[tetrominoIdx].size(); i++)
    {
        int nx = leftUpPos.first + i;
        if(nx < 0 || nx >= row) return 0;
        for(int j = 0; j<tetromino[tetrominoIdx][i].size(); j++)
        {
            int ny = leftUpPos.second + j;
            if(ny < 0 || ny >= col) return 0;
            if(tetromino[tetrominoIdx][i][j]) sum += paper[nx][ny];
        }
    }
    return sum;
}
int computMaxSum()
{
    int maxSum = 0;
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            for(int k = 0; k < tetromino.size(); k++)
                maxSum = max(maxSum, computeSum(make_pair(i, j), k));
        }
    }
    
    return maxSum;
    
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> row >> col;
    paper = vector<vector<int>>(row, vector<int>(col, 0));
    
    for(int i = 0; i<row; i++)
    {
        for(int j = 0; j<col; j++)
            cin >> paper[i][j];
    }
    
    setTetromino();
    //printTetromino();
    cout << computMaxSum();
    
}
