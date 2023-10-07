//https://www.acmicpc.net/problem/11559
/*
�ѿ�ѿ��� ���� ������ ����.

�ʵ忡 ���� ���� ������ �ѿ並 ���´�. �ѿ�� �߷��� ������ �޾� �Ʒ��� �ٴ��̳� �ٸ� �ѿ䰡 ���� ������ �Ʒ��� ��������.

�ѿ並 ���� �� ��, ���� �� �ѿ䰡 4�� �̻� �����¿�� ����Ǿ� ������ ����� ���� �� �ѿ���� �Ѳ����� ��������. �̶� 1���Ⱑ ���۵ȴ�.

�ѿ���� �������� ���� ���� �ٸ� �ѿ���� �ִٸ�, ���� �߷��� ������ �޾� ���ʴ�� �Ʒ��� �������� �ȴ�.

�Ʒ��� �������� ���� �ٽ� ���� ���� �ѿ���� 4�� �̻� ���̰� �Ǹ� �� ������ �Ǵµ�, ���� �� �ѿ���� �������� �ٽ� ������ �ݺ��� ������ 1���⾿ �þ��.

���� �� �ִ� �ѿ䰡 ���� �׷��� �ִٸ� ���ÿ� ������ �ϰ� ���� �׷��� �������� �ѹ��� ���Ⱑ �߰��ȴ�.

���Դ� �ֱ� �ѿ�ѿ� ���ӿ� ǫ ������. �� ������ 1:1�� �ٴ� ���������̶� �� �״� �͵� �߿�������, ������ �Ͷ߸��ٸ� ���Ⱑ �� ���� ���� �ٷ� �ľ��� �� �ִ� �ɷµ� �ʿ��ϴ�. ������ ���� �Ƿ��� �����Ͽ� ���Դ� �ڱ� �ʵ忡�� �Ű� ���� �ٻڴ�. ������ �ʵ尡 �־����� ��, ���Ⱑ �� �� �������� �Ͼ�� ����Ͽ� ���Ը� ��������!

�Է�
�� 12���� �ٿ� �ʵ��� ������ �־�����, �� �ٿ��� 6���� ���ڰ� �ִ�.

�̶� .�� ������̰� .�� �ƴѰ��� ������ ������ �ѿ並 ��Ÿ����.

R�� ����, G�� �ʷ�, B�� �Ķ�, P�� ����, Y�� ����̴�.

�Է����� �־����� �ʵ�� �ѿ���� ���� �Ʒ��� ������ ���� �����̴�. ��, �ѿ� �Ʒ��� �� ĭ�� �ִ� ���� ����.

���
���� �־��� ��Ȳ���� ��Ⱑ �Ǵ��� ����Ѵ�. �ϳ��� ������ �ʴ´ٸ� 0�� ����Ѵ�

*/

#include<bits/stdc++.h>
using namespace std;

#define X first 
#define Y second

int ans = 0, dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
char board[13][7];
bool vis[13][7];

const int ROW = 12;
const int COLUMN = 6;

void bfs() {

	for (int i = 0; i < ROW; i++)
		for (int j = 0; j < COLUMN; j++)
			vis[i][j] = 0;

	queue<pair<int, int>> Q;
	vector<pair<int, int>> v;
	for (int i = ROW - 1; i >= 0; i--) {
		for (int j = COLUMN - 1; j >= 0; j--) {
			int cnt = 0;
			if (vis[i][j] || board[i][j] == '.') continue;
			char color = board[i][j];
			vis[i][j] = 1;
			Q.push({ i,j });
			v.push_back({ i,j });
			while (!Q.empty()) {
				auto cur = Q.front(); Q.pop();
				for (int i = 0; i < 4; i++) {
					int nx = cur.X + dx[i]; int ny = cur.Y + dy[i];
					if (nx < 0 || nx > COLUMN || ny < 0 || ny > ROW) continue;
					if (board[nx][ny] != color || vis[nx][ny]) continue;
					Q.push({ nx, ny });
					v.push_back({ nx, ny });
					vis[nx][ny] = 1;
				}
			}

			if (cnt >= 4) {
				ans++;
				while (!v.empty()) {
					auto cur = v.front();
					board[cur.X][cur.Y] = '.';
					v.pop_back();
				}
			}

			while (!v.empty())
				v.pop_back();

		}
	}
}
void gravity() {
	for (int i = 0; i < COLUMN; i++) {
		int cnt = 0;
		for (int j = ROW - 1; j >= 0; j--) {
			if (board[j][i] == '.') {
				cnt++;
				continue;
			}
			else if (board[j][i] == 'R' || board[j][i] == 'G' || board[j][i] == 'B' || board[j][i] == 'P' || board[j][i] == 'Y') {
				board[j + cnt][i] = board[j][i];
				board[j][i] = '.';
			}
			else board[j][i] = '.';
		}
	}
}

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < ROW; i++)
		for (int j = 0; j < COLUMN; j++)
			cin >> board[i][j];
	cout << '\n';

	bfs();
	gravity();


	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COLUMN; j++)
			cout << board[i][j];
		cout << '\n';
	}

	cout << ans;
	return 0;
}