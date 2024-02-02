//240202
//BOJ 11559 Puyo puyo
//GOLD 4
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int ROW = 4;
const int COL = 6;
const char BLANK = '.';
const char RED = 'R';
const char GREEN = 'G';
const char BLUE = 'B';
const char PURPLE = 'P';
const char YELLOW = 'Y';
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
vector<vector<char>> puyoField(ROW, vector<char>(COL, BLANK));
void printPuyoField()
{
    for(int i = ROW-1; i>=0; i--)
    {
        for(int j = 0; j<COL; j++)
            cout << puyoField[i][j];
        cout << "\n";
    }
}
bool findPuyo()
{

}
void removePuyo(vector<pair<int, int>>& v)
{
    for(int i = 0; i<v.size(); i++)
        puyoField[v[i].first][v[i].second] = BLANK;
}
void dropPuyo()
{
    cout << "before drop puyo\n";
    printPuyoField();
    for(int j = 0; j<COL; j++)
    {
        int idx = 0;
        for(int i = 0; i<ROW; i++)
        {
            if(puyoField[i][j] != BLANK)
                puyoField[idx++][j] = puyoField[i][j];
        }
        for(int i = idx; i<ROW; i++)
            puyoField[i][j] = BLANK;
    }
    cout << "after drop puyo\n";
    printPuyoField();
    
}
int computePuyoCombo()
{
    bool flg = false;
    int comboNum = -1;

    do
    {
        comboNum++;
        vector<vector<bool>> isVisited(ROW, vector<bool>(COL, false));
        queue<pair<int, int>> q;
        for(int i = 0; i<ROW; i++)
        {
            for(int j = 0; j<COL; j++)
            {
                char color = puyoField[i][j];
                if(isVisited[i][j] || color == BLANK) continue;
                cout << "puyoField[" << i << ", " << j << "] : " << color << "\n";
                q.push(make_pair(i, j));
                int puyoNum = 1;
                isVisited[i][j] = true;

                vector<pair<int, int>> v;
                v.push_back(make_pair(i, j));

                while(!q.empty())
                {
                    pair<int, int> cur = q.front();
                    q.pop();

                    for(int k = 0; k<4; k++)
                    {
                        int nx = cur.first + dx[k];
                        int ny = cur.second + dy[k];

                        if(nx < 0 || nx >= ROW || ny < 0 || ny >= COL) continue;
                        if(puyoField[nx][ny] != color || isVisited[nx][ny]) continue;

                        q.push(make_pair(nx, ny));
                        isVisited[nx][ny] = true;
                        puyoNum++;
                        cout << "puyo" << puyoNum << ": (" << nx << ", " << ny << ")\n";

                        v.push_back(make_pair(nx, ny));
                    }
                }
                if(puyoNum >= 4)
                {
                    cout << color << " " << puyoNum << " puyo puyo\n";
                    printPuyoField();
                    flg = true;
                    removePuyo(v);
                    cout << "removed puyo\n";
                    printPuyoField();
                }
            }

        }
        
        //dropPuyo();

    }while(flg);

    return comboNum;

}
int main(void)
{
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);
    
    for(int i = ROW-1; i>=0; i--)
    {
        for(int j = 0; j<COL; j++)
            cin >> puyoField[i][j];
    }

    //printPuyoField();

    cout << computePuyoCombo();

}