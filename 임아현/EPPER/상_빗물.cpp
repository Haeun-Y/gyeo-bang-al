#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
int board[502][502]; //빈 공간0, 블럭1, 물2
int H, W;

int main()
{
    cin >> H >> W;
    //블록이 있는 부분 1로 표시시
    for(int i = 0; i < W; i++){
        int height;
        cin >> height;
        int j = H - 1;
        while(height--){
            board[j][i] = 1;
            j--;
        }
    }
    //1. 가로 한 줄씩 살펴 보기
    //2. 블록이 있으면 옆으로 이동하며 빈 공간 다 queue에 넣기
    //2-1. 빈 공간 밑이 (1)맨아래인지, (2)블록인지, (3)물이면 넣넣기
    //3. 블록을 만나면 다시 2번 반복... 맨 끝줄에 다다르면 윗줄로 ㄱㄱㄱ
    for(int i = H - 1; i >= 0; i--){
        int j = 0;
        while(j < W){
            //블록을 만날 때까지 이동
            queue<pair<int, int>> Q;
            if(!board[i][j]){
                j++;
                continue;
            }
            //블록을 만나면 다음 블록을 만날 때까지 이동
            while(j < W){
                j++;
                if(j >= W) break;
                //다음 블록을 만나면 큐에 넣어둔 빈 공간 다 꺼내서 2로 표시 (물인 거)
                if(board[i][j]){
                    if(Q.empty()) break; 
                    while(!Q.empty()){
                        auto cur = Q.front(); Q.pop();
                        board[cur.X][cur.Y] = 2;
                    }
                    break;
                }
                //빈 공간 만나면 물이 고일 수 있는지 확인 
                if(!board[i][j]){
                    int dy = i + 1;
                    //맨 밑인 경우, 밑이 물이거나, 벽인 경우에만 큐에 넣기 
                    if(dy >= H|| board[dy][j] == 1 || board[dy][j] == 2){ 
                        Q.push({i, j});
                    }
                }
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(board[i][j] == 2) ans++;
        }
    }
    cout << ans;
}