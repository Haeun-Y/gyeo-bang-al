/*
����
�ſ� ū ��ȭ���� �ڸ� ��� ���� �������� �Ѵ�.���� ���� ������ ���� �� ������ �ٸ� �� ������ �߰� �ȴ�.���� ���� ������ �̹� ���� �ִ� ��ġ�� ���ļ� �׸� ���� �ִµ�, ���� �� ���� ���� �� �� ���� ���� ���̸� ������ �� ���ٰ� ����.
�̿� ���� ������ ���� �׾��� ��, �׷��� ��(��)�� �� ���̸� ���ϴ� ���α׷��� �ۼ��Ͻÿ�. ���� ���� �� �׷��� ���� �� ������ ����Ѵ�.

�Է�
ù° �ٿ� ���� ���� Ƚ�� N(1 �� N �� 1, 000, 000)�� �־�����.���� N���� �ٿ��� ���� ���� �� ������ �� ���� ��ġ x, y(-1, 000, 000, 000 �� x < y �� 1, 000, 000, 000)�� �־�����.

���
ù° �ٿ� ���� ���� �� ���̸� ����Ѵ�.
*/

#define X first
#define Y second
int N, ans = 0; vector <pair<int, int>> dot;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.X == b.X) return a.Y > b.Y;
	else return a.X < b.X;
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N; int a, b;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		dot.push_back({ a,b });
	}
	if (N == 1) {
		cout << (b - a);
		return 0;
	}

	sort(dot.begin(), dot.end(), cmp);

	for (int i = 0; i < N; i++) {
		cout << dot[i].X << ' ' << dot[i].Y << '\n';
	}
	int head = dot[0].X; int tail = dot[0].Y;
	for (int i = 1; i < N; i++) {
		if (tail <= dot[i].X) {
			ans += (tail - head);
			head = dot[i].X; tail = dot[i].Y;
		}
		else if (tail < dot[i].Y) {
			tail = dot[i].Y;
		}
	}
	ans += (tail - head);
	cout << ans;
}
