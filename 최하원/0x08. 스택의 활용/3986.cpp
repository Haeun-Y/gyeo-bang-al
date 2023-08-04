// https://www.acmicpc.net/problem/3986

#include<bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, ans = 0; cin >> N;

	while (N--) {
		stack<char> S;
		string s;
		cin >> s;
		for (auto c : s) {
			if (S.empty()) S.push(c);
			else {// S not empty
				if (S.top() == c) S.pop();
				else S.push(c);
			}
		}
		if (S.empty()) ans++;
	}
	cout << ans << "\n";
}