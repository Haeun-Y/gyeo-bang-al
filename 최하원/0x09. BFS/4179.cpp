// https://www.acmicpc.net/problem/4179
/*
��������� ���� �� ������ �ҿ� ���� BFS�� �����̿� ���� BFS�� ��� �������μ� �ذ��� �����մϴ�.

���� �����̴� �Ű澲�� ���� �ҿ� ���� BFS�� ������ �̸� �� ĭ�� ���� ���ĵǴ� �ð��� �� ���صӴϴ�. �� ��°�� ����  �ٷ� �� ĭ�� ���� ���Ľð��� �ǹ��մϴ�.
�� �������� �����̿� ���� BFS�� ������ �����̸� �̵���ŵ�ϴ�. �� �� ���� �����̰� Ư�� ĭ�� x�ð��� ���ʷ� �湮�� �� �ִµ� �� ĭ���� x�ð��̳� �� ������ ���� �ٴ´ٸ� �� ĭ�� ������ �˴ϴ�.

���� ��� **���� ��ŷ�� ĭ�� ���� �����̴� �� ĭ�� 2�ð��� �� �� �湮�ϰ� �˴ϴ�. 
�׷��� ���� �̹� 1�ð����� ���ĵǾ��� ������ �����̴� �� ���� �� �� �����ϴ�. *, ***���� ��ŷ�� ĭ�� �������� ������ �����̰� �� �� ���� ĭ�Դϴ�.

���� BFS�� ���������� ť �ȿ��� (nx, ny)�� ���캼�� �湮�ߴ��� ���θ� vis[nx][ny]�� true���� Ȥ�� dist[nx][ny]�� 0 �̻����� Ȯ���ϰ�, �̹� �湮�� ĭ�̶�� continue�� �մϴ�.
�� ���������� �߰��� �ش� ĭ�� ���� ���� �ð��� Ȯ���ؼ� �ʿ信 ���� continue�� �ϸ� �˴ϴ�. �̷��� BFS�� �����̿� ���� BFS�� ���� �ؼ� ������ �׷��� ������� �ʰ� �ذ��� �� �ֽ��ϴ�.

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

	// �Է�
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			char tmp; cin >> tmp;
			if (tmp == '#') board[i][j] = 3; // ��
			else if (tmp == 'J') { // ����
				jihoon.push({ i,j });
				dist_jihoon[i][j] = 0;
			}
			else if (tmp == 'F') { // ��
				fire.push({ i,j });
				dist_fire[i][j] = 0;
			}
			else board[i][j] = 0; // ��ĭ 
		}
	}

	// �� bfs
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

	// ���� bfs
	while (!jihoon.empty()) {
		int curX, curY; curX = jihoon.front().X; curY = jihoon.front().Y;
		jihoon.pop();
		for (int i = 0; i < 4; i++) {
			int nx = curX + dx[i]; int ny = curY + dy[i];
			if (nx < 0 || nx >= m || ny < 0 || ny >= n) { // Ż�� ����
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