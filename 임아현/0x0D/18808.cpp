//잘 모르겠어서 참고...
#include <bits/stdc++.h>

using namespace std;

int N, M, C, R, TC;
int note[42][42]; //노트북
int stk[12][12]; //스티커 

void rot90(){
    int rstk[12][12]; //원본 저장
    
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            rstk[i][j] = stk[i][j];
        }
    }
    
    for(int i = 0; i < C; i++){
        for(int j = 0; j < R; j++){
            stk[i][j] = rstk[R - 1 - j][i];
        }
    }
    
    swap(R, C); // row col 바뀜
}

bool check(int x, int y){
  for(int i = 0; i < R; i++){
    for(int j = 0; j < C; j++){
      if(note[x+i][y+j] == 1 && stk[i][j] == 1)
        return false;
    }
  }
  //return안 됐다면 현재 붙일 수 있는 것이기 때문에 붙이기 시작
  for(int i = 0; i < R; i++){
    for(int j = 0; j < C; j++){
      if(stk[i][j] == 1)
        note[x+i][y+j] = 1;
    }
  }
  return true;
}

int main()
{
     ios::sync_with_stdio(0);
     cin.tie(0);
     cin >> N >> M >> TC;
    
    while(TC--){
        cin >> R >> C;
        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                cin >>stk[i][j];
            }
        }
        
        for(int rot = 0; rot < 4; rot++){//90도씩 회전
            bool paste = false;
            for(int x = 0; x <= N - R; x++){
                if(paste) break;
                for(int y = 0; y <= M - C; y++){
                    if(check(x, y)){
                        paste = true;
                        break;
                    }
                }
            }
            if(paste) break; 
            rot90(); //안 붙었으면 90도 돌리고 같은 과정 반복
        }
    }
    
    
    int cnt = 0; //스티커 붙어 있는 부분 배열 순회하며 찾기
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cnt += note[i][j];
        }
    }
    cout << cnt;
}