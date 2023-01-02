#include<bits/stdc++.h>
using namespace std;

int n, x, a[10005];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> x;
	for (int i = 0; i < x; i++) cin >> a[i];
	for (int i = 0; i < x; i++) if (a[i] < x) cout << a[i] << ' ';
}