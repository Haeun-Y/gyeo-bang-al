// https://www.acmicpc.net/problem/17478

#include<bits/stdc++.h>
using namespace std;
int N;
void func(int n) {
	if (n == 0) {
		for (int i = 0; i < N; i++) cout << "____";	cout << "\"����Լ��� ������?\"\n";
		for (int i = 0; i < N; i++) cout << "____";	cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";
		for (int i = 0; i < N; i++) cout << "____";	cout << "��� �亯�Ͽ���.\n";
		return;
	}
	for (int i = 0; i < N - n; i++) cout << "____";	cout << "\"����Լ��� ������?\"\n";
	for (int i = 0; i < N - n; i++) cout << "____";	cout << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n";
	for (int i = 0; i < N - n; i++) cout << "____";	cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";
	for (int i = 0; i < N - n; i++) cout << "____";	cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";
	func(n - 1);
	for (int i = 0; i < N - n; i++) cout << "____";	cout << "��� �亯�Ͽ���.\n";
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
	func(N);
}