#include <bits/stdc++.h>

using namespace std;
#define X first
#define Y second

string board[101];
bool nvis[101][101];
bool cvis[101][101];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    for(int i = 0; i < N; i++){
        cin >> board[i];
    }
    queue<pair<int, int>> NQ; //색맹 x
    queue<pair<int, int>> BQ; // 색맹 o
    int num = 0;
    int cnum = 0; //적록색 아닌 경우 적록색인 경우
    
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(nvis[i][j]) continue;
            char color = board[i][j]; //현재 색깔
            nvis[i][j] = 1;
            NQ.push({i, j});
            num++;
            while(!NQ.empty()){
                auto cur = NQ.front(); NQ.pop();
                for(int dir = 0; dir < 4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                    if(color != board[nx][ny] || nvis[nx][ny]) continue;
                    nvis[nx][ny] = 1;
                    NQ.push({nx, ny});
                }
            }
        }
    }
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(cvis[i][j]) continue;
            char color = board[i][j]; //현재 색깔
            cvis[i][j] = 1;
            BQ.push({i, j});
            cnum++;
            while(!BQ.empty()){
                auto cur = BQ.front(); BQ.pop();
                for(int dir = 0; dir < 4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                    if(cvis[nx][ny]) continue;
                    if(color == 'R' && board[nx][ny] == 'G'||color == 'G' && board[nx][ny] == 'R'||color == board[nx][ny]){
                      cvis[nx][ny] = 1;
                      BQ.push({nx, ny});
                    }
                }
            }
        }
    }
    
    cout << num << ' ' <<cnum;
    
}