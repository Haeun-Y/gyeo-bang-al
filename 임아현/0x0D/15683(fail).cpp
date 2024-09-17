#include <bits/stdc++.h>
/* 반례 (실패한 코드)
4 6 -> 현재 케이스만 고려하니 2를 아래 위로 감시 2랑 1 방향 겹침 고려해야 됨
2 6 0 3 0 2
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 6 1
*/
using namespace std;
#define X first
#define Y second
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int office[70][70]; //배치도
int cover = 0; //현재까지 커버하는 영역...
int answer = 0;
int cnt[4] = {0}; //cnt 배열
queue<int> usedir; //사용 중인 방향... 함수에서 사용
int N, M;

void func(int x, int y){
    while(!usedir.empty()){
      int cur = usedir.front(); usedir.pop();
      int nx = x + dx[cur]; int ny = y + dy[cur];
      while(true){
          if(nx < 0 || nx >= N || ny < 0 || ny >= M) break;
          if(office[nx][ny] == 6) break;
          if(office[nx][ny] == 0){
              office[nx][ny] = -1;
              nx += dx[cur];
              ny += dy[cur];
          }
          else{
              nx += dx[cur];
              ny += dy[cur]; 
          }
      }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    queue<pair<int, int>> Q;
    
    //세로 크기, 가로 크기
    cin >> N >> M;
    
    answer = M * N;
    
    //각 칸의 정보, 큐에 cctv 다 담아 두기
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> office[i][j];
            if(office[i][j] == 6){
                answer--;
                continue;
            }
            if(office[i][j] > 0){
                Q.push({i, j});
                answer--;
            }
        }
    }
    //1. 큐에 들어있는 cctv 좌표 꺼내기 
    //2. cctv 종류에 따라 다른 탐색...
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        fill(cnt, cnt + 4, 0);
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir]; int ny = cur.Y + dy[dir];
            while(1){
                if(nx < 0 || nx >= N || ny < 0 || ny >= M) break;
                if(office[nx][ny] == 6) break;
                if(office[nx][ny] == 0){ //빈공간인 경우
                    //office[nx][ny] = -1;
                    cnt[dir]++;
                    nx += dx[dir]; ny += dy[dir];
                }
                else{ //이미 감시중인 영역 || cctv
                    nx += dx[dir]; ny += dy[dir];
                }
            }
        }
        
        
        int maxA = 0;
        //case1: 0, 1, 2, 3 중 하나
        if(office[cur.X][cur.Y] == 1){
            int idx;
            for(int i = 0; i < 4; i++){
                if(maxA <= cnt[i]){
                    maxA = cnt[i]; 
                    idx = i;
                }
            }
            usedir.push(idx);
        }
        //case2: 0 & 2 또는 1 & 3
        else if(office[cur.X][cur.Y] == 2){
            usedir.push(0); usedir.push(2);
            maxA = cnt[0] + cnt[2];
            if(cnt[0] + cnt[2] < cnt[1] + cnt[3]){
                maxA = cnt[1] + cnt[3];
                usedir.pop(); usedir.pop(); 
                usedir.push(1); usedir.push(3);
            }
        }
        //case3: 0 & 1 or 0 & 3 or 1  & 2 or 2 & 3
         else if(office[cur.X][cur.Y] == 3){
            maxA = max(cnt[0] + cnt[1], maxA);
            usedir.push(0); usedir.push(1);
            if(cnt[0] + cnt[3] > maxA){
                maxA = cnt[0] + cnt[3];
                usedir.pop(); usedir.pop(); 
                usedir.push(0); usedir.push(3);
            }
            if(cnt[1] + cnt[2] > maxA){
                maxA = cnt[1] + cnt[2];
                usedir.pop(); usedir.pop(); 
                usedir.push(1); usedir.push(2);
            }
            if(cnt[2] + cnt[3] > maxA){
                maxA = cnt[2] + cnt[3];
                usedir.pop(); usedir.pop(); 
                usedir.push(2); usedir.push(3);
            }
        }
        //case4: 아무 방향이나 세 개 큰 순서대로
        else if(office[cur.X][cur.Y] == 4){
            int min = 0;
            for(int i = 1; i < 4; i++){
                if(cnt[min] > cnt[i]) min = i;
            }
            for(int i = 0; i < 4; i++){
                if(i != min){
                    usedir.push(i);
                    maxA += cnt[i];
                }
            }
        }
        //case5: 네 방향 모두 
        else{
            usedir.push(0); usedir.push(1); usedir.push(2); usedir.push(3);
            maxA = cnt[0] + cnt[1] + cnt[2] + cnt[3];
        }
        func(cur.X, cur.Y);
        cover += maxA;
    }
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cout << office[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << answer - cover;
}