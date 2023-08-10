#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int arr[52][52];
int choose[10];
vector<pair<int, int>> V; //virus location
vector<int> MIN; //save min time
int N, M; //array N X N, virus num 

void virus(){
    int board[52][52] = {0};
    memcpy(board, arr, sizeof(arr));
    //copy check
    
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(board[i][j] == 2) board[i][j] = 0; //virus
            else if(board[i][j] == 1) board[i][j] = -1; //wall
        }
    }
    
    for(int i = 0; i < M; i++){
        int x = V[choose[i] - 1].first;
        int y = V[choose[i] - 1].second;
        board[x][y] = -2; //check virus location
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            bool vis[52][52] = {0};
            if(board[i][j] >= 0 || board[i][j] == -1) continue;
            if(vis[i][j]) continue;
            queue<pair<int, int>> Q;
            Q.push({i, j});
            while(!Q.empty()){
                auto cur = Q.front(); Q.pop();
                for(int i = 0; i < 4; i++){
                    int nx = dx[i] + cur.X;
                    int ny = dy[i] + cur.Y;
                    if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                    if(vis[nx][ny]) continue;
                    if(board[nx][ny] == -2 || board[nx][ny] == -1) continue;
                    if(board[cur.X][cur.Y] == -2) board[nx][ny] = 1;
                    else {
                        if(board[nx][ny] > 0) board[nx][ny] = min(board[nx][ny], board[cur.first][cur.second] + 1);
                        else board[nx][ny] = board[cur.first][cur.second] + 1;
                    }
                    vis[nx][ny] = 1;
                    Q.push({nx, ny});
                }
            
            }
        }
    }
    
    int num = 0;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(board[i][j] == 0){
                MIN.push_back(-1); 
                return;
            }
            num = max(num, board[i][j]);
        }
    }
    
    MIN.push_back(num);
}

//choose M, virus location 
void choose_location(int k, int depth){
    if(depth == M){
        virus();
        return;
    }
    
    for(int i = k; i <= V.size(); i++){
        choose[depth] = i;
        choose_location(i + 1, depth + 1);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 2) V.push_back({i, j});
        }
    }
    choose_location(1, 0);
    sort(MIN.begin(), MIN.end());
    int flag = -1;
    for(int i = 0; i < MIN.size(); i++){
        if(MIN[i] != -1){
            flag = MIN[i];
            break;
        }
    }
    if(flag >= 0) cout << flag;
    else cout << -1;
}