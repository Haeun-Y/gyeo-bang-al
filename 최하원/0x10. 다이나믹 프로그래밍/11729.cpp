// �ϳ��� ž �̵� ���� �� Ƚ�� ���

#include <bits/stdc++.h>
using namespace std;

int cnt(int n) { // Ƚ�� ��� �Լ�
	if (n == 1) return 1;
	return 2 * cnt(n - 1) + 1;
}
void func(int from, int to, int n) { // �̵� ��� �Լ�
	if (n == 1) {
		cout << from << ' ' << to << '\n';
		return;
	}
	func(from, 6 - from - to, n - 1);
	cout << from << ' ' << to << '\n';
	func(6 - from - to, to, n - 1);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;	cin >> n; // �Է�
	cout << cnt(n) << '\n'; // Ƚ�� ���
	func(1, 3, n); // �̵� ���
}