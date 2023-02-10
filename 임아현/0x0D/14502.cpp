#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int N, M, MAX, S;
int board[8][8];
int arr[4];
vector<pair<int, int>> VQ; //바이러스 위치 
vector<pair<int, int>> BQ;//빈 공간 위치 (idx 접근)

void bfs(){
    bool vis[8][8] = {0};
    queue<pair<int, int>> Q;
    for(int i = 0; i < VQ.size(); i++){
        Q.push({VQ[i].X, VQ[i].Y});
    }
    int cnt= 0;
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop(); 
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if(vis[nx][ny] || board[nx][ny] != 0) continue;
            vis[nx][ny] = 1;
            Q.push({nx, ny});
            cnt++;
        }
    }
    MAX = max(MAX, S - 3 - cnt); //빈공간 - 벽 세 개 - 전염된 공간? 
}

void choose(int k, int idx){
    if(k == 3){
        for(int i = 0; i < 3; i++){
            board[BQ[arr[i]].X][BQ[arr[i]].Y] = 1;
            bfs();
        }
        for(int i = 0; i < 3; i++){
            board[BQ[arr[i]].X][BQ[arr[i]].Y] = 0;
        }
        return;
    }
    for(int i = idx; i < BQ.size(); i++){
        arr[k] = i;
        choose(k + 1, i + 1);
    }
    
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  
  int cnt = 0;
  
  for(int i = 0; i < N; i++){
      for(int j = 0; j < M; j++){
          cin >> board[i][j];
          if(board[i][j] == 0){
              BQ.push_back({i, j});
              cnt++;
          }
          else if(board[i][j] == 2) VQ.push_back({i, j});
      }
  }
  S = BQ.size();
  //빈 공간 세 개 고르기
  choose(0, 0);
  cout << MAX;
}