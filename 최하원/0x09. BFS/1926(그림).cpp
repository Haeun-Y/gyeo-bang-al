/*

����
� ū ��ȭ���� �׸��� �׷��� ���� ��, �� �׸��� ������, �� �׸� �� ���̰� ���� ���� ���� ���̸� ����Ͽ���. 
��, �׸��̶�� ���� 1�� ����� ���� �� �׸��̶�� ��������. ���γ� ���η� ����� ���� ������ �� ���̰� �밢������ ������ �� ���� ������ �׸��̴�. 
�׸��� ���̶� �׸��� ���Ե� 1�� �����̴�.

�Է�
ù° �ٿ� ��ȭ���� ���� ũ�� n(1 �� n �� 500)�� ���� ũ�� m(1 �� m �� 500)�� ���ʷ� �־�����. �� ��° �ٺ��� n+1 �� ���� �׸��� ������ �־�����. 
(�� �׸��� ������ 0�� 1�� ������ �ΰ� �־�����, 0�� ��ĥ�� �ȵ� �κ�, 1�� ��ĥ�� �� �κ��� �ǹ��Ѵ�)

���
ù° �ٿ��� �׸��� ����, ��° �ٿ��� �� �� ���� ���� �׸��� ���̸� ����Ͽ���. ��, �׸��� �ϳ��� ���� ��쿡�� ���� ���� �׸��� ���̴� 0�̴�.
*/
#include<bits/stdc++.h>
using namespace std;

int n, m, pic = 0, max_area = 0, board[501][501];
bool vis[501][501];
queue < pair < int, int > > Q;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
#define X first
#define Y second

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> board[i][j];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (vis[i][j] || board[i][j] == 0) continue;
			pic++;
			vis[i][j] = 1;
			int area = 0;
			Q.push({ i,j });
			while (!Q.empty()) {
				pair<int, int> cur = Q.front(); Q.pop();
				area++;
				for (int i = 0; i < 4; i++) {
					int nx = cur.X + dx[i];
					int ny = cur.Y + dy[i];
					if (nx < 0 || nx >= 500 || ny < 0 || ny >= 500) continue;
					if (vis[nx][ny] || board[nx][ny] == 0) continue;
					vis[nx][ny] = 1;
					Q.push({ nx, ny });
				}
			}
			if (max_area < area) max_area = area;
		}
	}
	cout << pic << "\n" << max_area;
}

