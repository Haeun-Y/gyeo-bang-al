// https://www.acmicpc.net/problem/1012

#include<bits/stdc++.h>
using namespace std;

# define X first
# define Y second
int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T; cin >> T;
	while (T--) {
		int M, N, K, ans = 0; // 가로 세로 배추
		cin >> M >> N >> K;
		bool cabbage[51][51] = { false }, visited[51][51] = { false };
		queue <pair<int, int>> Q;
		for (int i = 0; i < K; i++) {
			int x, y; cin >> x >> y;
			cabbage[x][y] = true;
		}
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (cabbage[i][j] == true && visited[i][j] == false) {
					Q.push({ i,j });
					visited[i][j] = true;
					ans++;

				}
				while (!Q.empty()) {
					auto cur = Q.front(); Q.pop();
					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
						if (cabbage[nx][ny] == false || visited[nx][ny] == true) continue;
						Q.push({ nx,ny });
						visited[nx][ny] = true;
					}
				}
			}
		}
		cout << ans << '\n';
	}
}