/*
����
���ĵǾ��ִ� �� �迭 A�� B�� �־�����. �� �迭�� ��ģ ���� �����ؼ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �迭 A�� ũ�� N, �迭 B�� ũ�� M�� �־�����. (1 �� N, M �� 1,000,000)

��° �ٿ��� �迭 A�� ������, ��° �ٿ��� �迭 B�� ������ �־�����. �迭�� ����ִ� ���� ������ 109���� �۰ų� ���� �����̴�.

���
ù° �ٿ� �� �迭�� ��ģ �� ������ ����� ����Ѵ�.
*/

// NULL ������
// stable sort (�� ���� �������� ������ ��, �� ������ ������ �����ϸ鼭 ������ �������� ����)
#include <bits/stdc++.h>
using namespace std;

int N, M, A[1000005], B[1000005], ans[2000010], A_idx = 0, B_idx = 0;

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)	cin >> A[i];
	for (int i = 0; i < M; i++)	cin >> B[i];

	for (int i = 0; i < N + M; i++) {
		if (A_idx == N) ans[i] = B[B_idx++];
		else if (B_idx == M) ans[i] = A[A_idx++];
		else if (A[A_idx] < B[B_idx]) ans[i] = A[A_idx++];
		else ans[i] = B[B_idx++];
	}
	for (int i = 0; i < N + M; i++) cout << ans[i] << " ";
}
