//240418
//BOJ 1260 DFS와 BFS
//SILVER 2
//TODO : dfs 코드 수정
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
vector<vector<bool>> g;
int nodeNum, nodeMaxIdx, edgeNum, startIdx;
void dfs()
{
    vector<bool> isVisited(nodeNum + 1, false);
    stack<int> s;
    s.push(startIdx);

    while(!s.empty())
    {
        int cur = s.top();
        s.pop();
        if(!isVisited[cur])
        {
            isVisited[cur] = true;
            cout << cur << " ";
        }

        for(int i =nodeNum; i>=1; i--)
        {
            if(!g[cur][i] || isVisited[i]) continue;
            //cout << i << " is pushed in stack\n";
            s.push(i);
        }
    }
    cout << "\n";


}
void bfs()
{
    vector<bool> isVisited(nodeNum + 1, false);
    queue<int> q;
    q.push(startIdx);
    isVisited[startIdx] = true;

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        cout << cur << " ";

        for(int i = 1; i<= nodeNum; i++)
        {
            if(!g[cur][i] || isVisited[i]) continue;
            q.push(i);
            isVisited[i] = true;
        }
    }

}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> nodeNum >> edgeNum >> startIdx;

    g = vector<vector<bool>>(nodeNum+1, vector<bool>(nodeNum+1, false));
    for(int i = 0; i<edgeNum; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a][b] = g[b][a] = true;
    }

    dfs();
    bfs();

}