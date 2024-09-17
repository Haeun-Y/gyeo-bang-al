#include <bits/stdc++.h>

using namespace std;

char board[66][66];
int N;

bool check(int r, int c, int n){
    for(int i = r; i < r + n; i++){
        for(int j = c; j < c + n; j++){
            if(board[r][c] != board[i][j]){
                return false;
            }
        }
    }
    
    return true;
}

void func(int r, int c, int n){
    if(check(r, c, n)) {
        cout << board[r][c];
        return;
    }
    
    n = n / 2;
    cout << "(";
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            func(r + i * n , c + j * n, n);
        }
    }
    cout <<")";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for(int i = 0; i < N; i++){
        string str;
        cin >> str;
        for(int j = 0; j < N; j++){
            board[i][j] = str[j];
        }
    }
    func(0, 0, N);
}