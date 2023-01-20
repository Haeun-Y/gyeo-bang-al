#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

string board[1002];
int dist[1002][1002];
int escape[1002][1002];  //j 이동 시간 저장하는 배열

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main (){
  ios::sync_with_stdio (0);
  cin.tie (0);

  int n, m;
  int nfire = 0;
  cin >> n >> m;

  int day = 0;
  queue <pair<int, int>> JQ; //지훈 위치
  queue <pair<int, int>> FQ; //불 위치
  
  for (int i = 0; i < n; i++){
      cin >> board[i];
    for (int j = 0; j < m; j++){
	  if (board[i][j] == 'J'){
	      JQ.push({i, j}); 
	      escape[i][j] = 1;
	      //dist[i][j] = 0;
	  }
	  else if (board[i][j] == 'F'){
	      nfire = 1;
	      FQ.push({i, j});
	      //escape[i][j] = 0;
	      dist[i][j] = 1;
	  }
	  else {
	      dist[i][j] = 0;
	      escape[i][j] = 0;
	  }
	}
  }
  if(!nfire)
      fill(&dist[0][0], &dist[n-1][m], 10000);

  while (!FQ.empty ()){
      pair <int, int>cur = FQ.front (); FQ.pop ();
      for (int dir = 0; dir < 4; dir++){
	    int nx = cur.X + dx[dir];
	    int ny = cur.Y + dy[dir];
	    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
	    if(dist[nx][ny] > 0 || board[nx][ny] == '#') continue;
	    dist[nx][ny] = dist[cur.X][cur.Y] + 1; //불이 퍼지는 시간 구하기
	    FQ.push({nx, ny});
      }
    }

  while(!JQ.empty()){
      pair <int, int>cur = JQ.front (); JQ.pop ();
      for (int dir = 0; dir < 4; dir++){
	    int nx = cur.X + dx[dir];
	    int ny = cur.Y + dy[dir];
	    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
	    if(escape[nx][ny] > 0 || board[nx][ny] == '#' || board[nx][ny] == 'F' || dist[nx][ny] <= escape[cur.X][cur.Y] + 1) continue;
	    escape[nx][ny] = escape[cur.X][cur.Y] + 1;
	    JQ.push({nx, ny});
      }
  }

  int sdis =  10000;
  
  //가장자리 돌면서 걸리는 시간이 뭔지 체크하기 
  for(int i = 0; i < 2; i++){
      if(escape[0][i] > 0)
        sdis = min(sdis, escape[0][i]);
  }
  
  for(int i = 0; i < m; i++){
      if(escape[n - 1][i]>0)
        sdis = min(sdis, escape[n - 1][i]);
  }
  
  for(int i = 1; i < n; i++){
      if(escape[i][0]>0)
        sdis = min(sdis, escape[i][0]);
  }
  
  for(int i = 1; i < n; i++){
      if(escape[i][m - 1]>0)
        sdis = min(sdis, escape[i][m - 1]);
  }

  if(sdis == 10000 || sdis < 0)
     cout << "IMPOSSIBLE";
  else
     cout << sdis;
}