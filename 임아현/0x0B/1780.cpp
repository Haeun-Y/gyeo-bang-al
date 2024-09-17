#include <bits/stdc++.h>

using namespace std;
int arr[2188][2188];
int N;
int a, b, c; // -1, 0, 1 count

bool check(int row, int col, int N){
    for(int i = row; i < row + N; i++){
        for(int j = col; j < col + N; j++){
            if(arr[row][col]!=arr[i][j])
               return false;
        }
    }
    return true;
}


void func(int row, int col, int N){
    if(check(row, col, N)){
        if(arr[row][col] == -1) a += 1;
        else if(arr[row][col] == 0) b += 1;
        else c += 1;
        return;
    }
    int n = N / 3; //같은 게 없으면 가로 세로 3으로 쪼갬
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            func(row + i * n, col + j * n, n);
        }
    }
    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> arr[i][j];
        }
    }
    func(0, 0, N);
    cout << a << '\n' << b << '\n' << c;
};