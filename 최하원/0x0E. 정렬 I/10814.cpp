// https://www.acmicpc.net/problem/10814

#include <bits/stdc++.h>
using namespace std;

bool func(pair<int, string> a, pair <int, string> b) {
	return a.first < b.first;
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, age; string name;
	cin >> n;
	vector <pair<int, string>> judge;

	for (int i = 0; i < n;i++) {
		cin >> age >> name;
		judge.push_back(make_pair(age, name));
	}
	stable_sort(judge.begin(), judge.end(), func);

	for (int i = 0; i < n; i++) cout << judge[i].first << ' ' << judge[i].second << '\n';

	return 0;
}