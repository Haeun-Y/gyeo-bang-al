/*
����
N���� ������ �̷���� ������ ���� ��, ũ�Ⱑ ����� �κм��� �߿��� �� ������ ���Ҹ� �� ���� ���� S�� �Ǵ� ����� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ������ ������ ��Ÿ���� N�� ���� S�� �־�����. (1 �� N �� 20, |S| �� 1,000,000)
��° �ٿ� N���� ������ �� ĭ�� ���̿� �ΰ� �־�����. �־����� ������ ������ 100,000�� ���� �ʴ´�.

���
ù° �ٿ� ���� S�� �Ǵ� �κм����� ������ ����Ѵ�.
*/
#include<bits/stdc++.h>
using namespace std;
int N, S, arr[20], sum = 0, ans = 0, idx = 0;

void func(int sum, int idx) {
	if (idx == N) {
		if (sum == S) ans++;
		return;
	}
	func(sum + arr[idx], idx + 1); // ����
	func(sum, idx + 1); // ������ ����
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> S;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	func(0, 0);
	if (S == 0) ans--; // �� ������
	cout << ans;
}