/*
문제
정렬되어있는 두 배열 A와 B가 주어진다. 두 배열을 합친 다음 정렬해서 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 배열 A의 크기 N, 배열 B의 크기 M이 주어진다. (1 ≤ N, M ≤ 1,000,000)

둘째 줄에는 배열 A의 내용이, 셋째 줄에는 배열 B의 내용이 주어진다. 배열에 들어있는 수는 절댓값이 109보다 작거나 같은 정수이다.

출력
첫째 줄에 두 배열을 합친 후 정렬한 결과를 출력한다.
*/

// NULL 쓰지마
// stable sort (두 가지 기준으로 정렬할 때, 한 가지의 기준은 유지하면서 나머지 기준으로 정렬)
#include <bits/stdc++.h>
using namespace std;

int N, M, A[1000005], B[1000005], ans[2000010], A_idx = 0, B_idx = 0;

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)	cin >> A[i];
	for (int i = 0; i < M; i++)	cin >> B[i];

	for (int i = 0; i < N + M; i++) {
		if (A_idx == N) ans[i] = B[B_idx++];
		else if (B_idx == M) ans[i] = A[A_idx++];
		else if (A[A_idx] < B[B_idx]) ans[i] = A[A_idx++];
		else ans[i] = B[B_idx++];
	}
	for (int i = 0; i < N + M; i++) cout << ans[i] << " ";
}
