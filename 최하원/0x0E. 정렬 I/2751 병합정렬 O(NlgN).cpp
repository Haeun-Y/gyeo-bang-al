/*����
N���� ���� �־����� ��, �̸� ������������ �����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ���� ���� N(1 �� N �� 1,000,000)�� �־�����. ��° �ٺ��� N���� �ٿ��� ���� �־�����.
�� ���� ������ 1,000,000���� �۰ų� ���� �����̴�. ���� �ߺ����� �ʴ´�.

���
ù° �ٺ��� N���� �ٿ� ������������ ������ ����� �� �ٿ� �ϳ��� ����Ѵ�.
*/

#include <bits/stdc++.h>
using namespace std;

int n;
int arr[1000001];
int tmp[1000001]; // merge �Լ����� ����Ʈ 2���� ��ģ ����� �ӽ÷� �����ϰ� ���� ����

// mid = (st+en)/2��� �� �� arr[st:mid], arr[mid:en]�� �̹� ������ �Ǿ��ִ� ������ �� arr[st:mid]�� arr[mid:en]�� ��ģ��.
void merge(int st, int en) {
	int mid = (st + en) / 2;
	int lidx = st;
	int ridx = mid;
	for (int i = st; i < en; i++) {
		if (lidx == mid) tmp[i] = arr[ridx++];
		else if (ridx == en) tmp[i] = arr[lidx++];
		else tmp[i] = arr[lidx] <= arr[ridx] ? arr[lidx++] : arr[ridx++];
	}
	for (int i = st; i < en; i++) arr[i] = tmp[i];
}

// arr[st:en]�� �����Ѵ�.
void merge_sort(int st, int en) {
	if (st + 1 == en) return; // ���� 1�� ���
	int mid = (st + en) / 2;

	merge_sort(st, mid); // arr[st:mid]�� �����Ѵ�.
	merge_sort(mid, en); // arr[mid:en]�� �����Ѵ�.
	merge(st, en); // arr[st:mid]�� arr[mid:en]�� ��ģ��.
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	merge_sort(0, n);
	for (int i = 0; i < n; i++) cout << arr[i] << "\n";
}