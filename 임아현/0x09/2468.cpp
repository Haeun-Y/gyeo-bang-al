#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int board[102][102];
vector<int> V; //안전 지대 개수 save

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    
    int temp = 0; //최대 높이 알아내기,
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> board[i][j];
            temp = max(temp, board[i][j]);
        }
    }
    
    while(temp > 0){
        //물에 잠기는 높이를 줄여가며 안전지대 개수 count
        int safe[102][102] = {0};
        bool vis[102][102] = {0};
        //물에 잠기는 지역 safe에 저장장
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(board[i][j] <= temp) safe[i][j] = 0; //잠기는 지역은 0
                else safe[i][j] = 1; //안전한 지역은 1
            }
        }
        //BFS 시작
        int area = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0 ; j < N; j++){
                if(!safe[i][j] || vis[i][j]) continue;
                queue<pair<int, int>> Q;
                Q.push({i, j});
                vis[i][j] = 1;
                area++;
                while(!Q.empty()){
                    auto cur = Q.front(); Q.pop();
                    for(int k = 0; k < 4; k++){
                        int nx = dx[k] + cur.X;
                        int ny = dy[k] + cur.Y;
                        if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                        if(vis[nx][ny] || !safe[nx][ny]) continue;
                        Q.push({nx, ny});
                        vis[nx][ny] = 1;
                    }
                }
            }
        }
        V.push_back(area);
        temp--;
    }
    if(V.empty()) cout << 1;
    else{
      sort(V.begin(), V.end());
      cout << max(1, V[V.size() - 1]); //가장 큰 것것
    }
}