/*
문제
수 N개가 주어졌을 때, i번째 수부터 j번째 수까지 합을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 수의 개수 N과 합을 구해야 하는 횟수 M이 주어진다. 둘째 줄에는 N개의 수가 주어진다. 수는 100,000보다 작거나 같은 자연수이다. 
셋째 줄부터 M개의 줄에는 합을 구해야 하는 구간 i와 j가 주어진다.

출력
총 M개의 줄에 입력으로 주어진 i번째 수부터 j번째 수까지 합을 출력한다.
*/

// 어려운 문제는 아니지만 보이는 대로 풀면 시간복잡도 O(NM)
// dp를 통해 획기적으로 풀기 -> Prefix Sum

int N, M, num[100003], sum[100003], ii, jj;
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 1; i < N; i++) {
		int tmp;
		cin >> tmp;
		num[i] = tmp;
		sum[i] = tmp + sum[i-1]
	}
	while (M--) {
		cin >> ii >> jj;
		cout << tmp[jj] - tmp[ii-1] << '\n';
	}
}