/*
문제
단어 위로 아치형 곡선을 그어 같은 글자끼리(A는 A끼리, B는 B끼리) 쌍을 짓기로 하였다.
만약 선끼리 교차하지 않으면서 각 글자를 정확히 한 개의 다른 위치에 있는 같은 글자와 짝 지을수 있다면, 그 단어는 '좋은 단어'이다.

입력
첫째 줄에 단어의 수 N이 주어진다. (1 ≤ N ≤ 100)
다음 N개 줄에는 A와 B로만 이루어진 단어가 한 줄에 하나씩 주어진다.
단어의 길이는 2와 100, 000사이이며, 모든 단어 길이의 합은 1, 000, 000을 넘지 않는다.

출력
첫째 줄에 좋은 단어의 수를 출력한다.
*/
// 자료구조 중에 스택을 이용 괄호문제와 거의 동일

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