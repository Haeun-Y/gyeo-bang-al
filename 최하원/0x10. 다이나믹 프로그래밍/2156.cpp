// https://www.acmicpc.net/problem/2156
#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, wine[10005], dp[10005];
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> wine[i];

	dp[0] = 0; dp[1] = wine[1]; dp[2] = wine[1] + wine[2];
	for (int i = 3; i <= n; i++) dp[i] = max({ dp[i - 1], wine[i] + dp[i - 2], wine[i] + wine[i - 1] + dp[i - 3] });

	cout << dp[n];
}