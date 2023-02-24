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

// ������ �Ÿ� (pair �� ���� ���)
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
		res[i] = big.top(); //���ÿ� top()�� i��° �������� ����
		if (height[i + 1] > height[i] && big.top()) {
			while (height[big.top()] < height[i + 1] && big.top()) {//������ top()�� i+1��° ž���� Ŀ�� �ϹǷ� ���� top()�� ����
				big.pop();
			}
		}
		else if (height[i + 1] < height[i]) {
			big.push(i);//i��° ž�� i+1��° ž�� ������ ���� �����鼭 ū ž���� ����
		}
		else if (height[i + 1] == height[i]) { // ���ӵ� ũ���� ž�� ��쿣 ���� ����� ž�� �����ϵ��� ��
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