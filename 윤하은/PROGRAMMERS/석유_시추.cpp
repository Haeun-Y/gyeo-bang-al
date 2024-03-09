//240309
//PROGRAMMERS [PCCP 기출문제] 2번 석유 시추
//Lv.2
#include <bits/stdc++.h>
using namespace std;
void addResult(vector<int>& oil, vector<bool>& existsOil, int area)
{
    for(int i = 0; i<existsOil.size(); i++)
    {
        if(!existsOil[i]) continue;
        oil[i] += area;
    }
}
int solution(vector<vector<int>> land) {
    int answer = 0;
    int n = land.size();
    int m = land[0].size();
    vector<int> oil(m, 0);
    
    vector<vector<bool>> isVisited(n, vector<bool>(m, false));
    queue<pair<int, int>> q;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            if(isVisited[i][j]) continue;
            if(land[i][j] == 0) continue;
            
            vector<bool> existsOil(m, false);
            existsOil[j] = true;
            q.push({i, j});
            isVisited[i][j] = true;
            int area = 0;
            
            while(!q.empty())
            {
                pair<int, int> cur = q.front();
                q.pop();
                area++;
                
                for(int k = 0; k<4; k++)
                {
                    int nx = cur.first + dx[k];
                    int ny = cur.second + dy[k];
                    
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if(isVisited[nx][ny] || land[nx][ny] == 0) continue;
                    
                    existsOil[ny] = true;
                    q.push({nx, ny});
                    isVisited[nx][ny] = true;
                }

            }
            addResult(oil, existsOil, area);
            
        }
    }
    return *max_element(oil.begin(), oil.end());
}