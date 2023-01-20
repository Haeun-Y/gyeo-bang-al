//나중에 다시 풀어보고 싶음 (반례)

#include <bits/stdc++.h>

using namespace std;

int board[200001];
int vis[200001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, K;
    cin >> N >> K; //수빈이이 위치 동생의 위치
    int range = max(N, K);
    
    queue<int> Q; //위치 담아 둠
    Q.push(N);
    vis[N] = 1;
    board[N] = 0;
    int find = 0;
    
    while(!Q.empty()){
        if(N == K) break;
        int cur = Q.front(); Q.pop(); 
       // cout << "cur : "<< cur << '\n';
        
        for(int dir = 0; dir < 3; dir++){
            int x = 0, chk = 0;
            if(N <= K && cur + 1 == cur * 2 || cur -1 == cur * 2) chk = 1;
            switch(dir){
                case 0:
                     x = cur * 2;
                     chk = 1;
                     break;
                case 1:
                     x = cur + 1;
                     break;
                case 2:
                     x = cur - 1;
                     break;     
            }
            if(x >= 0 && x <= range && !vis[x]){
                cout << "x " << x<< "cur" << cur << '\n';
              if(chk){
                  //cout << "0초 board[" << x <<"] " << cur << "\n";
                  board[x] = board[cur];
                  vis[x] = 1;
                 // cout << "0초 board[" << x <<"] " << board[x]<< "\n";
              }
              else{
                  board[x] = board[cur] + 1;
                  vis[x] = 1;
                  //cout << "1초 board[" << x <<"] " << board[x]<< "\n";
              }
              Q.push(x);
            }
            if(x == K) {
                find = 1;
                break;
            }
        }
        if(find) break;
    }
    cout << board[K];
}