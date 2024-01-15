//잘 모르겠어서 참고

#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int board[302][302] = {0};
int vis[302][302] = {0};
int N, M, year;

int check_stat(){
    int x = -1, y = -1; //빙산 위치 좌표
    int cnt1 = 0; //빙산의 개수
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(board[i][j]){
                x = i;
                y = j;
                cnt1++;
            }
        }
    }
    if(cnt1 == 0) return 0; //다 녹음 남아 있는 빙산 x
    int cnt2 = 0; //붙어있는 빙산의 개수
    
    queue<pair<int, int>> Q;
    vis[x][y] = 1;
    Q.push({x, y});
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        cnt2++;
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if(vis[nx][ny]||board[nx][ny] <= 0) continue;
            vis[nx][ny] = 1;
            Q.push({nx, ny});
        }
    }
    if(cnt1 == cnt2) return 1; //녹아도 개수가 같으므로 return;
    return 2; //분리된 상태
    
}

int main(){
    cin >> N >> M;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> board[i][j];
        }
    }
    
    while(true){
        year++;
        int check[302][302] = {0}; //주변 바닷물 개수
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(board[i][j] == 0) continue;
                for(int dir = 0; dir < 4; dir++){
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];
                    if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                    if(board[nx][ny] > 0) continue;
                    check[i][j]++; //개수 update... 
                    
                }
            }
        }
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                //1년 지났으니까 빼줘야 함, 음수가 될 때 방지
                board[i][j] = max(0, board[i][j] - check[i][j]); 
            }
        }
        
        fill(&vis[0][0], &vis[N-1][M], 0);
        
        int stat = check_stat();
        
        //1.다 녹음
        if(stat == 0){
            cout << 0;
            return 0; 
        }
        //2. 한 덩이임 더 녹이기
        else if(stat == 1) continue; 
        
        //3. 분리된 상태
        else break; 
    }
    cout << year;
    return 0;
}