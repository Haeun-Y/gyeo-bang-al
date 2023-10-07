// https://www.acmicpc.net/problem/15686

#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int N, M, ans = 1e6;
vector<pair<int, int>> chicken, home, v;
bool visited[51];

int cnt_all_dist(vector<pair<int, int>> v) {
	int sum = 0;
	for (int i = 0; i < home.size(); i++) {
		int min_dist = 1e6;
		for (int j = 0; j < v.size(); j++) {
			int dist = abs(home[i].X - v[j].X) + abs(home[i].Y - v[j].Y);
			min_dist = min(dist, min_dist);
		}
		sum += min_dist;
	}
	return sum;
}

void combi(int idx) {

	if (v.size() == M) {
		int sum = cnt_all_dist(v);
		ans = min(sum, ans);
		return;
	}


	for (int i = idx; i < chicken.size(); i++) {
		if (visited[i]) continue;
		v.push_back(chicken[i]);
		visited[i] = 1;
		combi(i + 1); // ¡Ú
		v.pop_back();
		visited[i] = 0;
	}
}

int main(void) {

	cin >> N >> M;
	int tmp;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> tmp;
			if (tmp == 1) home.push_back({ i,j });
			else if (tmp == 2) chicken.push_back({ i,j });
		}
	}

	combi(0);

	cout << ans;
	return 0;
}