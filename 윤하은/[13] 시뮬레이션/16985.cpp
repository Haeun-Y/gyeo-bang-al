#include <bits/stdc++.h>
using namespace std; 
int dy[6] = { 0,0,0,0,1,-1 }; 
int dx[6] = { 0,0,1,-1,0,0 }; 
int dz[6] = { 1,-1,0,0,0,0 }; 
const int n = 5; 
int ret; 
int BFS(vector<vector<vector<int>>>& board) 
{ 	
  if (board[0][0][0] == 0) 
    return -1; 	
  int d[n][n][n]; 	
  memset(d, -1, sizeof(d)); 	
  queue<pair<int, pair<int, int>>> q; 	
  q.push({ 0,{0,0} }); 	
  d[0][0][0] = 0; 	
  while (!q.empty()) 	
  { 		
    int z = q.front().first; 		
    int x = q.front().second.second; 		
    int y = q.front().second.first; 		
    q.pop(); 		
    for (int i = 0; i < 6; ++i) 		
    { 			
      int ny = y + dy[i]; 			
      int nx = x + dx[i]; 			
      int nz = z + dz[i]; 			
      if (!(0 <= ny && ny < n && 0 <= nx && nx < n && 0<= nz && nz < n)) continue; 			 			
      if (board[nz][ny][nx] ==1 && d[nz][ny][nx] == -1) { 				d[nz][ny][nx] = d[z][y][x] + 1; 				
        q.push({ nz,{ny,nx} }); 			
        } 		
      } 	
    } 	 	
  return d[n-1][n-1][n-1]; 
} 
void rotate(vector<vector<int>>& b) 
{ 	//90도 회전시킨다 	
  vector<vector<int>> temp(n, vector<int>(n)); 	
  for (int i = 0; i < n; ++i) 		
    for (int j = 0; j < n; ++j) 		
    { 			
      temp[i][n-1-j] = b[j][i]; 		
    } 	
  for (int i = 0; i < n; ++i) 		
    for (int j = 0; j < n; ++j) 		
    { 			
      b[i][j] = temp[i][j]; 		
    }
} 
void solve(int begin, vector<vector<vector<int>>>& board) { 	
  if (begin == n) 
  { 		
    return; 	
  } 	
  for (int i = 0; i < 4; ++i) 	
  { 		
    int cand = BFS(board); 		
    if (cand != -1) 
    { 			
      if (ret == -1 || ret > cand) 				
        ret = cand; 		
    } 		
    solve(begin + 1, board); 		
    rotate(board[begin]); 	
    } 
  } 
int main() 
{ 	
  vector<vector<vector<int>>> first(n); 	
  for (int i = 0; i < n; ++i) 
  { 		
    first[i].resize(n, vector<int>(n)); 		
    for (int j = 0; j < n; ++j) 			
      for (int k = 0; k < n; ++k) 			
      { 				
        cin >> first[i][j][k]; 			
      } 	
  } 	
  vector<int> order; 	
  for (int i = 0; i < n; ++i) 
  { 		
    order.push_back(i); 	
  } 	
  int ans = -1; 	
  ret = -1; 	
  do 
  { 		
    vector<vector<vector<int>>> board(n); 		
    for (int i = 0; i < n; ++i) 			
      board[order[i]] = first[i]; 		
    solve(0, board); 		
    if (ret != -1) 
    { 			
      if (ans == -1 || ans > ret) 				
        ans = ret; 		
    } 	
  } while (next_permutation(order.begin(), order.end())); 	cout << ans << "\n"; 	
  return 0; 
}
