/*
����
N-Queen ������ ũ�Ⱑ N �� N�� ü���� ���� �� N���� ���� ������ �� ���� ���� �����̴�.
N�� �־����� ��, ���� ���� ����� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� N�� �־�����. (1 �� N < 15)

���
ù° �ٿ� �� N���� ���� ������ �� ���� ���� ����� ���� ����Ѵ�.
*/
#include<bits/stdc++.h>
using namespace std;
int N, cnt = 0;

// �ð����⵵ ���̱� ->  isused �ڡڡ�
bool isused1[40], isused2[40], isused3[40]; // ��(y), �����ʴ밢��(x+y), ���ʴ밢��(y-x+N-1)

void func(int cur) { // cur��° �࿡ ���� ��ġ cur = 0,1,2...N-1
		if (cur == N) {
		cnt++;
		return;
	}
		for (int i = 0; i < N; i++) { // i : ��
			if (isused1[i] || isused2[i+cur] || isused3[cur-i+N -1]) // ��, �밢���� �̹� �� ����
				continue;
			isused1[i] = 1;
			isused2[i+cur] = 1;
			isused3[cur - i + N - 1] = 1;
			func(cur + 1);
			isused1[i] = 0;
			isused2[i + cur] = 0;
			isused3[cur - i+ N - 1] = 0;
		}
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	func(0);
	cout << cnt;
}