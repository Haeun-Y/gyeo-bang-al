//240203
//BOJ 16985 Maaaaaaaaaze
//GOLD 2
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int BOARD_NUM = 5;
const int MAX_ROUTE = BOARD_NUM * BOARD_NUM * BOARD_NUM + 1;
int minRoute = MAX_ROUTE;
int dz[6] = {-1, 1, 0, 0, 0, 0};
int dx[6] = {0, 0, -1, 1, 0, 0};
int dy[6] = {0, 0, 0, 0, -1, 1};
vector<vector<vector<bool>>> boards(BOARD_NUM, vector<vector<bool>>(BOARD_NUM, vector<bool>(BOARD_NUM, false)));
vector<vector<vector<bool>>> maze(BOARD_NUM, vector<vector<bool>>(BOARD_NUM, vector<bool>(BOARD_NUM, false)));
vector<bool> isUsed(BOARD_NUM, false);
typedef struct
{
  int z;
  int x;
  int y;
  int dist;
}block;
int coumputeRoute()
{
  if(!maze[0][0][0]) return MAX_ROUTE;
  block destination = {4, 4, 4, 0};
  queue<block> q;
  vector<vector<vector<bool>>> isVisited(BOARD_NUM, vector<vector<bool>>(BOARD_NUM, vector<bool>(BOARD_NUM, false)));
  q.push({0, 0, 0, 0});
  isVisited[0][0][0] = true;

  while(!q.empty())
  {
    block cur = q.front();
    q.pop();

    for(int i = 0; i<6; i++)
    {
      int nz = cur.z + dz[i];
      int nx = cur.x + dx[i];
      int ny = cur.y + dy[i];

      if(nz < 0 || nz >= BOARD_NUM || nx < 0 || nx >= BOARD_NUM || ny < 0 || ny >= BOARD_NUM) continue;
      if(isVisited[nz][nx][ny] || !maze[nz][nx][ny]) continue;

      if(nz == destination.z && nx == destination.x && ny == destination.y)
        return cur.dist+1;

      q.push({nz, nx, ny, cur.dist+1});
      isVisited[nz][nx][ny] = true;
    }

  }

  return MAX_ROUTE;

}
void rotateBoard(vector<vector<bool>>& v, int boardIdx, int rotateNum)
{
  if(rotateNum == 0)
    v = boards[boardIdx];
  else if(rotateNum == 1)
  {
    for(int i = 0; i<BOARD_NUM; i++)
    {
      for(int j = 0; j<BOARD_NUM; j++)
        v[j][4-i] = boards[boardIdx][i][j];
    }
  }
  else if(rotateNum == 2)
  {
    for(int i = 0; i<BOARD_NUM; i++)
    {
      for(int j = 0; j<BOARD_NUM; j++)
        v[4-i][4-j] = boards[boardIdx][i][j];
    }

  }
  else
  {
    for(int i = 0; i<BOARD_NUM; i++)
    {
      for(int j = 0; j<BOARD_NUM; j++)
        v[4-j][i] = boards[boardIdx][i][j];
    }
  }
  

}
void selectBoard(int idx)
{
  if(idx >= BOARD_NUM)
  {
    int route = coumputeRoute();
    if(route < minRoute) minRoute = route;
  }
  else
  {
    for(int i = 0; i<BOARD_NUM; i++)
    {
      if(isUsed[i]) continue;
      isUsed[i] = true;
      for(int j = 0; j<4; j++)
      {
        rotateBoard(maze[idx],i, j);
        selectBoard(idx+1);
      }
      isUsed[i] = false;
    }

  }

  
}
void printMinRoute()
{
  if(minRoute == MAX_ROUTE)
    cout << "-1";
  else cout << minRoute;
}
int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  for(int i = 0; i<BOARD_NUM; i++)
  {
    for(int j = 0; j<BOARD_NUM; j++)
    {
      for(int k = 0; k<BOARD_NUM; k++)
      {
        int num;
        cin >> num;
        boards[i][j][k] = num;
      }
    }
  }

  selectBoard(0);
  printMinRoute();
}