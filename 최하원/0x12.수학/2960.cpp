//https://www.acmicpc.net/problem/2960
#include<bits/stdc++.h>
using namespace std;
int main(void) {
	int N, K, cnt = 0;
	bool vis[1001];
	cin >> N >> K;

	for (int i = 2; i <= N; i++)
		vis[i] = 0;

	for (int i = 2; i <= N; i++) {
		if (vis[i]) continue;
		for (int j = i; j <= N; j++) {
			if (j % i == 0) {
				if (vis[j]) continue;
				vis[j] = 1;
				cnt++;
				if (cnt == K) {
					cout << j;
					return 0;
				}
			}
		}
	}
	return -1;
}