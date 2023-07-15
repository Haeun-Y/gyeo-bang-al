/*
문제
M이상 N이하의 소수를 모두 출력하는 프로그램을 작성하시오.
입력
첫째 줄에 자연수 M과 N이 빈 칸을 사이에 두고 주어진다. (1 ≤ M ≤ N ≤ 1,000,000) M이상 N이하의 소수가 하나 이상 있는 입력만 주어진다.
출력
한 줄에 하나씩, 증가하는 순서대로 소수를 출력한다.
*/
vector<bool> state(1000005, true); // 소수면 true, 소수 아니면 false

void func(int n) {
	state[1] = false;
	for (int i = 2; i * i <= n; i++) { 
		if (state[i] == false) continue;
		for (int j = i + i; j <= n; j += i) // i + i 보다 빠름
			state[j] = false;

	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int M, N;
	cin >> M >> N;
	func(N);
	for (int i = M; i <= N; i++)
		if (state[i]) cout << i << "\n";
}