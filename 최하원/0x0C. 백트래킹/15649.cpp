/*
문제
자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.
1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열

입력
첫째 줄에 자연수 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 8)
출력
한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 중복되는 수열을 여러 번 출력하면 안되며, 각 수열은 공백으로 구분해서 출력해야 한다.
수열은 사전 순으로 증가하는 순서로 출력해야 한다.
*/

// 백트래킹 + 재귀를 이용한 풀이
# include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[10];
bool issued[10];

void func(int k) { 
	// 출력 여부를 결정, 현재 k개(k<=m) 까지 수를 택했음
	if (k == M) { // m개를 모두 택했으면
		for (int i = 0; i < M; i++)
			cout << arr[i] << ' '; // arr에 기록해둔 수를 출력
		cout << '\n';
		return;
	}

	for (int i = 1; i <= N; i++) { // 1부터 n까지의 수에 대해
		if (!issued[i]) { // 아직 i가 사용되지 않았으면
			arr[k] = i; // k번째 수를 i로 정함
			issued[i] = 1; // i를 사용했다고 표시
			func(k + 1); // 다음 수를 정하러 한 단계 더 들어감
			issued[i] = 0; // k번째 수를 i로 정한 모든 경우에 대해 다 확인했으니 이제 i를 사용하지 않았다고 표시
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	func(0);
}