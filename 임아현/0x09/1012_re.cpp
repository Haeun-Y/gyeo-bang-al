#include <bits/stdc++.h>

using namespace std;
#define X first
#define Y second 

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int TC;
    cin >> TC;
    
    while(TC--){
        int board[52][52] = {0};
        bool check[52][52] = {0};
        int M, N, K;
        int W = 0; //배추흰지렁이 수
        cin >> M >> N >> K;
        
        while(K--){
            int row, col;
            cin >> row >> col;
            board[row][col] = 1;
        }
        
        for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                if(board[i][j] == 0 || check[i][j]) continue; //배추가 없거나 이미 방문
                
                queue<pair<int, int>> Q;
                check[i][j] = 1; 
                W++;
                Q.push({i, j});
                while(!Q.empty()){
                    pair<int, int> cur = Q.front(); Q.pop();
                    for(int dir = 0; dir < 4; dir++){
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
                        if(check[nx][ny] || board[nx][ny] == 0) continue;
                        check[nx][ny] = 1;
                        Q.push({nx, ny});
                    }
                }
            }
        }
        cout << W << '\n';
    }
}