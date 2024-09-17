//240103
//BOJ 2206 벽 부수고 이동하기
//GOLD 3
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
vector<vector<bool>> isVisited;
vector<vector<int>> minFromStart;
vector<vector<int>> minFromExit;
bool maze[1002][1002];
int row, col;
void findRoute(pair<int, int>& startBlock, vector<vector<int>>& v)
{
    isVisited = vector<vector<bool>>(row, vector<bool>(col, false));

    queue<pair<int, int>> q;
    q.push(startBlock);
    isVisited[startBlock.first][startBlock.second] = true;
    v[startBlock.first][startBlock.second] = 1;

    while(!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();

        for(int i = 0; i<4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            int nr = v[cur.first][cur.second] + 1;

            if(nx < 0 || nx >= row || ny < 0 || ny >= col) continue;
            if(isVisited[nx][ny] || !maze[nx][ny]) continue;
            
            q.push(make_pair(nx, ny));
            isVisited[nx][ny] = true;
            v[nx][ny] = nr;
        }

    }
    
}
int breakWall(pair<int, int>& wallPos)
{
    int s = 1000005;
    int e = 1000005;

    for(int i = 0; i<4; i++)
    {
        int nx = wallPos.first + dx[i];
        int ny = wallPos.second + dy[i];

        if(nx < 0 || nx >= row || ny < 0 || ny >= col) continue;
        if(!maze[nx][ny]) continue;

        if(minFromStart[nx][ny] != 0 && s > minFromStart[nx][ny])
            s = minFromStart[nx][ny];

        if(minFromExit[nx][ny] != 0 && e > minFromExit[nx][ny])
            e = minFromExit[nx][ny];

        
    }

    if(s == 1000005 || e == 1000005) return 0;
    else return s+e+1;

}
int findDirectRoute(pair<int, int>& pos)
{
    int s = minFromStart[pos.first][pos.second];
    int e = minFromExit[pos.first][pos.second];
    
    if(s != 0 && e != 0) return s + e - 1;
    else return 0;
}
int findMinRoute()
{
    int minRoute = 1000005;
    for(int i = 0; i<row; i++)
    {
        for(int j = 0; j<col; j++)
        {
            pair<int, int> pos = make_pair(i, j);
            int cnt;

            if(!maze[i][j])//wall block 
                cnt = breakWall(pos);
            else 
                cnt = findDirectRoute(pos);
            
            if(cnt != 0 && cnt < minRoute)
            {
                minRoute = cnt;
                //cout << "(" << i << ", " << j << ") : " << cnt << "\n";
            }
        }
    }
    if(minRoute == 1000005)
    {
        //cout << "no route\n";
        return -1;
    }
    else return minRoute;

}
void printVector(vector<vector<int>>& v)
{
    cout << "***printVector***\n";
    for(int i = 0; i<row; i++)
    {
        for(int j = 0; j<col; j++)
            printf("%3d", v[i][j]);
        cout << "\n";
    }
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> row >> col;

    for(int i = 0; i<row; i++)
    {
        for(int j = 0; j<col; j++)
        {
            char ch;
            cin >> ch;
            if(ch == '0')//not wall
                maze[i][j] = true;
        }
    }

    minFromStart = vector<vector<int>>(row, vector<int>(col, 0));
    minFromExit = vector<vector<int>>(row, vector<int>(col, 0));

    pair<int, int> startBlock = make_pair(0, 0);
    pair<int, int> exitBlock = make_pair(row-1, col-1);
    
    findRoute(startBlock, minFromStart);
    findRoute(exitBlock, minFromExit);

    //printVector(minFromStart);
    //printVector(minFromExit);

    cout << findMinRoute();
}