// https://www.acmicpc.net/problem/6603

#include <bits/stdc++.h>
using namespace std;
int N, num[14], lotto[7], isused[14];

void func(int n, int idx) {
	if (n == 6) {
		for (int i = 0; i < 6; i++) cout << lotto[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = idx; i < N; i++) {
		if (!isused[i]) {
			lotto[n] = num[i];
			isused[i] = 1;
			func(n + 1, i + 1);
			isused[i] = 0;
		}
	}
}


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	do {
		cin >> N;
		for (int i = 0; i < N; i++) cin >> num[i];
		func(0, 0);
		cout << '\n';
	} while (N != 0);
}