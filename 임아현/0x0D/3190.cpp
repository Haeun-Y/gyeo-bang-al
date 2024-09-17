#include <bits/stdc++.h>
using namespace std;

#define T first
#define D second

int N, K, DC;
int cnt = 0; 
int dir = 0; // 현재 방향 (오른쪽)
int board[102][102]; // 0 빈칸 1 사과 -1 뱀
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
pair<int, int> head = {0, 0}; //뱀 머리 위치


int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> N >> K;
  while(K--){
      int r, c;
      cin >> r >> c;
      board[r - 1][c - 1] = 1; //사과 위치 표시
  }
  cin >> DC; //방향 변환 횟수
  queue <pair<int, char>> Q;
  queue <pair<int, int>> TQ; //꼬리 위치 
  while(DC--){
      int tm; char dir;
      cin >> tm >> dir;
      Q.push({tm, dir});
  }
  
  board[0][0] = -1; //뱀 시작 위치
  TQ.push({0, 0});
  auto cur = Q.front(); Q.pop();
  while(true){
        cnt++;
        int nx = head.first + dx[dir];
        int ny = head.second + dy[dir];
        //범위 넘은 경우(벽)
        if(nx < 0 || nx >= N || ny < 0 || ny >= N){
             cout << cnt;
             return 0;
        }
        if(board[nx][ny] == -1){
             cout << cnt;
             return 0;
        }
        //사과 만남 꼬리가 줄어들지 않음
        if(board[nx][ny] == 1){
            board[nx][ny] = -1;
            TQ.push({nx, ny});
        }
        else{
            auto tail = TQ.front(); TQ.pop();//TQ의 맨앞이 꼬리임
            board[tail.first][tail.second] = 0;
            board[nx][ny] = -1;
            TQ.push({nx, ny});
        }
        head.first += dx[dir];
        head.second += dy[dir];
        if(cnt == cur.T){
            if(cur.D == 'D')  dir = (dir + 1) % 4;
            else dir = (dir + 3) % 4;
            if(!Q.empty()) cur = Q.front(); Q.pop();
        }
  }
  cout << cnt;
}