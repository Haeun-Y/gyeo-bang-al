//BOJ 1012 유기농 배추
#include <bits/stdc++.h>
using namespace std;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;

    for(int i = 0; i<tc; i++)
    {
        vector<vector<int>> field(52, vector<int>(52,0));
        vector<vector<bool>> isVisit(52, vector<bool>(52, false));
        int result = 0;

        int row, col, cabbageNum;
        cin >> col >> row >> cabbageNum;

        for(int j = 0; j<cabbageNum; j++)
        {
            int x, y;
            cin >> y >> x;
            field[x][y] = 1;
        }

        for(int j = 0; j<row; j++)
        {
            for(int k = 0; k<col; k++)
            {
                if(field[j][k] == 0 || isVisit[j][k]) continue;

                queue<pair<int, int>> q;
                q.push({j, k});
                isVisit[j][k] = true;
                result++;

                while(!q.empty())
                {
                    pair<int, int> cur = q.front();
                    q.pop();

                    for(int l = 0; l<4; l++)
                    {
                        int nx = cur.first + dx[l];
                        int ny = cur.second + dy[l];

                        if(nx < 0 || nx >= row || ny < 0 || ny >= col) continue;
                        if(field[nx][ny] == 0 || isVisit[nx][ny]) continue;

                        isVisit[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }

            }
        }
        cout << result << "\n";
    }


}