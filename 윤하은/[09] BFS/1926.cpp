//BOJ 1926 그림
#include <bits/stdc++.h>
using namespace std;
int board[502][502];
bool isVisit[502][502];
int maxArea;
int paintingNum;
int n, m;//세로크기 n, 가로크기 m
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
void bfs()
{
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            if(board[i][j] == 0 || isVisit[i][j]) continue;

            queue<pair<int, int>> q;
            isVisit[i][j] = true;
            q.push({i, j});
            
            int area = 0;
            paintingNum++;

            while(!q.empty())
            {
                pair<int, int> cur = q.front();
                q.pop();
                area++;

                for(int k = 0; k < 4; k++)
                {
                    int nx = cur.first + dx[k];
                    int ny = cur.second + dy[k];

                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if(isVisit[nx][ny] || board[nx][ny] == 0) continue;

                    isVisit[nx][ny] = true;
                    q.push({nx, ny});
                }
            }

            if(area > maxArea) maxArea = area;
        }
    }

}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
            cin >> board[i][j];
    }

    bfs();

    cout << paintingNum << "\n" << maxArea;
}