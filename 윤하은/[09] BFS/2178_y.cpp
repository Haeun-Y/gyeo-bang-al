#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int>> maze;
vector<vector<bool>> isVisited;
//상하좌우
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
typedef struct 
{
    int x;
    int y; 
    int path;
}space;
int findMaze(int n, int m) {
    
    int shortPath = 0;
    queue<space> q;
    q.push({0, 0, 1});//미로의 시작점

    while(!q.empty())
    {
        space cur = q.front();
        q.pop();

        for(int i = 0 ; i<4; i++)
        {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(!maze[nx][ny] || isVisited[nx][ny]) continue;
            if(nx == n && ny == m) return cur.path+1;//미로 도착
            isVisited[nx][ny] = true;
            
            q.push({nx, ny, cur.path+1});
            
        }
    }
         
}
int main(void)
{
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    maze = vector<vector<int>>(n, vector<int>(m));
    isVisited = vector<vector<bool>>(n, vector<bool>(m));

    for(int i = 0; i<n; i++) 
    {
        string str;
        cin >> str;

        for(int j = 0; j<m; j++)
            maze[i][j] = str[j];
    }
    cout << findMaze(n, m);
}