//BOJ 2573 빙산
#include <bits/stdc++.h>
using namespace std;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int bfs(vector<vector<int>> & v)
{
    int result = 0;
    int row = v.size();
    int col = v[0].size();

    vector<vector<bool>> isVisit(row, vector<bool>(col, false));

    for(int i = 0; i<row; i++)
    {
        for(int j = 0; j<col; j++)
        {
            if(isVisit[i][j] || v[i][j] == 0) continue;

            result++;
            queue<pair<int, int>> q;
            q.push({i, j});
            isVisit[i][j] = true;

            while(!q.empty())
            {
                pair<int, int> cur = q.front();
                q.pop();

                for(int k = 0; k<4; k++)
                {
                    int nx = cur.first + dx[k];
                    int ny = cur.second + dy[k];

                    if(nx < 0 || nx >= row || ny < 0 || ny >= col) continue;
                    if(isVisit[nx][ny] || v[nx][ny] == 0) continue;

                    isVisit[nx][ny] = true;
                    q.push({nx, ny});

                }
            }

            




        }
    }

    return result;

}
void melt(vector<vector<int>> & v)
{
    int row = v.size();
    int col = v[0].size();

    vector<vector<int>> yearAfter(row, vector<int>(col, 0));

    for(int i = 0; i<row; i++)
    {
        for(int j = 0; j<col; j++)
        {
            if(v[i][j] == 0) continue;
            int total = 0;

            for(int k = 0; k<4; k++)
            {
                int nx = i + dx[k];
                int ny = j + dy[k];

                if(nx < 0 || nx >= row || ny < 0 || ny >= col) continue;
                if(v[nx][ny] == 0) total++;
            }

            yearAfter[i][j] = v[i][j] - total;
            if(yearAfter[i][j] < 0) yearAfter[i][j] = 0;
        }
    }
    v = yearAfter;

}
bool isAllmelted(vector<vector<int>> &v)
{
    for(int i = 0; i<v.size(); i++)
    {
        for(int j = 0; j<v[0].size(); j++)
        {
            if(v[i][j] > 0) return false;
        }
    }

    return true;

}
void printV(vector<vector<int>> &v)
{
    for(int i = 0; i<v.size(); i++)
    {
        for(int j = 0; j<v[0].size(); j++)
            cout << v[i][j] << " ";
        cout << "\n";
    }
}
int main(void)
{
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);
    
    int row, col;
    cin >> row >> col;

    int year = 0;

    vector<vector<int>> v(row, vector<int>(col, 0));

    for(int i = 0; i<row; i++)
    {
        for(int j = 0; j<col; j++)
            cin >> v[i][j];
    }

    while(bfs(v) == 1)
    {
        year++;
        melt(v);
        //printV(v);

        //빙산이 다 녹을 때까지 2덩어리 이상으로 분리되지 않은 경우
        if(isAllmelted(v)) 
        {
            year = 0;
            break;
        }
    }

    cout << year;
    

    

}