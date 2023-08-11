// https://www.acmicpc.net/problem/14502
// 브루트포스 + BFS
# include <bits/stdc++.h>
using namespace std;

int N, M, dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, 1, -1 }, board[10][10], ans = 0;
queue<pair<int, int>> virus;

void bfs_cnt() { // 바이러스 퍼뜨리고 빈칸 세는 함수
	int board_copy[10][10];
	queue<pair<int, int>> Q = virus;
	bool vis[10][10] = {};
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			board_copy[i][j] = board[i][j];

	while (!Q.empty()) {
		auto cur = Q.front();
		Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (board_copy[nx][ny] != 0) continue;
			board_copy[nx][ny] = 2;
			vis[nx][ny] = true;
			Q.push({ nx, ny });
		}
	}

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!board_copy[i][j]) cnt++;
		}
	}
	ans = max(ans, cnt);
}

void wall(int n) { // 벽 세우는 함수
	if (n == 3) {
		bfs_cnt();
		return;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!board[i][j]) {
				board[i][j] = 1;
				wall(n + 1);
				board[i][j] = 0;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int tmp;
			cin >> tmp;
			if (tmp == 2) virus.push({ i,j });
			board[i][j] = tmp;
		}
	}
	wall(0);
	cout << ans;

	return 0;
}
