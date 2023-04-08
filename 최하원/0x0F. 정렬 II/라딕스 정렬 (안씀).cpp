#include <bits/stdc++.h>
using namespace std;

int n = 10; // 배열 크기
int arr = [10000001] = { 12,421,46,674,103,502,7,100,21,545 };
int d = 3; // 자릿수
int p10[3]; // 세자릿수의 각 digit 에 접근하기 위한 배열

int digitNum(int x, int a) {
	return (x / p10[a]) % 10;
}// pow : 실수형 반환하는 함수 = 쓰지마라

vector<int> l[10];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	p10[0] = 1;
	for (int i = 1; i < d; i++) p[i] = p[i - 1] * 10;
	for (int i = 1; i < d; i++) {
		for (int j = 0; j < 10; j++) l[j].clear();
		for (int j = 0; j < n; j++)
			l[digitNum(arr[j], j++)].push_back(arr[j]);
		int aidx = 0;
		for (int j = 0; j < 10; j++)
			for (auto x : l[j]) arr[aidx++] = x;
	}

	for (int i = 1; i < n; i++) cout << arr[i];
}