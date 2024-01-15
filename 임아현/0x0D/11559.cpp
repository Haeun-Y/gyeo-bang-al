#include <bits/stdc++.h>

using namespace std;
#define X first
#define Y second 
#define MAX 12
#define MAY 6
//네 방향 확인...
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1}; 

string field[14];
int answer = 0;

//떨어지는 함수 (정답 코드 참고함)
void drop(){
    for(int i = 0; i < MAY; i++){
        for(int j = 10; j >= 0; --j){
            int tmp = j;
            while(tmp < 11 && field[tmp + 1][i] == '.'){
                swap(field[tmp][i], field[tmp + 1][i]);
                ++tmp;
            }
        }
    }
}

int main()
{
    for(int i = 0; i < MAX; i++){
        cin >> field[i];
    }
    
    bool nochain = true;
    int chain = 0;

    while(true){
        for(int i = 0; i < 12; i++){
            for(int j = 0; j < 6; j++){
                queue<pair<int, int>> Q;
                queue<pair<int, int>> PQ; //터질 뿌요들...
                bool isused[14][14] = {0};
                if(field[i][j] != '.'){
                    Q.push({i, j});
                }
                int cnt = 0;
                while(!Q.empty()){
                    auto cur = Q.front(); Q.pop();
                    char color = field[cur.X][cur.Y]; 
                    for(int i = 0; i < 4; i++){
                        int nx = cur.X + dx[i];
                        int ny = cur.Y + dy[i];
                        if(nx < 0 || nx >= MAX || ny < 0 || ny >= MAY) continue;
                        if(isused[nx][ny]) continue;
                        if(color != field[nx][ny] || field[nx][ny] == '.') continue;
                        PQ.push({nx, ny}); Q.push({nx, ny}); isused[nx][ny] = 1;
                    }
                    
                }
                if(PQ.size() >= 4){ 
                    while(!PQ.empty()){
                        auto cur = PQ.front(); PQ.pop();
                        field[cur.X][cur.Y] = '.'; //터뜨려야 하는 것
                    }
                    nochain = false;
                }
            }
        }
        if(nochain) break;
        else{
            drop();
            answer++;
            nochain = true;
        }
    }
    cout << answer;
}