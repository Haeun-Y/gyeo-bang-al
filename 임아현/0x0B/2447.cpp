#include <bits/stdc++.h>

using namespace std;
char arr[6562][6562];
int N;

void print(int x, int y, int N){
    for(int i = x; i < x + N; i++){
        for(int j = y; j < y + N; j++){
            arr[i][j] = ' ';
        }
    }
}

void star(int row, int col, int N, bool blank){
    if(blank){
        print(row, col, N); 
        return;
    }
    if(N == 1){
        arr[row][col] = '*';
        return;
    }
    
    int size = N / 3;
    int count = 0;
    
    for(int i = row; i < row + N; i += size){
        for(int j = col; j < col + N; j += size){
            count++;
            if(count == 5) star(i, j, size, true);
            else star(i, j, size, false);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    
    star(0, 0, N, false);
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << arr[i][j];
        }
        cout << '\n';
    }
};