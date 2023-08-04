// https://www.acmicpc.net/problem/7569

#include<bits/stdc++.h>
using namespace std;

int tomato[103][103][103], days[103][103][103];
int dx[6] = { 1,0,-1,0,0,0 }, dy[6] = { 0,1,0,-1,0,0 }, dz[6] = { 0,0,0,0,1,-1 };
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, h, day = 0;
	queue< tuple <int, int, int> > Q;
	cin >> n >> m >> h; // 열 행 높이
	for (int k = 0; k < h; k++) { // 높이
		for (int i = 0; i < m; i++) { // 행
			for (int j = 0; j < n; j++) { // 열
				int tmp; cin >> tmp;
				tomato[i][j][k] = tmp;
				if (tmp == 1) Q.push({ i,j,k });
				if (tmp == 0) days[i][j][k] = -1;
			}
		}
	}

	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		int curX, curY, curZ;
		tie(curX, curY, curZ) = cur;
		for (int i = 0; i < 6; i++) {
			int nx = curX + dx[i];
			int ny = curY + dy[i];
			int nz = curZ + dz[i];
			if (nx < 0 || nx >= m || ny < 0 || ny >= n || nz < 0 || nz >= h) continue;
			if (days[nx][ny][nz] >= 0) continue;
			Q.push({ nx,ny,nz });
			days[nx][ny][nz] = days[curX][curY][curZ] + 1;
		}
	}

	for (int k = 0; k < h; k++) { // 높이
		for (int i = 0; i < m; i++) { // 행
			for (int j = 0; j < n; j++) { // 열
				if (days[i][j][k] < 0) {
					cout << -1 << '\n';
					return 0;
				}
				day = max(day, days[i][j][k]);
			}
		}
	}
	cout << day << '\n';
	return 0;
}