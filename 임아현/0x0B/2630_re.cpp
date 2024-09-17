#include <bits/stdc++.h>

using namespace std;

int board[130][130];
int num;
int white, blue;

// 다 0인지 1인지 check
bool check(int N, int col, int row){
    for(int i = col; i < col + N; i++){
        for(int j = row; j < row + N; j++){
            if(board[col][row] != board[i][j]) return false;
        }
    }
    if(board[col][row]) blue++; //1이면 blue
    else white++; //0이면 white
    return true;
}

//재귀함수 
void func(int N, int col, int row){
    if(check(N, col, row)) return;
    int n = N / 2;
    
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            func(n, col + i * n , row + j * n);
        }
    }

}

int main()
{
    cin >> num;
    
    for(int i = 0; i < num; i++){
        for(int j = 0; j < num; j++){
            cin >> board[i][j];
        }
    }
    
    func(num, 0, 0);
    cout << white << '\n' << blue;
}