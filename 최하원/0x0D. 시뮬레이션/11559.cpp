//https://www.acmicpc.net/problem/11559
/*
뿌요뿌요의 룰은 다음과 같다.

필드에 여러 가지 색깔의 뿌요를 놓는다. 뿌요는 중력의 영향을 받아 아래에 바닥이나 다른 뿌요가 나올 때까지 아래로 떨어진다.

뿌요를 놓고 난 후, 같은 색 뿌요가 4개 이상 상하좌우로 연결되어 있으면 연결된 같은 색 뿌요들이 한꺼번에 없어진다. 이때 1연쇄가 시작된다.

뿌요들이 없어지고 나서 위에 다른 뿌요들이 있다면, 역시 중력의 영향을 받아 차례대로 아래로 떨어지게 된다.

아래로 떨어지고 나서 다시 같은 색의 뿌요들이 4개 이상 모이게 되면 또 터지게 되는데, 터진 후 뿌요들이 내려오고 다시 터짐을 반복할 때마다 1연쇄씩 늘어난다.

터질 수 있는 뿌요가 여러 그룹이 있다면 동시에 터져야 하고 여러 그룹이 터지더라도 한번의 연쇄가 추가된다.

남규는 최근 뿌요뿌요 게임에 푹 빠졌다. 이 게임은 1:1로 붙는 대전게임이라 잘 쌓는 것도 중요하지만, 상대방이 터뜨린다면 연쇄가 몇 번이 될지 바로 파악할 수 있는 능력도 필요하다. 하지만 아직 실력이 부족하여 남규는 자기 필드에만 신경 쓰기 바쁘다. 상대방의 필드가 주어졌을 때, 연쇄가 몇 번 연속으로 일어날지 계산하여 남규를 도와주자!

입력
총 12개의 줄에 필드의 정보가 주어지며, 각 줄에는 6개의 문자가 있다.

이때 .은 빈공간이고 .이 아닌것은 각각의 색깔의 뿌요를 나타낸다.

R은 빨강, G는 초록, B는 파랑, P는 보라, Y는 노랑이다.

입력으로 주어지는 필드는 뿌요들이 전부 아래로 떨어진 뒤의 상태이다. 즉, 뿌요 아래에 빈 칸이 있는 경우는 없다.

출력
현재 주어진 상황에서 몇연쇄가 되는지 출력한다. 하나도 터지지 않는다면 0을 출력한다

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