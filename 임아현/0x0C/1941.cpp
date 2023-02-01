//잘 모르겠어서 답안지 참고 나중에 다시 풀어보기...

#include <bits/stdc++.h>

using namespace std;

string board[5];
bool isused[25]; 


int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

#define NUM 7 
#define RC 5
#define X first
#define Y second

int cnt;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 0; i < RC; i++) cin >> board[i];
    
    fill(isused + 7, isused + 25, true);
    do{
        queue<pair<int , int>> Q;
        int spower = 0, adj = 0; //임도연파의 숫자(3넘으면 안 됨), 가로세로 인접
        bool member[5][5] = {}, visited[5][5] ={};
        
        for(int i = 0; i < 25; i++){
            if(!isused[i]){
                int x = i / 5, y = i % 5;
                member[x][y] = 1;
                if(Q.empty()){
                    Q.push({x, y});
                    visited[x][y] = 1;
                }
            }
        }
        
        while(!Q.empty()){
            int x, y;
            tie(x, y) = Q.front();
            Q.pop();
            adj++;
            if(board[x][y] == 'S') spower++;
            for(int dir = 0; dir < 4; dir++){
                int nx = x + dx[dir], ny = y + dy[dir];
                if(nx < 0 || nx >= 5 || ny < 0 || ny >= 5 || visited[nx][ny] ||!member[nx][ny])
                   continue;
                 Q.push({nx, ny});
                 visited[nx][ny] = 1;
            }
        }
        if(adj >= 7 && spower >= 4) cnt++;
    }while(next_permutation(isused, isused + 25));
    
    //조합으로 모든 경우의 수 생각해 보고, 인접했는지 확인, 이다솜파 4명 이상인지 확인 
    cout << cnt;
    
}