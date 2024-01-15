#include <bits/stdc++.h>

using namespace std;
int N, L; //세로 선 가로 선
int board[102][102]; //다리 연결 정보 저장
int used[102][102]; //다리 사용 정보
int cnt = 0;

int main()
{
    cin >> N >> L; //첫째 줄
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> board[i][j];
        }
    }
    //경사로 체크 가로 
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N - 1; j++){
            if(board[i][j] != board[i][j + 1]){
                if(abs(board[i][j] - board[i][j + 1]) == 1){
                    //낮아지고 높아지고 생각해야 됨... 한 뱡향이 아님
                    //경사로 놓을 자리 있는지 -> 이미 놓은 자리가 아닌지
                    int flag = 0, tmp = j;
                    while(L--){
                        j++;
                        if(j >= N || used[i][j]){
                            flag = 1;
                            break;
                        }
                    }
                    if(flag) break;
                    else{
                        while(L--){
                            tmp++;
                            used[i][tmp] = 1;
                        }
                        
                    }
                }
                else break;
            }
            if(j == N - 2) { cnt++; cout << "가로 i count : " << i << '\n';}
        }
    }
    
    //경사로 체크 세로
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N - 1; j++){
            if(board[j][i] != board[j + 1][i]){
                if(abs(board[j][i] - board[j + 1][i]) == 1){
                    //경사로 놓을 자리 있는지 -> 이미 놓은 자리가 아닌지
                    int flag = 0, tmp = j;
                    while(L--){
                        j++;
                        if(j >= N || used[j][i]){
                            flag = 1;
                            break;
                        }
                    }
                    if(flag) break;
                    else{
                        while(L--){
                            tmp++;
                            used[tmp][i] = 1;
                        }
                        
                    }
                }
                else break;
            }
            if(j == N - 2) { cnt++; cout << "세로 i count : " << i << '\n';}
        }
    }
    
    cout << cnt;
    
}