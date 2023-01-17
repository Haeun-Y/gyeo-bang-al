#include <bits/stdc++.h>

using namespace std;

int board[101][101][101];
int vis[101][101][101];

int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int H, M, N; //면 행 열
    cin >> M >> N >> H;
    queue<tuple<int, int, int>> Q; //색맹 x
    
    for(int i = 0; i < H; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < M; k++){
              cin >> board[j][k][i];
              if(board[j][k][i] == 1) Q.push({j, k, i});
              if(board[j][k][i] == 0) vis[j][k][i] = -1;
            }
        }
    }
    
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        int curX, curY, curZ;
        tie(curX, curY, curZ) = cur;
        for(int dir = 0; dir < 6; dir++){
            int nx = curX + dx[dir];
            int ny = curY + dy[dir];
            int nz = curZ + dz[dir];
            if(nx < 0 || nx >= N || ny < 0 || ny >= M || nz < 0 || nz >= H) continue;
            if(vis[nx][ny][nz] >= 0) continue;
            vis[nx][ny][nz] = vis[curX][curY][curZ] + 1;                
            Q.push({nx, ny, nz});
        }
    }
    int day = 0;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < M; k++){
              if(vis[j][k][i] == -1){
                  cout << -1;
                  return 0;
              }
              day = max(day, vis[j][k][i]);
            }
        }
    }
   cout << day;
}