// https://www.acmicpc.net/problem/11652

#include <bits/stdc++.h>
using namespace std;
long long a[100005];
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; 	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	sort(a, a + n);

	int idx = 0, max = 0, cnt = 1;
	for (int i = 0; i < n - 1; i++) {
		if (a[i] == a[i + 1]) {
			cnt++;
			if (cnt > max) {
				max = cnt;
				idx = i;
			}
		}
		else cnt = 1;
	}
	cout << a[idx];
}