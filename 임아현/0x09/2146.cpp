#include <bits/stdc++.h>

using namespace std;
#define X first
#define Y second

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int imap[101][101] = {0};
int vis[101][101] = {0};
int N;

int main()
{
    cin >> N;
    queue<pair<int , int>>Q;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            int temp;
            cin >> temp; 
            if(temp == 1) imap[i][j] = -1;
            else imap[i][j] = 0;
        }
    }
    
    //대륙 분류하기 1, 2, 3... 이런 숫자들로
    int flag = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N ; j++){
            if(imap[i][j] >= 0) continue;
            flag++;
            Q.push({i, j});
            imap[i][j] = flag;
            while(!Q.empty()){
                auto cur = Q.front(); Q.pop();
                for(int dir = 0; dir < 4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx < 0 || nx >= N || ny < 0 || ny >=N) continue;
                    if(imap[nx][ny] >= 0) continue;
                    Q.push({nx, ny});
                    imap[nx][ny] = flag;
                }
            }
        }
    }
    
    int cnt = 0, check = 0;
    int minn = 100000;
    //다리 놓기 시작
    for(int num = 1; num <= flag; num++){
      queue<pair<int , int>> BQ;
      for(int i = 0; i < N; i++){
          for(int j = 0; j < N; j++){
               if(imap[i][j] != num) continue;
               vis[i][j] = 1;
               BQ.push({i, j});
            }
        }
        
        while(!BQ.empty()){
            int S = BQ.size();
            for(int i = 0; i < S; i++){
                auto cur = BQ.front(); BQ.pop(); 
                 //cout << "front " << imap[cur.X][cur.Y] << '\n';
                
                for(int dir = 0; dir < 4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                    if(imap[nx][ny] > 0 && imap[nx][ny] != num){
                        //cout << "nx, ny: " << nx << " " << ny << '\n';
                        check = 1;
                        break;
                    }
                    if(imap[nx][ny] == 0 && !vis[nx][ny]){
                      vis[nx][ny] = 1;
                      BQ.push({nx, ny});
                      //cout << "push nx, ny: " << nx << " " << ny << '\n';
                    }
                }
                if(check) break;
            }
            if(check) break;
            cnt++;
        }
        //cout << "cnt" << cnt << '\n';
        if(cnt != 0) minn = min(minn, cnt);
        cnt = 0; check = 0;
        fill(&vis[0][0], &vis[N-1][N], 0);
    }
    cout << minn;
}