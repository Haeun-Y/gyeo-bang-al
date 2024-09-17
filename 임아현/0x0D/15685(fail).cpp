#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int N;
int board[102][102];
int rx[3] = {1, 1, 0};
int ry[3] = {0, 1, 1};
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  while(N--){
      int x, y, d, g;
      cin >> x >> y >> d >> g;
      //시작 (0세대)
      vector<pair<int, int>> V;
      board[y][x] = 1; V.push_back({x, y});
      int nx = x + dx[d];
      int ny = y + dy[d];
      board[ny][nx] = 1; V.push_back({nx, ny});
      
      //1세대 ~ g세대
      while(g--){
          int idx = 0;
          auto end = V.back();
          pair<int, int> push_end;
          int vsize = V.size();
          while(idx < vsize - 1){
              auto cur = V[idx];
              int nx = 0, ny = 0;
              if(cur.X == end.X){
                  nx = cur.X + (end.Y - cur.Y);
                  ny = end.Y;
              }
              else if(cur.Y == end.Y){
                  nx = end.X;
                  ny = cur.Y + (cur.X - end.X);
              }
              else{
                  nx = end.X + (cur.Y - end.Y) * (-1);
                  ny = end.Y + (cur.X - end.X);
              }
              
              if(nx < 0 || nx > 100 || ny < 0 || ny > 100) {idx++; continue;}
              if(idx == 0){
                  push_end = make_pair(nx, ny);
              }
              else V.push_back({nx, ny});
              board[ny][nx] = 1;
              idx++;
           }
           V.push_back(push_end);
       }
  }
  int cnt = 0;
  
  for(int i = 0; i <= 100; i++){
      for(int j = 0; j <= 100; j++){
          if(!board[i][j]) continue;
          int flag = 1;
          for(int dir = 0; dir < 3; dir++){
             int NX = i + rx[dir];
             int NY = j + ry[dir];
             if(NX > 100 || NY > 100) continue;
             if(!board[NX][NY]) flag = 0;
           }
            if(flag){
                cnt++;
            }
        }
    }
    cout << cnt;
}