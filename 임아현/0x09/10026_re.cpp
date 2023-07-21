#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

char board[102][102];
bool check1[102][102];
bool check2[102][102];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int num1, num2; //색맹 X, 색맹O
    int N;
    cin >> N;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> board[i][j];
        }
    }
    
    //색맹이 아닌 경우 
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            char color = board[i][j];
            if(check1[i][j]) continue;
            num1++;
            queue<pair<int, int>> Q;
            Q.push({i, j});
            while(!Q.empty()){
                auto cur = Q.front(); Q.pop();
                for(int i = 0; i < 4; i++){
                    int nx = cur.X + dx[i];
                    int ny = cur.Y + dy[i];
                    if(color != board[nx][ny] || check1[nx][ny]) continue; //different color or visit
                    if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue; //out of bounds
                    Q.push({nx, ny});
                    check1[nx][ny] = 1;
                }
            }
        }
    }
    
    //색맹인 경우
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            char color = board[i][j];
            if(check2[i][j]) continue;
            num2++;
            queue<pair<int, int>> Q;
            Q.push({i, j});
            while(!Q.empty()){
            auto cur = Q.front(); Q.pop();
                for(int i = 0; i < 4; i++){
                    int nx = cur.X + dx[i];
                    int ny = cur.Y + dy[i];
                    if(check2[nx][ny]) continue; //visit
                    if(color == 'R' && board[nx][ny] == 'B' || color == 'G' && board[nx][ny] == 'B') continue;
                    if(color == 'B' && board[nx][ny] == 'R' || color == 'B' && board[nx][ny] == 'G') continue;
                    if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue; //out of bounds
                    Q.push({nx, ny});
                    check2[nx][ny] = 1;
                }
            }
        }
    }
    
    cout << num1 << " " << num2;
    
    
}