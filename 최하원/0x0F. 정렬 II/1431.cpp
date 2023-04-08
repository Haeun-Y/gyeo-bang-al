/*
����
�ټ��̴� ��Ÿ�� �ø��� ��ȣ ������� �����ϰ��� �Ѵ�. ��� �ø��� ��ȣ�� ���ĺ� �빮�� (A-Z)�� ���� (0-9)�� �̷���� �ִ�.
�ø����ȣ A�� �ø����ȣ B�� �տ� ���� ���� ������ ����.

A�� B�� ���̰� �ٸ���, ª�� ���� ���� �´�.
���� ���� ���̰� ���ٸ�, A�� ��� �ڸ����� �հ� B�� ��� �ڸ����� ���� ���ؼ� ���� ���� ������ ���� �����´�. (������ �͸� ���Ѵ�)
���� 1,2�� �� �������ε� ���� �� ������, ���������� ���Ѵ�. ���ڰ� ���ĺ����� ���������� �۴�.
�ø����� �־����� ��, �����ؼ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ��Ÿ�� ���� N�� �־�����. N�� 50���� �۰ų� ����. ��° �ٺ��� N���� �ٿ� �ø��� ��ȣ�� �ϳ��� �־�����. 
�ø��� ��ȣ�� ���̴� �ִ� 50�̰�, ���ĺ� �빮�� �Ǵ� ���ڷθ� �̷���� �ִ�. �ø��� ��ȣ�� �ߺ����� �ʴ´�.

���
ù° �ٺ��� ���ʴ�� N���� �ٿ� ���ٿ� �ϳ��� �ø��� ��ȣ�� ������ ����� ����Ѵ�.
*/

#include <bits/stdc++.h>
using namespace std;

int N;
string s;
vector<string> S;

bool func(string& a, string& b) { // �� ������ �̿�
	int lena = a.size(); int lenb = b.size();
	if (lena != lenb) return lena < lenb;

	int suma = 0, sumb = 0;
	for (int i = 0; i < lena; i++)
		if (isdigit(a[i])) suma += (a[i] - '0');
	for (int i = 0; i < lenb; i++)
		if (isdigit(b[i])) sumb += (b[i] - '0');
	if (suma != sumb) return suma < sumb;

	return a < b; // ���� ��
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s;
		S.push_back(s);
	}

	sort(S.begin(), S.end(), func);

	for (string ss : S) cout << ss << '\n';
}