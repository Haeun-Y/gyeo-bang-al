#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int board[502][502];
bool vis[502][502];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
  
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  
  int cnt = 0; //그림의 갯수
  int max = 0; //최대값
  
  for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
          cin >> board[i][j];
      }
  }
  
  int temp = 0;
  //for문 돌면서 bfs 시작점 찾기
  for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
          if(board[i][j] == 1 && vis[i][j] == 0){
              temp = 0;
              cnt++; //그림의 시작점이니까 개수 count
              queue<pair<int, int>> Q;
              //시작점 push
              vis[i][j] = 1;
              Q.push({i, j});
              
              while(!Q.empty()){
                temp++;
                pair<int, int> cur = Q.front(); Q.pop(); //시시작점이니까
                for(int dir = 0; dir < 4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir]; //좌표 정하기
                    if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                      if(board[nx][ny] == 1 && vis[nx][ny] == 0){
                          vis[nx][ny] = 1;
                          Q.push({nx, ny});
                      }
                    }
                }
              }
              if(max < temp) max = temp;
          }
      }
  }
  cout << cnt << '\n' << max;
}