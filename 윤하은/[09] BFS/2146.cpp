//240118
//BOJ 2146 다리 만들기
//GOLD 3
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0}; 
int land[101][101];
vector<vector<bool>> isVisited;
vector<vector<pair<int, int>>> edges;
int n;
void findIsland()
{
    isVisited = vector<vector<bool>>(n, vector<bool>(n, false));
    queue<pair<int, int>> q;

    int landNum = 0;

    for(int i = 0; i<n; i++)
    {
        for(int j =0; j<n; j++)
        {
            if(isVisited[i][j] || land[i][j] == 0) continue;
            vector<pair<int, int>> edge; 
            q.push(make_pair(i, j));
            isVisited[i][j] = true;
            landNum++;
        
            while(!q.empty())
            {
                pair<int, int> cur = q.front();
                land[cur.first][cur.second] = landNum;
                q.pop();
                 
                bool isAdjacentToSee = false;
                for(int k = 0; k<4; k++)
                {
                    int nx = cur.first + dx[k];
                    int ny = cur.second + dy[k];

                    //outofIndex 먼저 확인해줘야함
                    if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if(isVisited[nx][ny]) continue;
                    if(land[nx][ny] == 0)//(nx, ny) is sea
                    {
                        isAdjacentToSee = true;
                        continue;
                    }
                    
                    isVisited[nx][ny] = true;
                    q.push(make_pair(nx, ny));
                }
                
                if(isAdjacentToSee)
                    edge.push_back(make_pair(cur.first, cur.second));
            }
            edges.push_back(edge);
        }
    }
}
int findBridge()
{
    int minLength = n * n; 

    for(int i = 0; i<edges.size(); i++)
    {
        //i번째 섬을 기준으로 경로 탐색
        isVisited = vector<vector<bool>>(n, vector<bool>(n, false));
        queue<pair<int, int>> q;
        vector<vector<int>> dis(n, vector<int>(n, 0));

        int landNum = land[edges[i][0].first][edges[i][0].second];

        //cout << landNum << " land start\n";
        
        for(int j = 0; j<edges[i].size(); j++)
        {
            q.push(edges[i][j]);
            isVisited[edges[i][j].first][edges[i][j].second] = true;
        }
        
        bool flg = true;
        while(!q.empty() && flg)
        {
            pair<int ,int> cur = q.front();
            q.pop();

            //cout << "current pos : (" << cur.first << ", " << cur.second << ")\n";

            for(int j = 0; j<4; j++)
            {
                int nx = dx[j] + cur.first;
                int ny = dy[j] + cur.second;

                if(nx < 0 || nx >= n || ny < 0 || ny >= n)
                {
                    //cout << "(" << nx << ", " << ny << ") is outOfIndex\n"; 
                    continue;
                }
                if(isVisited[nx][ny] || land[nx][ny] == landNum)
                {
                    //cout << "(" << nx << ", " << ny << ") is visited or same island\n"; 
                    continue;
                }
                if(land[nx][ny] != 0)
                {
                    //cout << "(" << nx << ", " << ny << ") is other island\n"; 
                    flg = false;
                    if(minLength > dis[cur.first][cur.second])
                        minLength =  dis[cur.first][cur.second];
                    break;
                } 
                //cout << "(" << nx << ", " << ny << ") is sea\n"; 

                //cout << "push in queue : (" << nx << ", " << ny << ")\n";
                q.push(make_pair(nx, ny));
                isVisited[nx][ny] = true;
                dis[nx][ny] = dis[cur.first][cur.second] + 1;
            }
        }
    }
    return minLength;
}
void printLand()
{
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
            cout << land[i][j] << " ";
        cout << "\n";
    }
}
void printEdges()
{
    for(int i = 0; i< edges.size(); i++)
    {
        for(int j = 0; j<edges[i].size(); j++)
            cout << "(" << edges[i][j].first << ", " << edges[i][j].second << ")\t";
        cout << "\n";
    }
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
            cin >> land[i][j];
    }

    findIsland();
    //printLand();
    //printEdges();
    cout << findBridge();
    
}