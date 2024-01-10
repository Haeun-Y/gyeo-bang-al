//240110
//BOJ 9663 N-Queen
//GOLD 4
#include <iostream>
#include <vector>
using namespace std;
int chess[20][20] = {-1, };
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
        if(flg && chess[target.first][i] == -1)
            chess[target.first][i] = row;
        else if(!flg && chess[target.first][i] == row)
            chess[target.first][i] = -1;
        if(flg && chess[i][target.second] == -1)
            chess[i][target.second] = row; 
        else if(!flg && chess[i][target.second] == row)
            chess[i][target.second] = -1; 
        //cout << "(" << target.first << ", " << i << ") is turned to " << (flg?"true":"false") << "\n"; 
        //cout << "(" << i << ", " << target.second << ") is turned to " << (flg?"true":"false") << "\n"; 
    }
    
    for(int i = 0; i<rightDown[rightDownNum].size(); i++)
    {
        pair<int, int> cur = rightDown[rightDownNum][i];
        if(flg && chess[cur.first][cur.second] == -1)
            chess[cur.first][cur.second] = row;
        else if(!flg && chess[cur.first][cur.second] == row)
            chess[cur.first][cur.second] = -1;
        //cout << "(" << cur.first << ", " << cur.second << ") is turned to " << (flg?"true":"false") << "\n"; 
    }
    
    for(int i = 0; i<rightUp[rightUpNum].size(); i++)
    {
        pair<int, int> cur = rightUp[rightUpNum][i];
        if(flg && chess[cur.first][cur.second] == -1)
            chess[cur.first][cur.second] = row;
        else if(!flg && chess[cur.first][cur.second] == row)
            chess[cur.first][cur.second] = -1;
        //cout << "(" << cur.first << ", " << cur.second << ") is turned to " << (flg?"true":"false") << "\n"; 
    }
    
}
void printDiagonals()
{
    for(int i = 0; i<rightDown.size(); i++)
    {
        cout << "rightDown " << i << "\n";
        for(int j = 0; j<rightDown[i].size(); j++)
            cout << rightDown[i][j].first << ", " << rightDown[i][j].second << "\n";
        cout << "\n";
    }
    
    for(int i = 0; i<rightUp.size(); i++)
    {
        cout << "rightUp " << i << "\n";
        for(int j = 0; j<rightUp[i].size(); j++)
            cout << rightUp[i][j].first << ", " << rightUp[i][j].second << "\n";
        cout << "\n";
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
    //printDiagonals();
}
void printChess(int idx)
{
    cout << "put " << idx+1 << " queens\n";
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            if(chess[i][j] >= 0) cout << "#";
            else cout << ".";
        }
        cout << "\n";
    }
}
void printChess()
{
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            if(chess[i][j] >= 0) cout << "#";
            else cout << ".";
        }
        cout << "\n";
    }
}
//row queen을 배치하는 함수
void putQueens(int row)
{
    if(row == n)
    {
        result++;
        //printChess();
        //cout << "result : " << result << "\n";
        return;
    }
    else
    {
        for(int i = 0; i<n; i++)
        {
            if(chess[row][i] != -1) continue;
            pair<int, int> cur = make_pair(row, i);
            //cout << "put " << row << "th queen : (" << row << ", " << i << ")\n";
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
    
    setDiagonals();
    putQueens(0);
    cout << result;
    
}