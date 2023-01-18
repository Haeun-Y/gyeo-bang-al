//BOJ 1600 말이 되고픈 원숭이
#include <bits/stdc++.h>
using namespace std;
int dxH[8] = {-1, -2, -1, -2, 1, 2, 1, 2};
int dyH[8] = {-2, -1, 2, 1, -2, -1, 2, 1};
int dxM[4] = {-1, 1, 0, 0};
int dyM[4] = {0, 0, -1, 1};
typedef struct pos
{
    bool isVisit;
    int monkeyMove;
    int horseMove;

}pos;
int main(void)
{
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);
    
    int maxHorseMove;
    cin >> maxHorseMove;
    
    int row, col;
    cin >> col >> row;

    int minMove = -1;

    vector<vector<int>> board(row, vector<int>(col, 0));
    
    for(int i = 0; i<row; i++)
    {
        for(int j = 0; j<col; j++)
            cin >> board[i][j];
    }
    
    vector<vector<pos>> movement(row, vector<pos>(col));

    pair<int, int> start = {0, 0};
    pair<int, int> destination = {row-1, col-1};

    queue<pair<int, int>> q;
    movement[0][0].isVisit = true;
    q.push(start);

    while(!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();

        int cur_mky = movement[cur.first][cur.second].monkeyMove;
        int cur_hrs = movement[cur.first][cur.second].horseMove;

        if(cur == destination)
        {
            minMove = cur_mky + cur_hrs;
            break;
        }

        if(cur_hrs < maxHorseMove)
        {
            for(int i = 0; i<8; i++)
            {
                int nx = cur.first + dxH[i];
                int ny = cur.second + dyH[i];

                if(nx < 0 || nx >= row || ny < 0 || ny >= col) continue;
                if(movement[nx][ny].isVisit || board[nx][ny] == 1) continue;
                if(nx == destination.first && ny == destination.second)
                {
                    minMove = cur_mky + cur_hrs + 1;
                    break;
                }
                
                movement[nx][ny].isVisit = true;
                movement[nx][ny].horseMove = cur_hrs + 1;
                movement[nx][ny].monkeyMove = cur_mky;
                q.push({nx, ny});
            }

        }

        for(int i = 0; i < 4; i++)
        {
            
            int nx = cur.first + dxM[i];
            int ny = cur.second + dyM[i];

            if(nx < 0 || nx >= row || ny < 0 || ny >= col) continue;
            if(movement[nx][ny].isVisit || board[nx][ny] == 1) continue;
            if(nx == destination.first && ny == destination.second)
            {
                minMove = cur_mky + cur_hrs + 1;
                break;
            }
                
            movement[nx][ny].isVisit = true;
            movement[nx][ny].horseMove = cur_hrs;
            movement[nx][ny].monkeyMove = cur_mky + 1;
            q.push({nx, ny});

        }
    }

    cout << minMove;


}