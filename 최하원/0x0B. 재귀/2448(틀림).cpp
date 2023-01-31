/*
����
������� �������� ���� ��� ����. N�� 3�� �ŵ�����(3, 9, 27, ...)�̶�� �� ��, ũ�� N�� ������ N��N ���簢�� ����̴�.
ũ�� 3�� ������ ����� ������ �ְ�, ����� ������ ��� ĭ�� ���� �ϳ��� �ִ� �����̴�.
***
* *
***
N�� 3���� Ŭ ���, ũ�� N�� ������ �������� ä���� �����(N / 3)��(N / 3) ���簢���� ũ�� N / 3�� �������� �ѷ��� �����̴�.
���� ��� ũ�� 27�� ������ ���� ��� 1�� ����.
�Է�
ù° �ٿ� N�� �־�����.N�� 3�� �ŵ������̴�.�� � ���� k�� ���� N = 3k�̸�, �̶� 1 �� k < 8�̴�.
���
ù° �ٺ��� N��° �ٱ��� ���� ����Ѵ�.
*/

#include<bits/stdc++.h>
using namespace std;
const int MAX = 6561;
char m[MAX][MAX];

void star(int row, int col) {
	for (int i = col; i < col + 3; i++) m[row][i] = '*';
	for (int i = col; i < col + 3; i += 2) m[row + 1][i] = '*';
	for (int i = col; i < col + 3; i++) m[row + 2][i] = '*';
}
void func(int n, int row, int col) {
	if (n == 3) {
		star(row, col);
		return;
	}
	for (int i = 3; i <= n; i += 3) {

		func(n / 3, row, col);
		func(n / 3, row + i, col);
		func(n / 3, row, col + i);
		func(n / 3, row + i, col + i);
	}


}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; // 3, 9, 27 ...
	cin >> n;
	func(n, 0, 0);


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (m[i][j] == '*') cout << '*';
			else cout << ' ';
		}
		cout << "\n";
	}
}