/*
입력
첫째 줄에 사무실의 세로 크기 N과 가로 크기 M이 주어진다. (1 ≤ N, M ≤ 8)
둘째 줄부터 N개의 줄에는 사무실 각 칸의 정보가 주어진다. 0은 빈 칸, 6은 벽, 1~5는 CCTV를 나타내고, 문제에서 설명한 CCTV의 종류이다. 
CCTV의 최대 개수는 8개를 넘지 않는다.

출력
첫째 줄에 사각 지대의 최소 크기를 출력한다.
*/

//CCTV의 위치를 따로 저장합니다.
//CCTV를 하나씩 추가합니다.이때 각각의 CCTV는 회전이 가능하므로 그 회전의 경우 역시 모두 확인해야 합니다.
//CCTV를 모두 추가한 후에는 사각지대의 수를 계산하고 최솟값을 업데이트 합니다.
//CCTV가 아예 없는 경우가 있을 수 있는데 이때는 빈칸수를 세어 답으로 합니다.

# define X first
# define Y second

int N, M, board[10][10], checkboard[10][10], ans = 0;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
vector<pair<int, int>> cctv;

void check(int x, int y, int dir) { // 직진 체크
	while (true) {
		x += dx[dir];
		y += dy[dir];
		if (x < 0 || x >= N || y < 0 || y >= M) return;
		if (checkboard[x][y] == 6) return;
		if (checkboard[x][y] != 0) continue;
		checkboard[x][y] = 7; // 지났다는 표시를 # 대신 7
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

	// 입력
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

	// 구현 by.진법
	for (int num = 0; num < (1 << (2 * cctv.size())); num++) { // dir ** (cctv 갯수) 회 연산 시행

		// 초기화
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				checkboard[i][j] = board[i][j];

		// tmp -> 4진법 for dir 표기 
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

		// 사각지대 셈 후 비교
		int cnt = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				cnt += (checkboard[i][j] == 0);

		if (ans > cnt) ans = cnt;

	}
	// 출력
	cout << ans;
}