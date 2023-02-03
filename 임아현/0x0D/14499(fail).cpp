//실패 코드 (TC도 틀림)

#include <bits/stdc++.h>

using namespace std;

int N, M, X, Y, K; //가로, 세로, 주사위 위치 (X, Y), 명령 개수
int nx = 0, ny = 0; //주사위의 현재 위치
int dx = 1, dy = 1; //현재 바닥의 위치
int MAP[22][22];
int dice[4][3]; //주사위 전개도 (윗면 아직 1)
int dir[7][4]; //dir 배열

bool checkb(int nx, int ny){
    if(nx < 0 || nx >= N || ny < 0 || ny >= M) return false;
    else return true;
}

void prinT(){
    if(dy == 1) cout << MAP[(dx + 2) % 4][dy] << '\n';
    else cout << MAP[dx][(dy + 2) % 3] << '\n';
}

void roll(){
    if(MAP[nx][ny] == 0){
        MAP[nx][ny] = dice[dx][dy]; //주사위 바닥 칸에 복사
    }
    else{
        dice[dx][dy] = MAP[nx][ny]; //칸에 있는 게 주사위에 복사
    }
}

int main()
{
    //주사위 초기화 (빈칸은 -1임)
    fill(&dice[0][0], &dice[3][3], -1);
    dice[0][1] = 2; 
    dice[1][0] = 4; dice[1][1] = 1; dice[1][2] = 3;
    dice[2][1] = 5; dice[3][1] = 6;
    
    cin >> N >> M >> X >> Y >> K;
    
    nx = X; ny = Y;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> MAP[i][j];
        }
    }
    while(K--){
        int dir;
        cin >> dir; 
        if(dir == 1){
            if(!checkb(nx + 1, ny)) continue;
            nx++; //동쪽으로 
            if(dx == 1 && dy == 2){
                dx = 3; dy = 1;
            }
            else if(dx == 3 && dy == 1){
                dx = 1; dy = 0;
            }
            else dx = (dx + 1) % 3;
            prinT();
        }
        
        else if(dir == 2){
            if(!checkb(nx - 1 , ny)) continue;
            nx--; //서쪽으로
            if(dx == 1 && dy == 0){
                dx = 3; dy = 1;
            }
            else if(dx == 3 && dy == 1){
                dx = 1; dy = 2;
            }
            else dx = (dx + 2) % 3;
            prinT();
        }
        
        else if(dir == 3){
            if(!checkb(nx, ny - 1)) continue;
            ny--; 
            dy = (dy + 3) % 4;
            prinT();
        }
        
        else{
            if(!checkb(nx, ny + 1)) continue;
            ny++;
            dy = (dy + 1) % 4;
            prinT();
        }
        
    }
}