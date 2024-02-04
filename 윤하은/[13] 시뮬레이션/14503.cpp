//240204
//BOJ 14503 로봇청소기
//GOLD 5
#include <iostream>
#include <vector>
using namespace std;
typedef struct
{
  int x;
  int y;
  int d;//direction
}robot;
robot cleaner;
const int NOT_CLEANED = 0;
const int WALL = 1;
const int CLEANED = 2;
int row, col;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
vector<vector<int>> room;
int cleanRoom()
{
  int area = 0;
  bool isActivated = true;

  while(isActivated)
  {
    if(room[cleaner.x][cleaner.y] == NOT_CLEANED)
    {
      room[cleaner.x][cleaner.y] = CLEANED;
      area++;
    }
    bool isNotcleanedSpaceExist = false;
    for(int i = 0; i<4; i++)
    {
      cleaner.d = (cleaner.d+3)%4;
      int nx = cleaner.x + dx[cleaner.d];
      int ny = cleaner.y + dy[cleaner.d];
      if(nx < 0 || nx >= row || ny < 0 || ny >= col) continue;
      if(room[nx][ny] == NOT_CLEANED)
      {
        cleaner.x = nx;
        cleaner.y = ny;
        isNotcleanedSpaceExist = true;
        break;
      }
    }
    if(!isNotcleanedSpaceExist)
    {
      int nx = cleaner.x - dx[cleaner.d];
      int ny = cleaner.y - dy[cleaner.d];
      if(nx < 0 || nx >= row || ny < 0 || ny >= col || room[nx][ny] == WALL)
        isActivated = false;
      else
      {
        cleaner.x = nx;
        cleaner.y = ny;
      }
    }

      
  }
  return area;
}
int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> row >> col;
  room = vector<vector<int>>(row, vector<int>(col, 0));
  cin >> cleaner.x >> cleaner.y >> cleaner.d;

  for(int i = 0; i<row; i++)
  {
    for(int j = 0; j<col; j++)
      cin >> room[i][j];
  }

  cout << cleanRoom();
}