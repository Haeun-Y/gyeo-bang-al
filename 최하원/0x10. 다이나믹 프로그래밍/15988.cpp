//https://www.acmicpc.net/problem/15988
# include <bits/stdc++.h>
using namespace std;

int dp[1000005], MOD = 1000000009;
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T, n;

	dp[1] = 1; dp[2] = 2; dp[3] = 4;
	for (int i = 4; i <= 1000000; i++)
		// !! 오버플로우
		dp[i] = (((dp[i - 1] + dp[i - 2]) % MOD) + dp[i - 3]) % MOD;

	cin >> T;
	while (T--) {
		cin >> n;
		cout << dp[n] << '\n';
	}
}