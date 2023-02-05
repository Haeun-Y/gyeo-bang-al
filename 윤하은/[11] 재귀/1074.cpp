//BOJ 1074 Z
#include <bits/stdc++.h>
using namespace std;
int visitNum; 
int r;
int c;
int result;
int dx[4] = {0, 0, 1, 1};
int dy[4] = {0, 1, 0, 1};
void zVisit(int row, pair<int, int> start)
{
  int x = start.first;
  int y = start.second;
  if(row==1)
  {
    if(x == r && y == c)
      result = visitNum;
    visitNum++;
    return;
  }
  else
  {
    int moves = row/2;
    zVisit(moves, start);
    zVisit(moves, {x, y+moves});
    zVisit(moves, {x+moves, y});
    zVisit(moves, {x+moves, y+moves});
  }
  
}
void zVisit2(int row, pair<int, int> start)
{
  int x = start.first;
  int y = start.second;
  if(row==1)
  {
    if(x == r && y == c)
          result = visitNum;
        visitNum++;
    return;
  }
  else
  {
    int moves = row/2;
    int moves2 = moves * moves;
    for(int i = 0; i<4; i++)
      {
        int nx = x + dx[i] * moves;
        int ny = y + dy[i] * moves;
        if(nx <= r && nx+moves > r && ny <= c && ny+moves > c)
          zVisit2(moves, {nx, ny});
      
        else visitNum += moves2;
      }
    return;
  }
}
int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n >> r >> c;

  int row = pow(2, n);

  zVisit2(row, {0, 0});
  cout << result;
  
}
