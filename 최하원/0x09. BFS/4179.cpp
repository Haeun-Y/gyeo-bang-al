// https://www.acmicpc.net/problem/4179
/*
결론적으로 말해 이 문제는 불에 대한 BFS와 지훈이에 대한 BFS를 모두 돌림으로서 해결이 가능합니다.

먼저 지훈이는 신경쓰지 말고 불에 대한 BFS를 돌려서 미리 각 칸에 불이 전파되는 시간을 다 구해둡니다. 두 번째의 맵이  바로 각 칸에 불이 전파시간을 의미합니다.
그 다음에는 지훈이에 대한 BFS를 돌리며 지훈이를 이동시킵니다. 이 때 만약 지훈이가 특정 칸을 x시간에 최초로 방문할 수 있는데 그 칸에는 x시간이나 그 이전에 불이 붙는다면 그 칸을 못가게 됩니다.

예를 들어 **으로 마킹한 칸을 보면 지훈이는 저 칸에 2시간이 될 때 방문하게 됩니다. 
그런데 불은 이미 1시간만에 전파되었기 때문에 지훈이는 저 곳을 갈 수 없습니다. *, ***으로 마킹한 칸도 마찬가지 이유로 지훈이가 갈 수 없는 칸입니다.

원래 BFS의 구현에서는 큐 안에서 (nx, ny)를 살펴볼때 방문했는지 여부를 vis[nx][ny]가 true인지 혹은 dist[nx][ny]가 0 이상인지 확인하고, 이미 방문한 칸이라면 continue를 합니다.
이 문제에서는 추가로 해당 칸에 불이 붙은 시간을 확인해서 필요에 따라 continue를 하면 됩니다. 이렇게 BFS와 지훈이에 대한 BFS를 따로 해서 문제를 그렇게 어렵지는 않게 해결할 수 있습니다.

*/

#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[1003][1003], dx[4] = { 1,0,-1,0 }, dy[4] = { 0, 1, 0, -1 }, dist_fire[1003][1003], dist_jihoon[1003][1003];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int m, n; cin >> m >> n;
	queue <pair<int, int>> fire, jihoon;

	for (int i = 0; i < m; i++) {
		fill(dist_fire[i], dist_fire[i] + n, -1);
		fill(dist_jihoon[i], dist_jihoon[i] + n, -1);
	}

	// 입력
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			char tmp; cin >> tmp;
			if (tmp == '#') board[i][j] = 3; // 벽
			else if (tmp == 'J') { // 지훈
				jihoon.push({ i,j });
				dist_jihoon[i][j] = 0;
			}
			else if (tmp == 'F') { // 불
				fire.push({ i,j });
				dist_fire[i][j] = 0;
			}
			else board[i][j] = 0; // 빈칸 
		}
	}

	// 불 bfs
	while (!fire.empty()) {
		int curX, curY; curX = fire.front().X; curY = fire.front().Y;
		fire.pop();
		for (int i = 0; i < 4; i++) {
			int nx = curX + dx[i]; int ny = curY + dy[i];
			if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
			if (board[nx][ny] == 3 || dist_fire[nx][ny] >= 0) continue;
			fire.push({ nx,ny });
			dist_fire[nx][ny] = dist_fire[curX][curY] + 1;
		}
	}

	// 지훈 bfs
	while (!jihoon.empty()) {
		int curX, curY; curX = jihoon.front().X; curY = jihoon.front().Y;
		jihoon.pop();
		for (int i = 0; i < 4; i++) {
			int nx = curX + dx[i]; int ny = curY + dy[i];
			if (nx < 0 || nx >= m || ny < 0 || ny >= n) { // 탈출 성공
				cout << dist_jihoon[curX][curY] + 1;
				return 0;
			}
			if (board[nx][ny] == 3 || dist_jihoon[nx][ny] >= 0) continue;
			dist_jihoon[nx][ny] = dist_jihoon[curX][curY] + 1;
			if ((dist_jihoon[nx][ny] >= dist_fire[nx][ny]) && dist_fire[nx][ny] != -1) continue;
			jihoon.push({ nx,ny });
		}
	}
	cout << "IMPOSSIBLE";
}