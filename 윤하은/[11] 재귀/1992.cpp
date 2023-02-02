//BOJ 1992 쿼드트리
#include <bits/stdc++.h>
using namespace std;
vector<vector<char>> qtree;
string result;
char isSame(int n, pair<int, int> start)
{
  int x = start.first;
  int y = start.second;
  char ch = qtree[x][y];

  for(int i = x; i< x+n; i++)
    {
      for(int j = y; j<y+n; j++)
        {
          if(qtree[i][j] != ch)
              return 'x';
        }
    }
  return ch;
}
void CompressQuadTree(int n, pair<int, int> start)
{
  char ch = isSame(n, start);
  if(ch != 'x')
  {
    result += ch;
    return;
  }
  else
  {
    result += '(';
    int num = n/2;
    int x = start.first;
    int y = start.second;
    CompressQuadTree(num, start);
    CompressQuadTree(num, {x, y+num});
    CompressQuadTree(num, {x+num, y});
    CompressQuadTree(num, {x+num, y+num});
    result += ')';
  }
  
}
int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  vector<char> v(n);
  for(int i = 0; i<n; i++)
    qtree.push_back(v);

  for(int i = 0; i<n; i++)
    {
      for(int j = 0; j<n; j++)
          cin >> qtree[i][j];
    }
  CompressQuadTree(n, {0, 0});

  cout << result;
  
}
