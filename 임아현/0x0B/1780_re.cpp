#include <bits/stdc++.h>

using namespace std;
int arr[2188][2188]; // 3^7 x 3^7
int N;
int a, b, c; // -1, 0, 1 count

//같은 숫자인지 확인해 주는 함수
bool check(int row, int col, int N){
    int num = arr[row][col];
    for(int i = row; i < row + N; i++){
        for(int j = col; j < col + N; j++){
           if(num != arr[i][j]) return false;
        }
    }
    return true;
}

//재귀 함수
void func(int row, int col, int N){
    //종이가 같은 수로 되어 있는지 확인해야 됨
    if(check(row, col, N)){
        if(arr[row][col] == -1) a++;
        else if(arr[row][col] == 0) b++;
        else c++;
        return;
    }
    
    //같은 수가 아니라면 또 9개로 나누기
    int num = N / 3;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            func(row + i * num, col + j * num, num);
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