// https://www.acmicpc.net/problem/2847

#include<bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, arr[102], ans = 0;
	cin >> n;

	for (int i = 0; i < n; i++) cin >> arr[i];

	for (int i = n - 1; i > 0; i--) {
		if (arr[i - 1] >= arr[i]) {
			int d = arr[i - 1] - arr[i] + 1;
			arr[i - 1] -= d;
			ans += d;
		}
	}
	cout << ans << '\n';
}