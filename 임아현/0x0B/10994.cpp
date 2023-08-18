#include <bits/stdc++.h>

using namespace std;

char board[402][402];

void func(int num, int x, int y){
    if(num == 1){
        board[x][y] = '*';
        return;
    }
    
    int dx = x + 4 * (num - 1);
    int dy = y + 4 * (num - 1);
    
    for(int i = x; i <= dx; i++){
        board[i][y] = '*';
        board[i][dy] = '*';
    }
    
    for(int i = y; i <= dy; i++){
        board[x][i] = '*';
        board[dx][i] = '*';
    }
    
    func(num - 1, x + 2, y + 2);
}

int main()
{
    int N;
    cin >> N;
    func(N, 0, 0);
    
    N = 4 * (N - 1);
    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= N; j++){
            if(board[i][j] == '*') cout << board[i][j];
            else cout << ' ';
        }
        cout << '\n';
    }
    
}