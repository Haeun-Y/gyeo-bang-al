#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool board[102][102];//true : retangle area, false : blank area
bool isVisited[102][102];
int main(void)
{
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);

    int row, col, k;//k is the number of the retangle
    cin >> col >> row >> k;

    for(int i = 0; i<k; i++)
    {
        pair<int, int> rightBottom;
        pair<int, int> leftUpper;

        cin >> rightBottom.first >> rightBottom.second >> leftUpper.first >> leftUpper.second;

        for(int x = rightBottom.first; x < leftUpper.first; x++)
        {
            for(int y = rightBottom.second; y < leftUpper.second; y++)
                board[x][y] = true;
        }
    }

    vector<int> area;
    queue<pair<int, int>> q;

    for(int i = 0; i<row; i++)
    {
        for(int j = 0; j<col; j++)
        {
            //retangle block or visited block
            if(board[i][j] || isVisited[i][j]) continue;

            isVisited[i][j] = true;
            q.push(make_pair(i, j));
            int width = 0;

            while(!q.empty()) 
            {
                pair<int, int> cur = q.front();
                q.pop();
                width++;

                for(int k = 0; k<4; k++)
                {
                    int nx = cur.first + dx[k];
                    int ny = cur.second + dy[k];

                    if(nx < 0 || nx >= row || ny < 0 || ny >= col) continue;
                    if(board[nx][ny] || isVisited[nx][ny]) continue;

                    isVisited[nx][ny] = true;
                    q.push(make_pair(nx, ny));
                }
            }

            area.push_back(width);
        }
    }

    sort(area.begin(), area.end());

    cout << area.size() << "\n";
    for(int i = 0; i<area.size(); i++)
        cout << area[i] << " ";

}