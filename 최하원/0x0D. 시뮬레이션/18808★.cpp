/*
입력
첫째 줄에 노트북의 세로와 가로 길이를 나타내는 N(1 ≤ N ≤ 40)과 M(1 ≤ M ≤ 40), 그리고 스티커의 개수 K(1 ≤ K ≤ 100)이 한 칸의 빈칸을 사이에 두고 주어진다.
그 다음 줄부터는 K개의 스티커들에 대한 정보가 주어진다. 각 스티커는 아래와 같은 형식으로 주어진다.
먼저 i번째 스티커가 인쇄된 모눈종이의 행의 개수와 열의 개수를 나타내는 Ri(1 ≤ Ri ≤ 10)와 Ci(1 ≤ Ci ≤ 10)가 한 칸의 빈칸을 사이에 두고 주어진다.
다음 Ri개의 줄에는 각 줄마다 모눈종이의 각 행을 나타내는 Ci개의 정수가 한 개의 빈칸을 사이에 두고 주어진다. 각 칸에 들어가는 값은 0, 1이다. 0은 스티커가 붙지 않은 칸을, 1은 스티커가 붙은 칸을 의미한다.
문제에서 설명한 것과 같이 스티커는 모두 올바른 모눈종이에 인쇄되어 있다. 구체적으로 스티커의 각 칸은 상하좌우로 모두 연결되어 있고, 모눈종이의 크기는 스티커의 크기에 꼭 맞아서 상하좌우에 스티커에 전혀 포함되지 않는 불필요한 행이나 열이 존재하지 않는다.

출력
첫째 줄에 주어진 스티커들을 차례대로 붙였을 때 노트북에서 스티커가 붙은 칸의 수를 출력한다.
*/
#include <bits/stdc++.h>
using namespace std;

int sticker[12][12], board[42][42], N, M, r, c;

void rotate() { // 시계 90도 회전
	int tmp[12][12];
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)
			tmp[i][j] = sticker[i][j];
	}
	for (int i = 0; i < c; i++) {
		for (int j = 0; j < r; j++)
			sticker[i][j] = tmp[r - 1 - j][i];
	}
	swap(r, c);
}
bool attach(int x, int y) { // 붙일 수 있는지 여부 확인 후 가능하면 부착
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (sticker[i][j] && board[x + i][y + j]) return false;
		}
	}
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (sticker[i][j]) board[x + i][y + j] = 1;
	return true;
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// 입력 
	int K, ans = 0;
	cin >> N >> M >> K;

	while (K--) {
		cin >> r >> c;
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				cin >> sticker[i][j];

		for (int n = 0; n < 4; n++) {
			bool isPaste = false;
			for (int i = 0; i <= N - r; i++) {
				if (isPaste) break;
				for (int j = 0; j <= M - c; j++) {
					if (attach(i, j)) {
						isPaste = true;
						break;
					}
				}
			}
			if (isPaste) break;
			rotate();
		}
	}

	// 출력
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			ans += board[i][j];

	cout << ans;
}