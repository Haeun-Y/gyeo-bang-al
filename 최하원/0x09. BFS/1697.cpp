// https://www.acmicpc.net/problem/1697
// 수빈이가 5-10-9-18-17 순으로 가면 4초만에 동생을 찾을 수 있다.
// 메모리 초과 주의
# include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, t = 0; queue<int> Q;
	int dist[100002];
	fill(dist, dist + 100001, -1);
	cin >> n >> m;

	Q.push({ n }); dist[n] = 0;
	while (dist[m] == -1) {
		n = Q.front(); Q.pop();
		for (int nxt : {n - 1, n + 1, 2 * n}) {
			if (nxt < 0 || nxt > 100000) continue;
			if (dist[nxt] != -1) continue;
			dist[nxt] = dist[n] + 1;
			Q.push(nxt);
		}
	}
	cout << dist[m];
	return 0;
}