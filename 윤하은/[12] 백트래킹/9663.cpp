//BOJ N-Queen
//수정
#include <bits/stdc++.h>
using namespace std;
vector<vector<bool>> chessBoard;
int result;
void putQueen(int cur, pair<int, int> before, int n)
{
  if(cur == n)
  {
    result++;
    return;
  }
  else
  {
    int x = before.first;
    int y = before.second;
    
    for(int i = x; i<n; i++)
      {
        for(int j = y; y<n; y++)
          {
            bool check = false;
            
            for(int k = 0; k<n; k++)
              {
                if(chessBoard[i][k] || chessBoard[k][j])
                {
                  check = true;
                  break;
                }
              }
            for(int k = x+1, l = y+1; k<n && l<n; k++, l++)
              {
                if(chessBoard[k][l])
                {
                  check = true;
                  break;
                }
                
              }
            for(int k = x-1, l = y-1; k>=0 && l >=0; k--, l--)
              {
                if(chessBoard[k][l])
                {
                  check = true;
                  break;
                }
              }
            if(check)
              continue;
            cout << "put [" << i << ", " << j << "]\n"; 
            chessBoard[i][j] = true;
            putQueen(cur+1, {i, j}, n);
            chessBoard[i][j] = false;
          }
      }
    
  }
  
}
int main(void)
{
  //ios::sync_wtih_stdio(false);
  //cin.tie(NULL);

  int n;
  cin >> n;

  vector<bool> v(n, false);

  for(int i = 0; i<n; i++)
    chessBoard.push_back(v);

  putQueen(0, {0,0}, n);
  cout << result;

  

  
}
