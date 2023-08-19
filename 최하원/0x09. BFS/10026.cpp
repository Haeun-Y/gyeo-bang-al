// https://www.acmicpc.net/problem/10026
#include <bits/stdc++.h>
using namespace std;
int N; char a[100][100];
int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
#define X first
#define Y second
void bfs() {

	queue<pair<int, int>> Q;
	bool vis[100][100]; int area = 0;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			vis[i][j] = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (vis[i][j]) continue;
			Q.push({ i,j });
			vis[i][j] = 1;
			area++;
			while (!Q.empty()) {
				auto cur = Q.front();
				Q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir]; int ny = cur.Y + dy[dir];
					if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
					if (a[cur.X][cur.Y] != a[nx][ny] || vis[nx][ny]) continue;
					Q.push({ nx, ny });
					vis[nx][ny] = 1;
				}
			}
		}
	}
	cout << area << '\n';
}
void bfs_RG() {

	queue<pair<int, int>> Q;
	bool vis[100][100]; int area = 0;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			vis[i][j] = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (vis[i][j]) continue;
			Q.push({ i,j });
			vis[i][j] = 1;
			area++;
			while (!Q.empty()) {
				auto cur = Q.front();
				Q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir]; int ny = cur.Y + dy[dir];
					if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
					if (vis[nx][ny]) continue;
					if (a[cur.X][cur.Y] == 'R' || a[cur.X][cur.Y] == 'G') {
						if (a[nx][ny] == 'B') continue;
					}
					else { // 'B'
						if (a[nx][ny] != 'B') continue;
					}
					Q.push({ nx, ny });
					vis[nx][ny] = 1;
				}
			}
		}
	}
	cout << area << '\n';

}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> a[i][j];

	bfs();
	bfs_RG();

	return 0;
}
// RGB board에서 G를 R로 바꿔주고 bfs() 돌리면 bfs_RG()와 동일한 결과 얻을 수 있다.