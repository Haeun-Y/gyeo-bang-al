#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int board[27][27];
bool vis[27][27];
vector<int> V;

int main()
{
    int N;
    cin >> N;
    
    for(int i = 0; i < N; i++){
        string num;
        cin >> num;
        for(int j = 0; j < N; j++){
            board[i][j] = num[j] - 48;
        }
    }  
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(!board[i][j] || vis[i][j]) continue;
            queue<pair<int, int>> Q;
            Q.push({i, j});
            vis[i][j] = 1;
            int area = 1;
            while(!Q.empty()){
                auto cur = Q.front(); Q.pop();
                for(int k = 0; k < 4; k++){
                    int nx = cur.X + dx[k];
                    int ny = cur.Y + dy[k];
                    if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                    if(vis[nx][ny] || !board[nx][ny]) continue;
                    area++;
                    Q.push({nx, ny});
                    vis[nx][ny] = 1;
                }
            }
            V.push_back(area);
        }
    }
    sort(V.begin(), V.end());
    cout << V.size() << '\n';
    for(int i = 0; i < V.size(); i++){
        cout << V[i] << '\n';
    }
}