#include <bits/stdc++.h>
using namespace std;

int N, M, R, C, D;//가로 세로 좌표(R, C), 방향 (0-3, 북동남서 순서)
int cnt = 0; //청소하는 구역
int board[52][52];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};


bool move(){
    //왼쪽으로 회전하기
    //D기준 0 ->3 3 ->2 2 -> 1 1-> 0 
    //0: C-- 1: R++ 2: C++ 3: R--
    for(int i = 0; i < 4; i++){
        D = (D + 3) % 4;
        int nx = R + dx[D]; int ny = C + dy[D];
        if(board[nx][ny] == 0){
            R += dx[D];
            C += dy[D];
            return true;
        }
    }
    return false;
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> N >> M;
  cin >> R >> C >> D;
  for(int i = 0; i < N; i++){
      for(int j = 0; j < M; j++){
          cin >> board[i][j];
      }
  }
  //네 방향이 막혀 있어서 index 넘어갈 걱정 X...
  
  while(true){
      //현재 위치 청소 
      if(board[R][C] == 0) cnt++;
      board[R][C] = -1;
     
      if(move()) continue; //이동 0
      else{
          int nx = R - dx[D]; int ny = C - dy[D];
          if(board[nx][ny] == 1) break; //뒤가 막혀 있음
          else{
              R -= dx[D];
              C -= dy[D];
          }
      }
  }
  cout << cnt;
}