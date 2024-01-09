#include <bits/stdc++.h>
using namespace std;
bool chess[20][20] = {false, };
vector<vector<pair<int, int>>> rightDown;
vector<vector<pair<int, int>>> rightUp;
int result;
int n;
void checkBoard(pair<int, int> target, bool flg)
{
    int rightDownNum = target.first - target.second + n - 1;
    int rightUpNum = target.first + target.second;
    
    for(int i = 0; i<n; i++)
    {
        chess[target.first][i] = flg;
        chess[i][target.second] = flg;
        cout << "(" << target.first << ", " << i << ") is turned to " << (flg?"true":"false") << "\n"; 
        cout << "(" << i << ", " << target.second << ") is turned to " << (flg?"true":"false") << "\n"; 
    }
    
    for(int i = 0; i<rightDown[rightDownNum].size(); i++)
    {
        pair<int, int> cur = rightDown[rightDownNum][i];
        chess[cur.first][cur.second] = flg;
        cout << "(" << cur.first << ", " << cur.second << ") is turned to " << (flg?"true":"false") << "\n"; 
    }
    
    for(int i = 0; i<rightUp[rightUpNum].size(); i++)
    {
        pair<int, int> cur = rightUp[rightUpNum][i];
        chess[cur.first][cur.second] = flg;
        cout << "(" << cur.first << ", " << cur.second << ") is turned to " << (flg?"true":"false") << "\n"; 
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
            if(chess[i][j]) cout << "#";
            else cout << ".";
        }
        cout << "\n";
    }
}
//n번째 queen을 배치하는 함수
void putQueens(int idx, pair<int, int> before)
{
    if(idx == n)
    {
        result++;
        cout << "result : " << result << "\n";
        return;
    }
    else
    {
        for(int i = before.first; i<n; i++)
        {
            for(int j = before.second+1; j<n; j++)
            {
                if(chess[i][j]) continue;
                cout << "put " << idx << "th queen in (" << i << ", " << j << ")\n";
                pair<int, int> cur = make_pair(i, j);
                checkBoard(cur, true);
                printChess(idx);
                putQueens(idx+1, cur);
                checkBoard(cur, false);
            }
            
        }
        
    }
    
    
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    
    setDiagonals();
    putQueens(0, make_pair(0, -1));
    cout << result;
    
}