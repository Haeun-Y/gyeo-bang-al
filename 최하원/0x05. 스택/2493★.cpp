#include<bits/stdc++.h>
using namespace std;

stack<pair<int, int>> S;
int n;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	S.push({ 0,100000001 });

	for (int i = 1; i <= n; i++) {
		int tmp;
		cin >> tmp;
		while (S.top().second <= tmp) S.pop();
		cout << S.top().first << " ";
		S.push({ i,tmp });
	}
}

// 공부할 거리 (pair 안 쓰는 방법)
/* https://seokjin2.tistory.com/61
int height[500001];
int res[500001];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie();

	int n; cin >> n;
	stack<int> big;
	for (int i = 1; i <= n; i++) {
		cin >> height[i];
	}

	big.push(0);

	for (int i = 1; i < n; i++) {
		res[i] = big.top(); //스택에 top()은 i번째 레이저를 수신
		if (height[i + 1] > height[i] && big.top()) {
			while (height[big.top()] < height[i + 1] && big.top()) {//스택의 top()이 i+1번째 탑보다 커야 하므로 작은 top()은 제거
				big.pop();
			}
		}
		else if (height[i + 1] < height[i]) {
			big.push(i);//i번째 탑을 i+1번째 탑이 만나는 가장 가까우면서 큰 탑으로 만듬
		}
		else if (height[i + 1] == height[i]) { // 연속된 크기의 탑일 경우엔 가장 가까운 탑이 수신하도록 함
			big.pop();
			big.push(i);
		}
	}
	res[n] = big.top();
	for (int i = 1; i <= n; i++) {
		cout << res[i] << " ";
	}
	return 0;
}