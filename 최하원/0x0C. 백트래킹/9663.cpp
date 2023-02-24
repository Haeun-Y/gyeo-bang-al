/*
문제
N-Queen 문제는 크기가 N × N인 체스판 위에 퀸 N개를 서로 공격할 수 없게 놓는 문제이다.
N이 주어졌을 때, 퀸을 놓는 방법의 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N이 주어진다. (1 ≤ N < 15)

출력
첫째 줄에 퀸 N개를 서로 공격할 수 없게 놓는 경우의 수를 출력한다.
*/
#include<bits/stdc++.h>
using namespace std;
int N, cnt = 0;

// 시간복잡도 줄이기 ->  isused ★★★
bool isused1[40], isused2[40], isused3[40]; // 열(y), 오른쪽대각선(x+y), 왼쪽대각선(y-x+N-1)

void func(int cur) { // cur번째 행에 말을 배치 cur = 0,1,2...N-1
		if (cur == N) {
		cnt++;
		return;
	}
		for (int i = 0; i < N; i++) { // i : 열
			if (isused1[i] || isused2[i+cur] || isused3[cur-i+N -1]) // 열, 대각선에 이미 퀸 있음
				continue;
			isused1[i] = 1;
			isused2[i+cur] = 1;
			isused3[cur - i + N - 1] = 1;
			func(cur + 1);
			isused1[i] = 0;
			isused2[i + cur] = 0;
			isused3[cur - i+ N - 1] = 0;
		}
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	func(0);
	cout << cnt;
}