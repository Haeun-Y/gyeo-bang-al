// 하노이 탑 이동 순서 및 횟수 출력

#include <bits/stdc++.h>
using namespace std;

int cnt(int n) { // 횟수 계산 함수
	if (n == 1) return 1;
	return 2 * cnt(n - 1) + 1;
}
void func(int from, int to, int n) { // 이동 출력 함수
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

	int n;	cin >> n; // 입력
	cout << cnt(n) << '\n'; // 횟수 출력
	func(1, 3, n); // 이동 출력
}