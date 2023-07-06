#include <bits/stdc++.h>

using namespace std;

char board[1005][1005];
int dp[1005][1005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    
    for(int i = 1; i <= N; i++){
        string str;
        cin >> str;
        //1,1 부터 시작이라 
        for(int j = 1; j <= M; j++){
            board[i][j] = str[j - 1];
        }
    }
    
    int MAX = 0;
    
    //최대값 저장하면서 가기
    //ex 만약 세 방향 모두 2라면 3으로 업데이트!
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            if(board[i][j] == '1'){
                int tmp = min(dp[i - 1][j], dp[i][j -1]);
                tmp = min(dp[i - 1][j - 1], tmp);
                dp[i][j] = tmp + 1;
                MAX = max(MAX, dp[i][j]);
            }
        }
    }
    cout << MAX * MAX;
}