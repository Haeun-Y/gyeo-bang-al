//실패함 코드 정답 확인...
#include <bits/stdc++.h>
using namespace std;

int n, m;
bool board[502][502];
int b[502][502];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int mx, sum;

//범위 체크
bool oob(int x, int y) {
  return (x >= n || x < 0 || y >= m || y < 0);
}

//백트래킹을 이용한 풀이 방법
void solve(int cx, int cy, int cnt) {
  if(cnt == 4) {
    mx = max(mx, sum);
    return;
  }
  
  //BFS, 백트래킹
  int nx, ny;
  for(int dir = 0; dir < 4; dir++) {
    nx = cx + dx[dir];
    ny = cy + dy[dir];
    if(oob(nx, ny)) continue;
    if(board[nx][ny]) continue;
    sum += b[nx][ny];
    board[nx][ny] = 1;
    solve(nx, ny, cnt + 1);
    // ㅏ ㅗ ㅓ ㅜ BFS 길이가 3임 따로 처리해야 됨
    if(cnt == 2)
      solve(cx, cy, cnt + 1);
    sum -= b[nx][ny];
    board[nx][ny] = 0;
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      cin >> b[i][j];
  
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++) {
      sum = b[i][j];
      board[i][j] = 1;
      solve(i, j, 1);
      board[i][j] = 0;
    }
  cout << mx << '\n';
}