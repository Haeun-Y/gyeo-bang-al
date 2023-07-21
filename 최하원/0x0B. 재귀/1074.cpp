/*
문제
2N × 2N인 2차원 배열을 Z모양으로 탐색하려고 한다. 예를 들어, 2×2배열을 왼쪽 위칸, 오른쪽 위칸, 왼쪽 아래칸, 오른쪽 아래칸 순서대로 방문하면 Z모양이다.
N이 주어졌을 때, r행 c열을 몇 번째로 방문하는지 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 정수 N, r, c가 주어진다.

출력
r행 c열을 몇 번째로 방문했는지 출력한다.

제한
1 ≤ N ≤ 15
0 ≤ r, c < 2^N
*/

int power(int n) {
	if (n == 0) return 1;
	return 2 * power(n - 1);
}
int func(int n, int r, int c) {
	if (n == 0) return 0;
	int tmp = power(n - 1);
	return tmp * tmp * (2 * (r >= tmp) + (c >= tmp)) + func(n - 1, r % tmp, c % tmp);
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, r, c;
	cin >> N >> r >> c;
	cout << func(N, r, c);
}