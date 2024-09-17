#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
string board[102]; //공백 없이 한 줄로...
int dis[102][102];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
  
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m; // n x m arr
  
  fill(&dis[0][0], &dis[n - 1][m], -1); //배열 초기화
  
  queue<pair<int, int>> Q;
  
    //미로 입력받음
  for(int i = 0; i < n; i++){
          cin >> board[i];
  }
  
  dis[0][0] = 1; //시작점, 방문함
  Q.push({0, 0});
  
  while(!Q.empty()){
      pair<int, int> cur = Q.front(); Q.pop();
      
      for(int dir = 0; dir < 4; dir++){
          int nx = cur.X + dx[dir];
          int ny = cur.Y + dy[dir];
          if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
          if(dis[nx][ny] >= 0 || board[nx][ny] == '0') continue;
          dis[nx][ny] = dis[cur.X][cur.Y] + 1; //이전 거리에서 한 칸 이동
          Q.push({nx, ny});
      }
  }
  cout << dis[n - 1][m - 1];
}