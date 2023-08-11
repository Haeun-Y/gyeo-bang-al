// https://www.acmicpc.net/problem/14002
#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int arr[1002], dp[1002], N, ans = 0;

	// 입력
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	fill(dp, dp + N, 1);

	// DP
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	// 출력
	int MAX = *max_element(dp, dp + N), max_idx;
	for (int i = 0; i < N; i++) {
		if (dp[i] == MAX) {
			max_idx = i;
			break;
		}
	}
	cout << MAX << '\n';

	stack<int> S; S.push(arr[max_idx]);

	for (int i = max_idx - 1; i >= 0; i--) {
		if (arr[i] < S.top() && dp[i] == dp[max_idx] - 1) {
			S.push(arr[i]);
			max_idx = i;
		}
	}
	while (!S.empty()) {
		cout << S.top() << ' ';
		S.pop();
	}
}
