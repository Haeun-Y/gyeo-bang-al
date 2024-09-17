//240330
//softeer 순서대로 방문하기
//Lv.3
#include<bits/stdc++.h>
using namespace std;
vector<vector<bool>> isVisited;
vector<vector<bool>> board;
vector<pair<int, int>> visitBlock;
int n, m;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int result;
//bfs 로 하면 최단거리를 계산하게 돼서 그냥 방식이 계산이 안될듯..
//backtracking을 이용하자 -> 근데 재귀종료조건을 어떻게 해야할지 모르겠음
void findRoute(pair<int, int> pos)
{
    if(pos == visitBlock[m-1]) {
        bool allVisit = true;

        for(int i = 0; i<m-1; i++) {
            if(!isVisited[visitBlock[i].first][visitBlock[i].second])
                allVisit = false;
        }
        if(allVisit) result++;
    }
    else {
        //cout << "visited (" << pos.first << ", " << pos.second << ")\n";
        isVisited[pos.first][pos.second] = true;

        for(int i = 0; i<4; i++) {
            int nx = pos.first + dx[i];
            int ny = pos.second + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(board[nx][ny] || isVisited[nx][ny]) continue;
            //cout << "call (" << nx << ", " << ny << ")\n"; 
            findRoute({nx, ny});
        }
        isVisited[pos.first][pos.second] = false;
    }
    
}
int main(int argc, char** argv)
{
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);

    cin >> n >> m;
    isVisited = board = vector<vector<bool>>(n, vector<bool>(n, false));
    visitBlock = vector<pair<int, int>>(m, {0, 0});

    for(int i = 0; i<n; i++) {
        for(int j = 0; j<n; j++) {
            int tmp;
            cin >> tmp;
            board[i][j] = tmp;
        }
    }
    for(int i = 0; i<m; i++)
    {
        int row, col;
        cin >> row >> col;
        visitBlock[i] = {row-1,col-1};
    }

    
    findRoute({visitBlock[0]});
    cout << result;
    

    

    

   return 0;
}