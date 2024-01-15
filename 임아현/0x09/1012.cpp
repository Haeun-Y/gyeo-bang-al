#include <bits/stdc++.h>

using namespace std;
#define x first
#define y second 

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TC; //test case
    cin >> TC;
    
    while(TC--){
        int board[50][50] = {0};
        bool vis[50][50] = {0}; //방문 여부

        int M, N, K; //가로 세로 배추 개수
        cin >> M >> N >> K;
        queue<pair<int, int>> Q ; //배추 위치 queue
        while(K--){
            int X, Y;// 배추 위치
            cin >> X >> Y;
            board[X][Y] = 1;
            Q.push({X, Y});
        }
        
        int cnt = 0;
        
        while(!Q.empty()){
            queue<pair<int, int>> BQ; //인접한 배추 queue
            auto start = Q.front(); Q.pop();
            if(vis[start.x][start.y]) continue;
            vis[start.x][start.y] = 1;
            BQ.push({start.x, start.y});
            cnt++;
            while(!BQ.empty()){
                auto cur = BQ.front(); BQ.pop();
                for(int dir = 0; dir < 4; dir++){
                  int nx = cur.x + dx[dir];
                  int ny = cur.y + dy[dir];
                  if(nx < 0 || nx >= M || ny < 0 || ny >= N ) continue;
                  if(board[nx][ny] == 0 || vis[nx][ny]) continue;
                  vis[nx][ny] = 1;
                  BQ.push({nx, ny});
                }
            } 
        }
        cout << cnt << '\n';
    }
}