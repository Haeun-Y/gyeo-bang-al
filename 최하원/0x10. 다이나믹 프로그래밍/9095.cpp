/*
문제
정수 4를 1, 2, 3의 합으로 나타내는 방법은 총 7가지가 있다.합을 나타낼 때는 수를 1개 이상 사용해야 한다.

1 + 1 + 1 + 1
1 + 1 + 2
1 + 2 + 1
2 + 1 + 1
2 + 2
1 + 3
3 + 1
정수 n이 주어졌을 때, n을 1, 2, 3의 합으로 나타내는 방법의 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스는 한 줄로 이루어져 있고, 정수 n이 주어진다.n은 양수이며 11보다 작다.

출력
각 테스트 케이스마다, n을 1, 2, 3의 합으로 나타내는 방법의 수를 출력한다.
*/
#include <bits/stdc++.h>
using namespace std;
int n, dp[13];
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	dp[1] = 1; dp[2] = 2; dp[3] = 4;
	for (int i = 4; i <= 10; i++)
		dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
	
	cin >> n;
	while (n--) {
		int tmp; 
		cin >> tmp;
		cout << dp[tmp] << '\n';
	}
	cout << dp[n];
}