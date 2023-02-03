//BOJ 1074 Z
#include <bits/stdc++.h>
using namespace std;
int visitNum;
vector<vector<int>> v; 
int dx[4] = {0, 0, 1, 1};
int dy[4] = {0, 1, 0, 1};
void zVisit(int n, pair<int, int> start)
{
  int x = start.first;
  int y = start.second;
  if(n==0)
  {
    v[x][y] = visitNum++;
    return;
  }
  else
  {
    int moves = pow(2, n-1);
    zVisit(n-1, start);
    zVisit(n-1, {x, y+moves});
    zVisit(n-1, {x+moves, y});
    zVisit(n-1, {x+moves, y+moves});
  }
  
}
void zVisit2(int n, pair<int, int> start)
{
  int x = start.first;
  int y = start.second;
  if(n==1)
  {
    for(int i = 0; i<4; i++)
      {
        v[x+dx[i]][y+dy[i]] = visitNum++;
      }
  }
  else
  {
    int moves = pow(2, n-1);
    zVisit2(n-1, start);
    zVisit2(n-1, {x, y+moves});
    zVisit2(n-1, {x+moves, y});
    zVisit2(n-1, {x+moves, y+moves});
    return;
  }
}
int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, r, c;
  cin >> n >> r >> c;

  int row = pow(2, n);

  for(int i = 0; i<row; i++)
    {
      vector<int> tmp(row, 0); 
      v.push_back(tmp);
    }

  zVisit2(n, {0, 0});
  cout << v[r][c];

  /*
  for(int i = 0; i<row; i++)
    {
      for(int j = 0; j<row; j++)
        printf("%2d ", v[i][j]);
      cout << "\n";
    }*/
  
}
