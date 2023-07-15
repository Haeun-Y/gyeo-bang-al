/*
문제
주어진 수 N개 중에서 소수가 몇 개인지 찾아서 출력하는 프로그램을 작성하시오.
입력
첫 줄에 수의 개수 N이 주어진다. N은 100이하이다. 다음으로 N개의 수가 주어지는데 수는 1,000 이하의 자연수이다.
출력
주어진 수들 중 소수의 개수를 출력한다.
*/
int isprime(int n) {
	if (n ==1) return 0;
	for (int i = 2; i * i <= n; i++) 
		if (n % i == 0) return 0;
	return 1;
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, ans = 0;

	cin >> N;
	while (N--) {
		int tmp;
		cin >> tmp;
		ans += isprime(tmp);
	}
	cout << ans << "\n";
}