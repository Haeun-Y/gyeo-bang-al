//BOJ 1926 그림
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> v;
vector<vector<bool>> isVisited;
//상하좌우
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int numOfPaintings;
int maxArea;
int row, col;
void findPaintings()
{
    for(int i = 0; i< row; i++)
    {
        for(int j = 0; j<col; j++)
        {
            if(isVisited[i][j]) continue;
            
            queue<pair<int, int>> q;
            int curArea = 1;
            numOfPaintings++;
            isVisited[i][j] = true;
            q.push({i, j});
            
            while(!q.empty())
            {
                pair<int, int> curPosition = q.front();
                q.pop();
                for(int k = 0; k<4; k++)
                {
                    int nx = dx[k] + curPosition.first;
                    int ny = dy[k] + curPosition.second;
                    
                    if(isVisited[nx][ny]) continue;
                    if(nx < 0 || nx >= row || ny < 0 || ny >= col) continue;
                    
                    q.push({nx, ny});
                    isVisited[nx][ny] = true;
                    curArea++;
                }
            }
            if(curArea > maxArea) maxArea = curArea;
            
        }
    }
}
int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(NULL)
    
    cin >> row >> col;
    v = vector<vector<int>>(row, vector<int>(col));
    isVisited = vector<vector<bool>>(row, vector<bool>(col));
    
    for(int i = 0; i<row; i++)
    {
        for(int j = 0; j<col; j++)
            cin >> v[i][j];
    }
    
    findPaintings();
    
    cout << numOfPaintings << "\n" << maxArea;
    
    
    
    
    return 0;
}
