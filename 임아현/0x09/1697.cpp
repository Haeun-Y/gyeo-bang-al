#include <bits/stdc++.h>

using namespace std;

int board[200001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int tm = 1;
    int N, K;
    cin >> N >> K; //수빈이이 위치 동생의 위치
    
    queue<int> Q; //위치 담아 둠
    Q.push(N);
    
    int find = 0;
    
    while(!Q.empty()){
        if(N == K) break;
        tm++; //해당 시간에 큐에 들어간 것들이 다 나가면 시간 ++
        int cur = Q.front(); Q.pop(); 
       // cout << "cur : "<< cur << '\n';
       // cout << "tm : "<< tm << '\n';
        
        for(int dir = 0; dir < 3; dir++){
            int x;
            switch(dir){
                case 0:
                     x = cur + 1;
                     break;
                case 1:
                     x = cur - 1;
                     break;
                case 2:
                     x = cur * 2;
                     break;     
            }
            if(x >= 0 && x <= 200000 && x != N && board[x]== 0){
              board[x] = board[cur] + 1;
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