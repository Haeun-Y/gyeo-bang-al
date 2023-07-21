/*
�Է�
ù° �ٿ� ��Ʈ���� ���ο� ���� ���̸� ��Ÿ���� N(1 �� N �� 40)�� M(1 �� M �� 40), �׸��� ��ƼĿ�� ���� K(1 �� K �� 100)�� �� ĭ�� ��ĭ�� ���̿� �ΰ� �־�����.
�� ���� �ٺ��ʹ� K���� ��ƼĿ�鿡 ���� ������ �־�����. �� ��ƼĿ�� �Ʒ��� ���� �������� �־�����.
���� i��° ��ƼĿ�� �μ�� �������� ���� ������ ���� ������ ��Ÿ���� Ri(1 �� Ri �� 10)�� Ci(1 �� Ci �� 10)�� �� ĭ�� ��ĭ�� ���̿� �ΰ� �־�����.
���� Ri���� �ٿ��� �� �ٸ��� �������� �� ���� ��Ÿ���� Ci���� ������ �� ���� ��ĭ�� ���̿� �ΰ� �־�����. �� ĭ�� ���� ���� 0, 1�̴�. 0�� ��ƼĿ�� ���� ���� ĭ��, 1�� ��ƼĿ�� ���� ĭ�� �ǹ��Ѵ�.
�������� ������ �Ͱ� ���� ��ƼĿ�� ��� �ùٸ� �����̿� �μ�Ǿ� �ִ�. ��ü������ ��ƼĿ�� �� ĭ�� �����¿�� ��� ����Ǿ� �ְ�, �������� ũ��� ��ƼĿ�� ũ�⿡ �� �¾Ƽ� �����¿쿡 ��ƼĿ�� ���� ���Ե��� �ʴ� ���ʿ��� ���̳� ���� �������� �ʴ´�.

���
ù° �ٿ� �־��� ��ƼĿ���� ���ʴ�� �ٿ��� �� ��Ʈ�Ͽ��� ��ƼĿ�� ���� ĭ�� ���� ����Ѵ�.
*/
#include <bits/stdc++.h>
using namespace std;

int sticker[12][12], board[42][42], N, M, r, c;

void rotate() { // �ð� 90�� ȸ��
	int tmp[12][12];
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)
			tmp[i][j] = sticker[i][j];
	}
	for (int i = 0; i < c; i++) {
		for (int j = 0; j < r; j++)
			sticker[i][j] = tmp[r - 1 - j][i];
	}
	swap(r, c);
}
bool attach(int x, int y) { // ���� �� �ִ��� ���� Ȯ�� �� �����ϸ� ����
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (sticker[i][j] && board[x + i][y + j]) return false;
		}
	}
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (sticker[i][j]) board[x + i][y + j] = 1;
	return true;
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// �Է� 
	int K, ans = 0;
	cin >> N >> M >> K;

	while (K--) {
		cin >> r >> c;
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				cin >> sticker[i][j];

		for (int n = 0; n < 4; n++) {
			bool isPaste = false;
			for (int i = 0; i <= N - r; i++) {
				if (isPaste) break;
				for (int j = 0; j <= M - c; j++) {
					if (attach(i, j)) {
						isPaste = true;
						break;
					}
				}
			}
			if (isPaste) break;
			rotate();
		}
	}

	// ���
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			ans += board[i][j];

	cout << ans;
}