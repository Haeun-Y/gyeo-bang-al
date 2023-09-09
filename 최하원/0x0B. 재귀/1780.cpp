// https://www.acmicpc.net/problem/1780
// 분할 정복
// 영역 내 숫자가 같아질 때 까지 삼등분 쪼개면서 확인

#include <bits/stdc++.h>
using namespace std;
int N, cnt0, cnt1, cnt2, board[2200][2200];

bool check(int n, int m, int k) {
    int start = board[n][m];
    for (int i = n; i < n + k; i++)
        for (int j = m; j < m + k; j++)
            if (start != board[i][j]) return false;
    return true;
}

void func(int n, int m, int k) {
    if (check(n, m, k)) {
        switch (board[n][m]) {
        case -1: cnt0++; break;
        case 0: cnt1++; break;
        case 1: cnt2++; break;
        }
    }

    else {
        int size = k / 3;
        for (int i = n; i < n + k; i += size) {
            for (int j = m; j < m + k; j += size) {
                func(i, j, size);
            }
        }
    }
}
int main() {

    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];

    func(0, 0, N);
    cout << cnt0 << '\n' << cnt1 << '\n' << cnt2 << '\n';

    return 0;
}

