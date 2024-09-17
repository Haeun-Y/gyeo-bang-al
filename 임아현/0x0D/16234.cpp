#include <bits/stdc++.h>

#define X first
#define Y second

using namespace std;

int board[102][102];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int main()
{
    int N, L, R;
    cin >>N >> L >> R;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> board[i][j];
        }
    }
    
    int day = 0;
    
    while(true){
        bool vis[102][102] = {0};
        int flag = 0;
        
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(vis[i][j]) continue;
                vis[i][j] = 1;
                queue<pair<int, int>> Q;
                queue<pair<int , int>> W;
                Q.push({i, j});
                
                int sum = 0;
                while(!Q.empty()){
                    auto cur = Q.front(); Q.pop(); //BFS 좌표 
                    sum += board[cur.X][cur.Y];
                    W.push(cur); //국경선 열기 위해 저장 
                    for(int i = 0; i < 4; i++){
                        int nx = dx[i] + cur.X;
                        int ny = dy[i] + cur.Y;
                        if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                        if(vis[nx][ny]) continue;
                        int num = abs(board[nx][ny] - board[cur.X][cur.Y]);
                        if(num < L || num > R) continue;
                        vis[nx][ny] = 1;
                        Q.push({nx, ny});
                    }
                }
                
                if(W.size() > 1){
                    flag = 1;
                    int pe = sum / W.size();
                    while(!W.empty()){
                        auto cur = W.front(); W.pop();
                        board[cur.X][cur.Y] = pe;
                    }
                }
                
            }
        }
        if(flag) day++;
        else break;
    }

    cout << day;
    
}