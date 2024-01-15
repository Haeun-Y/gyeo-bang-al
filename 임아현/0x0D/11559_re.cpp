#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

char board[14][8]; //12 X 6
bool vis[14][8];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int cnt = 0; //몇 번의 연쇄
    
    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 6; j++){
            cin >> board[i][j];
        }
    }
    
    while(true){
        fill(vis[0], vis[14], 0);
        bool check = false; //터졌는지
        //pop 터뜨리기 (터뜨린 것은 .으로)
        for(int i = 0; i < 12; i++){
            for(int j = 0; j < 6; j++){
                if(board[i][j] == '.') continue;
                
                queue<pair<int, int>> Q;
                queue<pair<int, int>> P; //pop을 위해 좌표 저장
                vis[i][j] = 1;
                Q.push({i, j});
                
                int area = 0;
                while(!Q.empty()){
                    area++;
                    pair<int, int> cur = Q.front(); Q.pop();
                    P.push(cur); //pop을 위해 저장
                    for(int dir = 0; dir < 4; dir++){
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(nx < 0 || ny < 0 || nx >= 12 || ny >= 6) continue;
                        if(vis[nx][ny] || board[nx][ny] != board[cur.X][cur.Y]) continue;
                        vis[nx][ny] = 1;
                        Q.push({nx, ny});
                    }
                }
                
                if(area >= 4){
                    check = true;
                    while(!P.empty()){
                         pair<int, int> PQ = P.front(); P.pop();
                         board[PQ.X][PQ.Y] = '.';
                    }
                }
                
            }
        }
        if(!check) break; //연쇄 없었다면 중단
        else cnt++; //연쇄 있었다면 +1
        
        //drop (떨어뜨리기)
        for(int i = 0; i < 6; i++){
            int gap = 0;
            for(int j = 11; j >= 0; j--){
                if(board[j][i] == '.') gap++;
                else{
                    if(gap != 0){
                      board[j + gap][i] = board[j][i];
                      board[j][i] = '.';
                    }
                }
            }
        }
    }
    cout << cnt;
}