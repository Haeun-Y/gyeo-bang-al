//BOJ 5427 불
#include <bits/stdc++.h>
using namespace std;
//북남서동
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool isEdge(int row, int col, pair<int, int> dot)
{
    if(dot.first == 0 || dot.first == row-1 || dot.second == 0 || dot.second == col-1)
        return true;
    return false;
}
int bfs(vector<vector<char>>& v, int row, int col, pair<int, int> start)
{
    vector<vector<int>> fire(row, vector<int>(col, 10000));
    queue<pair<int, int>> q;

    for(int i = 0; i<row; i++)
    {
        for(int j = 0; j<col; j++)
        {
            if(v[i][j] == '*')
            {
                q.push({i, j});
                fire[i][j] = 0;

            }    
        }
    }

    //bfs for fire
    while(!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();

        for(int i = 0; i<4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx < 0 || nx >= row || ny < 0 || ny >= col) continue;
            if(fire[nx][ny] != 10000 || v[nx][ny] == '#') continue;

            fire[nx][ny] = fire[cur.first][cur.second] + 1;
            q.push({nx, ny});
        }

    }

    /*cout << "***fire***\n";
    for(int i = 0; i<row; i++)
    {
        for(int j = 0; j<col; j++)
        {
            if(v[i][j] == '#')
                cout << "# ";
            else cout << fire[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "***fire***\n";*/


    //bfs for 상근
    vector<vector<int>> distance(row, vector<int>(col, -1));
    queue<pair<int, int>> q2;

    q2.push(start);
    distance[start.first][start.second] = 0;

    while(!q2.empty())
    {
        pair<int, int> cur = q2.front();
        q2.pop();

        if(isEdge(row, col, cur)) return distance[cur.first][cur.second];

        for(int i = 0; i<4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx < 0 || nx >= row || ny < 0 || ny >= col) continue;
            if(distance[nx][ny] != -1 || v[nx][ny] == '#') continue;
            if(fire[nx][ny] <= distance[cur.first][cur.second] + 1) continue;

            distance[nx][ny] = distance[cur.first][cur.second] + 1;
            if(isEdge(row, col, {nx, ny})) return distance[nx][ny];
            q2.push({nx, ny});
        }
    }

    /*cout << "***SG***\n";
    for(int i = 0; i<row; i++)
    {
        for(int j = 0; j<col; j++)
        {
            if(v[i][j] == '#')
                cout << "# ";
            else cout << distance[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "***SG***\n";*/

    


    return -1;

}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;

    for(int i = 0; i<tc; i++)
    {
        int w, h;
        cin >> w >> h;

        int result = 0;

        vector<vector<char>> building(h, vector<char>(w, '!'));

        pair<int, int> start;
        for(int j = 0; j<h; j++)
        {
            for(int k =0; k<w; k++)
            {
                cin >> building[j][k];
                if(building[j][k] == '@')
                    start = {j, k};
            }
        }

        result = bfs(building, h, w, start);
        if(result == -1)
            cout << "IMPOSSIBLE\n";

        else cout << result+1 << "\n";

    }


}