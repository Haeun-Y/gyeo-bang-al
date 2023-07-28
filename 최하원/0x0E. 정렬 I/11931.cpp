// https://www.acmicpc.net/problem/11931

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long n;
	cin >> n;
	int list[10002] = { 0 };

	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		list[tmp]++;
	}

	for (int i = 10001; i >= 0; i--) 
		for (int j = 0; j < list[i]; j++)
			cout << i << '\n';
	
}