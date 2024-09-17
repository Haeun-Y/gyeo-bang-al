//240407
//BOJ 17141 연구소2
//GOLD 4
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int n, virusNum;
vector<vector<int>> lab;
vector<pair<int, int>> virusPos;
int wallNum;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
void printVirus(vector<vector<int>>& v)
{
    cout << "*****\n";
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            if(lab[i][j] == 1)
                cout << "- ";
            else cout << v[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "*****\n";
}
int infect(vector<pair<int, int>>& virus)
{
    vector<vector<int>> visitInfo(n, vector<int>(n, -1));
    queue<pair<int, int>> q;

    for(int i = 0; i<virus.size(); i++)
    {
        pair<int, int> cur = virus[i];
        q.push(cur);
        visitInfo[cur.first][cur.second] = 0;
    }

    int infectedNum = virus.size();
    int result = 0;

    while(!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();

        for(int i = 0; i<4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(lab[nx][ny] == 1 || visitInfo[nx][ny] != -1) continue;

            visitInfo[nx][ny] = visitInfo[cur.first][cur.second] + 1;
            result = max(result, visitInfo[nx][ny]);
            q.push({nx, ny});
            infectedNum++;
        }

    }

    //printVirus(visitInfo);

    if(infectedNum == n * n - wallNum)
        return result;
    else return 0x7fffffff;
}
int putVirus()
{
    vector<int> v(virusPos.size(), 1);
    for(int i = 0; i<virusNum; i++)
        v[i] = 0;
    
    int result = 0x7fffffff;
    do
    {
        vector<pair<int, int>> virus;
        for(int i = 0; i<v.size(); i++)
        {
            if(v[i] == 0)
                virus.push_back(virusPos[i]);
        }
        result = min(result, infect(virus));

    }while(next_permutation(v.begin(), v.end()));

    if(result == 0x7fffffff) return -1;
    else return result;

}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> virusNum;

    lab = vector<vector<int>>(n, vector<int>(n, 0));
    wallNum = 0;

    for(int i = 0; i<n; i++)
    {
        for(int j = 0 ;j<n; j++)
        {
            cin >> lab[i][j];
            if(lab[i][j] == 2)
                virusPos.push_back({i, j});
            else if(lab[i][j] == 1)
                wallNum++;
        }
    }

    cout << putVirus();
}