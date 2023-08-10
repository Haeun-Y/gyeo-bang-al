#include <bits/stdc++.h>

#define X first
#define Y second

using namespace std;
int building[32][32][32] = {0}; //-2 입구, 0 통로, -1 벽
int dz[6] = {0, 0, 0, 0,  1, -1};
int dx[6] = {-1, 0, 1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};

int main()
{
    while(true){
        int L, R, C;
        cin >> L >> R >> C;
        if(L == 0) break;
        
        tuple<int, int, int> E, S;
        
        //입력 (char -> int로)
        for(int i = 0; i < L; i++){
            for(int j = 0; j < R; j++){
                string str;
                cin >> str;
                for(int k = 0; k < C; k++){
                    char a = str[k];
                    if(a == 'E'){
                        E = {i, j, k};
                        building[i][j][k] = 0;
                    }
                    else if(a == 'S'){
                         S = {i, j, k};
                         building[i][j][k] = -2;
                    }
                    else if(a == '.') building[i][j][k] = 0;
                    else building[i][j][k] = -1;
                }
            }
        }
        //BFS 진행   
        queue<tuple<int, int, int>> Q;
        Q.push(S);
        
        while(!Q.empty()){
            auto cur = Q.front(); Q.pop();
            for(int i = 0; i < 6; i++){
                    int nz = get<0>(cur) + dz[i];
                    int nx = get<1>(cur) + dx[i];
                    int ny = get<2>(cur) + dy[i];  
                    
                    if(nz < 0 || nz >= L || nx < 0 || nx >= R || ny < 0 || ny >= C ) continue;
                    if(building[nz][nx][ny] < 0) continue;
                    if(building[nz][nx][ny] > 0) continue; 
                    if(building[get<0>(cur)][get<1>(cur)][get<2>(cur)] == -2) building[nz][nx][ny] = 1;
                    else building[nz][nx][ny] = building[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
                    Q.push({nz, nx, ny});
            }
        }
        int t = building[get<0>(E)][get<1>(E)][get<2>(E)];
        if(t <= 0) cout << "Trapped!\n";
        else cout << "Escaped in " << t <<" minute(s).\n";
    }
}