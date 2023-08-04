// https://www.acmicpc.net/problem/14888
// 백트래킹
# include<bits/stdc++.h>
using namespace std;

int N, arr[102], op[4], max_val = -100000000, min_val = 100000000;
void func(int cnt, int result) {
	if (cnt == N - 1) {
		max_val = max(max_val, result);
		min_val = min(min_val, result);
	}

	for (int i = 0; i < 4; i++) {
		if (!op[i]) continue;
		op[i]--;
		if (i == 0) func(cnt + 1, result + arr[cnt + 1]);
		if (i == 1) func(cnt + 1, result - arr[cnt + 1]);
		if (i == 2) func(cnt + 1, result * arr[cnt + 1]);
		if (i == 3) func(cnt + 1, result / arr[cnt + 1]);
		op[i]++;
	}
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	for (int i = 0; i < 4; i++) cin >> op[i];

	func(0, arr[0]);

	cout << max_val << "\n" << min_val << "\n";

}