// https://www.acmicpc.net/problem/10989
#include <bits/stdc++.h>
using namespace std;

int l[1000005];
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;

	for (int i = 0; i < n; i++)
		cin >> l[i];

	sort(l, l + n);
	// sort(a, a + n, greater<int>()); greater<�ڷ���> : �������� �Լ�

	for (int i = n - 1; i >= 0;i--)
		cout << l[i] << '\n';
}