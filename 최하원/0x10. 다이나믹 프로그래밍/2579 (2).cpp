// dp 2차원 배열 이용
// dp[][1] = 계단 1개 밟음 vs dp[][2] = 계단 2개 연속 밟음
int n, stair[305], dp[305][3];

int main(void) {

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> stair[i];

	if (n == 1) {
		cout << stair[1];
		return 0;
	}

	dp[1][1] = stair[1]; dp[1][2] = 0; 
	dp[2][1] = stair[2]; dp[2][2] = stair[1] + stair[2];

	for (int i = 3; i <= n; i++) {
		dp[i][1] = stair[i] + max(dp[i - 2][1], dp[i - 2][2]);
		dp[i][2] = stair[i] + dp[i - 1][1];
	}
	cout << max(dp[n][1], dp[n][2]);
}