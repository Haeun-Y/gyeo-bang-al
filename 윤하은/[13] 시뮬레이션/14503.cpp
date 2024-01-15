//BOJ 14503 로봇 청소기
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> v;
vector<vector<bool>> isCleaned;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
bool isCleanedOrWall(pair<int, int> pos)
{
  for(int i = 0; i<4; i++)
    {
      int nx = pos.first + dx[i];
      int ny = pos.second + dy[i];

      if(v[nx][ny] != 1 && !isCleaned[nx][ny]) return false;
    }
  return true;
}
int clean(pair<int, int> robot, int direction)
{
  int result = 0;
  pair<int, int> position = robot;
  int curD = direction;
  
  while(1)
    {
      int check = 0;
      int x = position.first;
      int y = position.second;
      //현재 위치를 청소한다. 
      if(!isCleaned[x][y])
      {
        isCleaned[x][y] = true;
        result++;
      }

      while(1)
      {
        int leftSide = curD-1;
        if(leftSide == -1) leftSide = 3;

        if(!isCleaned[x+dx[curD]][y+dy[curD]])
        {
          position.first += dx[curD];
          position.second += dy[curD];
          curD = leftSide;
          isCleaned[position.first][position.second] = true;
          result++;
          check = 1;
          break;
        }
        else if(isCleanedOrWall(position))
        {
          pair<int, int> back = position;
          
          switch(curD)
            {
              //북쪽
              case 0:
                back.first += 1;
                break;
              //동쪽
              case 1:
                back.second -= 1;
                break;
              //남쪽
              case 2:
                back.first -= 1;
                break;
              //서쪽
              case 3:
                back.second += 1;
                break;
            }
          if(v[back.first][back.second] == 1)
          {
            check = -1;
            break;
          }

          position = back;
          continue;
          
        }
        else
        {
          curD = leftSide;
          continue;
        }

        

      }
      

      if(check==1)
        continue;
      else if(check == -1)
        break;
      
    }
  return result;
  
}
int main(void)
{
  //ios::sync_with_stdio(false);
  //cin.tie(NULL);

  int row, col;
  cin >> row >> col;
  vector<int> tmp(col);
  vector<bool> tmp2(col);

  for(int i = 0; i<row; i++)
    {
      v.push_back(tmp);
      isCleaned.push_back(tmp2);
    }

  int direction;
  pair<int, int> robot;

  cin >> robot.first >> robot.second;
  cin >> direction;

  for(int i = 0; i<row; i++)
    {
      for(int j = 0; j<col; j++)
        cin >> v[row][col];
    }

  cout << clean(robot, direction);
  
  

  
}
