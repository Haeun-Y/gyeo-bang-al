/*
����
2N �� 2N�� 2���� �迭�� Z������� Ž���Ϸ��� �Ѵ�. ���� ���, 2��2�迭�� ���� ��ĭ, ������ ��ĭ, ���� �Ʒ�ĭ, ������ �Ʒ�ĭ ������� �湮�ϸ� Z����̴�.
N�� �־����� ��, r�� c���� �� ��°�� �湮�ϴ��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ���� N, r, c�� �־�����.

���
r�� c���� �� ��°�� �湮�ߴ��� ����Ѵ�.

����
1 �� N �� 15
0 �� r, c < 2^N
*/

int power(int n) {
	if (n == 0) return 1;
	return 2 * power(n - 1);
}
int func(int n, int r, int c) {
	if (n == 0) return 0;
	int tmp = power(n - 1);
	return tmp * tmp * (2 * (r >= tmp) + (c >= tmp)) + func(n - 1, r % tmp, c % tmp);
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, r, c;
	cin >> N >> r >> c;
	cout << func(N, r, c);
}