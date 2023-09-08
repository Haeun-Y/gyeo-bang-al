#include <bits/stdc++.h>

#define X first
#define Y second

using namespace std;

bool vis[52][52];
char board[52][52];

int main()
{
    int N, M;
    cin >> N >> M;
    
    for(int i = 0; i < N; i++){
        string str;
        cin >> str;
        for(int j = 0; j < M; j++){
            board[i][j] = str[j];
        }
    }
    
    int cnt = 0;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(vis[i][j]) continue;
            cnt++;
            queue<pair<int, int>> Q;
            Q.push({i, j});
            while(!Q.empty()){
                auto cur = Q.front(); Q.pop();
                int dx = cur.X; int dy = cur.Y;
                if(board[cur.X][cur.Y] == '|') dx++;
                else dy++;
                if(dx < 0 || dx >= N || dy < 0 || dy >= M) continue;
                if(vis[dx][dy]) continue;
                if(board[cur.X][cur.Y] != board[dx][dy]) continue;
                vis[dx][dy] = 1;
                //cout << "dx: " << dx << " dy: " << dy << '\n';
                Q.push({dx, dy});
            }
        }
    }
    cout << cnt;
}