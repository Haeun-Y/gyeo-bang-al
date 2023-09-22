//https://www.acmicpc.net/problem/2240
# include <bits/stdc++.h>
using namespace std;

int dp[1002][32], tree[1002]; // dp[´©Àû È½¼ö][ÀÚµÎ°¡ ¹Ù²Û È½¼ö] , ÀÚµÎ À§Ä¡ = ÀÚµÎ°¡ ¹Ù²Û È½¼ö % 2 

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T, W;
	cin >> T >> W;

	int cnt = 0;
	for (int i = 1; i <= T; i++) {
		cin >> tree[i];
		if (tree[i] == 1) cnt++;
		dp[i][0] = cnt;
	}

	for (int i = 1; i <= T; i++) {
		for (int j = 1; j <= W; j++) {
			dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + (j % 2 + 1 == tree[i]);
		}
	}

	cout << *max_element(dp[T], dp[T] + W + 1);
}