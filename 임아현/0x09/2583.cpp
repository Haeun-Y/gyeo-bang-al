#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int board[102][102];
bool vis[102][102];
vector<int> V; //영역 크기 save

int main()
{
    int N, M, K;
    cin >> M >> N >> K;
    
    while(K--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x2--; y2--;
        for(int i = x1; i <= x2; i++){
            for(int j = y1; j <=y2; j++){
                board[i][j] = 1;
            }
        }
    }
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(board[i][j] || vis[i][j]) continue;
            vis[i][j] = 1;
            int size = 1;
            queue<pair<int, int>> Q;
            Q.push({i, j});
            while(!Q.empty()){
                auto cur = Q.front(); Q.pop();
                for(int k = 0; k < 4; k++){
                    int nx = cur.X + dx[k];
                    int ny = cur.Y + dy[k];
                    if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                    if(vis[nx][ny]||board[nx][ny])continue;
                    size++;
                    vis[nx][ny] = 1;
                    Q.push({nx, ny});
                }
                
            }
            V.push_back(size);
        }
    }
    sort(V.begin(), V.end());
    cout << V.size() << "\n";
    for(int i = 0; i < V.size(); i++){
        cout << V[i] << " ";
    }
}