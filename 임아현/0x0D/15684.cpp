#include <bits/stdc++.h>

using namespace std;
int N, M, H; //세로 선 가로 선
int check = 0, num = 0;
int board[32][32]; //다리 연결 정보 저장

void find(int r, int c, int k){
    if(check) return;
    
    if(num == k){
        int flag = 0;
        
        for(int i = 1; i <= N; i++){
            int start = i;
            for(int j = 1; j <= H; j++){
                if(board[j][start] < 0) start++;
                else if(board[j][start]) start--;
            }
            
            if(start != i){
                flag = 1;
                break;
            }
        }
        
        if(flag == 0){
            check = 1;
        }
        
        return; //더이상 탐색 X 
    }
    
    for(int i = r; i <= H; i++){
        for(int j = c; j < N; j++){
            if(!board[i][j]&& !board[i][j + 1]){
                //더이상 다리 X 다리 추가
                board[i][j] = -1;
                board[i][j + 1] = 1;
                
                if(j + 2 < N) find(i, j + 1, k + 1);
                else find(i + 1, 1, k + 1);
                board[i][j] = 0;
                board[i][j + 1] = 0; //재귀 끝나면 원상 복귀
            }
        }
    }
    
}

int main()
{
    cin >> N >> M >> H; //첫째 줄
    
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        //왼쪽 연결 -1, 오른쪽 연결 1, 연결 X 0
        board[a][b] = -1; 
        board[a][b + 1] = 1;
    }
    
    //다리 최대 3개 놓음 -> 탐색 세 번
    for(int i = 0; i < 4; i++){
        num = i;
        find(1, 1, 0);
        
        if(check){
            cout << num;
            return 0;
        }
    }
    cout << -1;
}