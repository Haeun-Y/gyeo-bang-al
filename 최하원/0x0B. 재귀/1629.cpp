/*
����
�ڿ��� A�� B�� ���� ���� �˰� �ʹ�. �� ���Ϸ��� ���� �ſ� Ŀ�� �� �����Ƿ� �̸� C�� ���� �������� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
�Է�
ù° �ٿ� A, B, C�� �� ĭ�� ���̿� �ΰ� ������� �־�����. A, B, C�� ��� 2,147,483,647 ������ �ڿ����̴�.
���
ù° �ٿ� A�� B�� ���� ���� C�� ���� �������� ����Ѵ�.
*/
# include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll func(ll a, ll b, ll c) {

	if (b == 1) return a % c;
	ll aa = func(a, b / 2, c);
	aa = aa * aa % c;
	if (b % 2 == 1) return a * aa % c;
	else return aa;
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll a, b, c;
	cin >> a >> b >> c;
	cout << func(a, b, c);
}