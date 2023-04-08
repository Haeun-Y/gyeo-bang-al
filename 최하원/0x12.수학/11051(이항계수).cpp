/*
문제
자연수 N과 정수 K가 주어졌을 때 이항 계수 NCK를 10007로 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N과 K가 주어진다. (1 ≤ N ≤ 1000, 0 ≤ K ≤ N)

출력
NCK를 출력한다.
*/
int func(int n) {
	if (n == 1 || n == 0) return 1;
	else return n * func(n - 1);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N, K, ans;
	cin >> N >> K;
	ans = func(N) / func(N - K) / func(K);
	cout << ans;
}