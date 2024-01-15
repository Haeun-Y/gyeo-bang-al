#include <bits/stdc++.h>

using namespace std;
#define X first
#define Y second

int dx[8] = {-2, -1, -2, -1, 2, 1, 2, 1};
int dy[8] = {1, 2, -1, -2, 1, 2, -1, -2};


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int TC; //test case
    cin >> TC;
    
    while(TC--){
        int I;
        cin >> I; //체스판 크기
        
        int firstX, firstY; //현재 위치
        cin >> firstX >> firstY; 
        
        int endX, endY; //도착 위치
        cin >> endX >> endY;
        
        int board[I][I]; //체스판
        fill(&board[0][0], &board[I - 1][I], -1);

        queue<pair<int, int>> Q;
        board[firstX][firstY] = 0;
        Q.push({firstX, firstY});
        
        while(!Q.empty()){
            auto cur = Q.front(); Q.pop();
            for(int i = 0; i < 8; i++){
                int nx = cur.X + dx[i];
                int ny = cur.Y + dy[i];
                if(nx < 0 || nx >= I || ny < 0 || ny >=I) continue;
                if(board[nx][ny]>=0) continue;
                board[nx][ny] = board[cur.X][cur.Y] + 1;
                Q.push({nx, ny});
                if(nx == endX && ny == endY) break;
            }
        }
         cout << board[endX][endY] <<'\n';
    }
}