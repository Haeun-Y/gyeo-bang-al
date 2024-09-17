#include <iostream>
#include <vector>
#include <utility>
using namespace std;
vector<vector<char>> v;
void printBlank(int n, pair<int, int> pos)
{
  int x = pos.first;
  int y = pos.second;
  
  for(int i = x; i< x+n; i++)
    {
      for(int j = y; j< y+n; j++)
          v[i][j] = ' ';
    }
}
void printStar(int n, pair<int, int> pos)
{
  int x = pos.first;
  int y = pos.second;
  
  if(n == 1)
  {
    v[x][y] = '*';
    return;
  }
  else
  {
    int num = n/3;
    for(int i = x; i<x+n; i+=num)
      {
        for(int j = y; j<y+n; j+=num)
          {
            if(i == (x+num) && j == (y+num))
              printBlank(num, {i, j});
            else
              printStar(num, {i, j});
          }
      }
  }
  
}
int main(void)
{
  //ios::sync_with_stdio(false);
  //cin.tie(NULL);

  int n;
  cin >> n;

  v = vector<vector<char>>(n, vector<char>(n));

  printStar(n, make_pair(0,0));

  for(int i = 0; i<n; i++)
    {
      for(int j = 0; j<n; j++)
          cout << v[i][j];
      cout << "\n";
    }
  
}