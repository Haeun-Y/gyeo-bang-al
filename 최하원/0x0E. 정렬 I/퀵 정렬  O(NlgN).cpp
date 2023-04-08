// �޸� ���, "���� ���� ������ 2�� ����" : In-place sort
/* ��� ����Ʈ
int arr[8] = { 6,-8,1,12,8,3,7,0 }, pivot = arr[0], l = 1, r=7;
while (true) {
	while (arr[l] <= pivot && l <= r) l++;
	while (pivot < arr[r] && l <= r) r--;
	if (l > r) break;
	swap(arr[l], arr[r]);
}
swap(arr[0], arr[r]);
*/

#include <bits/stdc++.h>
using namespace std;

int n = 10;
int arr[1000001] = { 15, 25, 22, 357, 16, 23, -53, 12, 46, 3 };

// index ����
void quick_sort(int st, int en) {
	if (st + 1 >= en) return;
	int pivot = arr[st];
	int l = st + 1, r = en - 1;
	while (true) {
		while (pivot >= arr[l] && l <= r) l++;
		while (arr[l] < pivot && l <= r) r--;
		if (l > r) break;
		swap(arr[l], arr[r]);
	}
	swap(arr[st], arr[r]);

	quick_sort(st, r);
	quick_sort(r+1, en);
}
int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	quick_sort(0, n);

	for (int i = 0; i < n; i++) cout << arr[i] << " ";
}

// �ټ� ���̴� �ְ����� pivot �� ����� ������ �뷫 O(nlgn)
// �־��� ��� O(N^2) �̳� ���� merge sort ���� ����
// quick_sort �� stable_sort �ƴ�