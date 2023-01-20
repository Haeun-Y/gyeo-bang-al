#include<bits/stdc++.h>
using namespace std;
// ��Ģ���� �� �ľ��ϰ�(���⼭ �ָ���) & ��ͷ� ����
// �ٷ� ����� �õ������� �����ؼ� ��Ŀ� ���� �� �Ѳ����� ��� ����
const int MAX = 3072;// n = 3X2^k (k = 0,1,2 ... 10) �ִ� 3072, int �̿� 
char m[MAX][MAX * 2]; // �������� �� 24, �� 48���� �̿��Ͽ� ����

void star(int row, int col) { // star: * ���� �Լ�, row, col �� ������ ���� ��ġ

	// ù ��° ��										*
	m[row][col] = '*';
	// �� ��° ��									   * * 	
	m[row + 1][col - 1] = m[row + 1][col + 1] = '*';
	// �� ��° ��									  *****
	for (int i = col - 2; i <= col + 2; i++)
		m[row + 2][i] = '*';
}

void func(int n, int row, int col) { // func : star �Լ� ��������� �����ϴ� �Լ�, �� �� ����� �� ���� 6�� �ﰢ�� �ϳ� ����
	if (n == 3) { // base condition
		star(row, col);
		return;
	}
	int mid = n / 2;

	func(mid, row, col); // �� �߾� �ﰢ��
	func(mid, row + mid, col - mid); // �Ʒ� ���� �ﰢ��
	func(mid, row + mid, col + mid); // �Ʒ� ������ �ﰢ�� 


}
int main(void) { // main : ����� �Է�, ��� ���
	ios::sync_with_stdio(0);
	cin.tie(0);

	// ����� �Է�
	int n;
	cin >> n;
	// func �Լ� ����
	// matrix ũ��[n][2n], �� �� ������ ���� ��ġ (0, n-1)
	func(n, 0, n - 1);

	// ��� ���
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n * 2; j++) {
			if (m[i][j] == '*') cout << '*';
			else cout << ' ';
		}
		cout << "\n";
	}
}