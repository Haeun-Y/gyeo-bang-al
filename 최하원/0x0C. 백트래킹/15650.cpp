/*
문제
자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.
1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열
고른 수열은 오름차순이어야 한다.

입력
첫째 줄에 자연수 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 8)

출력
한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 중복되는 수열을 여러 번 출력하면 안되며, 각 수열은 공백으로 구분해서 출력해야 한다.
수열은 사전 순으로 증가하는 순서로 출력해야 한다.
*/
# include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[10];

void func(int k, int idx) { // k는 현재까지 넣은 정수의 갯수, idx는 현재까지 계산한 정수
	if (idx <= N + 1) { // idx 가 N이 될때까지 func 함수 실행
		if (k == M) { // 길이 M의 수열 완성 했으므로 출력
			for (int i = 0; i < M; i++)
				cout << arr[i] << ' ';
			cout << '\n';
			return;
		}
		arr[k] = idx;
		func(k + 1, idx + 1); // arr[k+1] = idx + 1 실행
		func(k, idx + 1); //  // arr[k] = idx + 1 실행, 즉 현재 arr[k] = idx 무시 
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	func(0, 1);
}