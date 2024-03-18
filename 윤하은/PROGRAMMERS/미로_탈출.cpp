//230316
//PROGRAMMERS 미로 탈출
//Lv.2
#include <bits/stdc++.h>
using namespace std;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int move(vector<string>& maps, pair<int, int> startPos, pair<int, int> endPos)
{
    int row = maps.size();
    int col = maps[0].length();
    vector<vector<bool>> isVisited(row, vector<bool>(col, false));
    vector<vector<int>> timeTaken(row, vector<int>(col, 0));
    queue<pair<int, int>> q;
    
    q.push(startPos);
    timeTaken[startPos.first][startPos.second] = 0;
    isVisited[startPos.first][startPos.second] = 0;
    
    while(!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
        
        for(int i = 0; i<4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            
            if(nx < 0 || nx >= row || ny < 0 || ny >= col) continue;
            if(maps[nx][ny] == 'X' || isVisited[nx][ny]) continue;
            
            timeTaken[nx][ny] = timeTaken[cur.first][cur.second] + 1;
            
            if(nx == endPos.first && ny == endPos.second) 
                return timeTaken[nx][ny];
            q.push({nx, ny});
            isVisited[nx][ny] = true;
        }
    }
    
    return -1;
    
}
int solution(vector<string> maps) {
    int answer = 0;
    pair<int, int> startPos, leverPos, endPos;
    for(int i = 0; i<maps.size(); i++)
    {
        for(int j = 0; j<maps[0].length(); j++)
        {
            if(maps[i][j] == 'S')
                startPos = {i, j};
            else if(maps[i][j] == 'L')
                leverPos = {i, j};
            else if(maps[i][j] == 'E')
                endPos = {i, j};
        }
    }
    int dist1 = move(maps, startPos, leverPos);
    int dist2 = move(maps, leverPos, endPos);
    if(dist1 == -1 || dist2 == -1)
        return -1;
    else return dist1 + dist2;
}