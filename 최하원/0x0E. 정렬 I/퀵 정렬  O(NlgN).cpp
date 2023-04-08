// 메모리 대신, "양쪽 끝에 포인터 2개 쓰기" : In-place sort
/* 재귀 포인트
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

// index 유의
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

// 다소 차이는 있겠으나 pivot 이 정가운데 있으면 대략 O(nlgn)
// 최악일 경우 O(N^2) 이나 보통 merge sort 보다 빠름
// quick_sort 는 stable_sort 아님