/*
�Է�
ù° �ٿ� �繫���� ���� ũ�� N�� ���� ũ�� M�� �־�����. (1 �� N, M �� 8)
��° �ٺ��� N���� �ٿ��� �繫�� �� ĭ�� ������ �־�����. 0�� �� ĭ, 6�� ��, 1~5�� CCTV�� ��Ÿ����, �������� ������ CCTV�� �����̴�. 
CCTV�� �ִ� ������ 8���� ���� �ʴ´�.

���
ù° �ٿ� �簢 ������ �ּ� ũ�⸦ ����Ѵ�.
*/

//CCTV�� ��ġ�� ���� �����մϴ�.
//CCTV�� �ϳ��� �߰��մϴ�.�̶� ������ CCTV�� ȸ���� �����ϹǷ� �� ȸ���� ��� ���� ��� Ȯ���ؾ� �մϴ�.
//CCTV�� ��� �߰��� �Ŀ��� �簢������ ���� ����ϰ� �ּڰ��� ������Ʈ �մϴ�.
//CCTV�� �ƿ� ���� ��찡 ���� �� �ִµ� �̶��� ��ĭ���� ���� ������ �մϴ�.

# define X first
# define Y second

int N, M, board[10][10], checkboard[10][10], ans = 0;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
vector<pair<int, int>> cctv;

void check(int x, int y, int dir) { // ���� üũ
	while (true) {
		x += dx[dir];
		y += dy[dir];
		if (x < 0 || x >= N || y < 0 || y >= M) return;
		if (checkboard[x][y] == 6) return;
		if (checkboard[x][y] != 0) continue;
		checkboard[x][y] = 7; // �����ٴ� ǥ�ø� # ��� 7
	}
}
void cctv1(int x, int y, int dir) {
	check(x, y, dir);
}
void cctv2(int x, int y, int dir) {
	check(x, y, dir);
	check(x, y, (dir + 2) % 4);
}
void cctv3(int x, int y, int dir) {
	check(x, y, dir);
	check(x, y, (dir + 1) % 4);
}
void cctv4(int x, int y, int dir) {
	check(x, y, dir);
	check(x, y, (dir + 1) % 4);
	check(x, y, (dir + 2) % 4);
}
void cctv5(int x, int y) {
	check(x, y, 0);
	check(x, y, 1);
	check(x, y, 2);
	check(x, y, 3);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// �Է�
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int tmp;
			cin >> tmp;
			board[i][j] = tmp;
			if (tmp > 0 && tmp < 6)
				cctv.push_back({ i,j });
			if (tmp == 0) ans++;
		}
	}

	// ���� by.����
	for (int num = 0; num < (1 << (2 * cctv.size())); num++) { // dir ** (cctv ����) ȸ ���� ����

		// �ʱ�ȭ
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				checkboard[i][j] = board[i][j];

		// tmp -> 4���� for dir ǥ�� 
		int tmp = num;
		for (int i = 0; i < cctv.size(); i++) {
			int x = cctv[i].X;
			int y = cctv[i].Y;
			int dir = tmp % 4;
			switch (board[x][y]) {
			case 1:
				cctv1(x, y, dir);
				break;
			case 2:
				cctv2(x, y, dir);
				break;
			case 3:
				cctv3(x, y, dir);
				break;
			case 4:
				cctv4(x, y, dir);
				break;
			case 5:
				cctv5(x, y);
				break;
			default: break;
			}
			tmp /= 4;
		}

		// �簢���� �� �� ��
		int cnt = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				cnt += (checkboard[i][j] == 0);

		if (ans > cnt) ans = cnt;

	}
	// ���
	cout << ans;
}