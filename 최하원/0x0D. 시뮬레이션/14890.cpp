/*
문제
크기가 N×N인 지도가 있다. 지도의 각 칸에는 그 곳의 높이가 적혀져 있다.
오늘은 이 지도에서 지나갈 수 있는 길이 몇 개 있는지 알아보려고 한다. 길이란 한 행 또는 한 열 전부를 나타내며, 한쪽 끝에서 다른쪽 끝까지 지나가는 것이다.
다음과 같은 N=6인 경우 지도를 살펴보자.

이때, 길은 총 2N개가 있으며, 아래와 같다.
길을 지나갈 수 있으려면 길에 속한 모든 칸의 높이가 모두 같아야 한다. 또는, 경사로를 놓아서 지나갈 수 있는 길을 만들 수 있다. 경사로는 높이가 항상 1이며, 길이는 L이다. 또, 개수는 매우 많아 부족할 일이 없다. 경사로는 낮은 칸과 높은 칸을 연결하며, 아래와 같은 조건을 만족해야한다.]
지도가 주어졌을 때, 지나갈 수 있는 길의 개수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N (2 ≤ N ≤ 100)과 L (1 ≤ L ≤ N)이 주어진다. 둘째 줄부터 N개의 줄에 지도가 주어진다. 각 칸의 높이는 10보다 작거나 같은 자연수이다.

출력
첫째 줄에 지나갈 수 있는 길의 개수를 출력한다.
*/
#include<stdio/bits>
using namespace std;

int n, l;
int board[100][100];

bool canGo(vector<int>& v)
{
	vector<bool> visited(n, false);
	for (int i = 1; i < n; ++i)
	{
		if (v[i - 1] != v[i]) {
			int diff = abs(v[i] - v[i - 1]);

			// 차이가 1이상 날때
			if (diff != 1)
				return false;

			// 더 높을때
			if (v[i - 1] < v[i]) {
				for (int j = 1; j <= l; ++j) {

					//경사로 범위 벗어날 때
					if (i - j < 0)
						return false;

					// 평평하지 않을때
					if (v[i - 1] != v[i - j])
						return false;

					// 놓은 곳에 또 경사로를 놓을 때
					if (visited[i - j]) {
						return false;
					}

					//경사로를 놓은다.
					visited[i - j] = true;
				}
			}
			// 더 낮을때
			else {
				for (int j = 0; j < l; ++j) {
					if (i + j >= n)
						return false;

					if (v[i] != v[i + j])
						return false;

					if (visited[i + j])
						return false;

					visited[i + j] = true;
				}
			}
		}

	}
	return true;
}
int main()
{
	cin >> n >> l;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> board[i][j];


	int ret = 0;
	//행부터 계산
	for (int i = 0; i < n; ++i)
	{
		vector<int> row;
		for (int j = 0; j < n; ++j)
		{
			row.push_back(board[i][j]);
		}

		if (canGo(row)) {
			ret++;
		}
	}

	for (int j = 0; j < n; ++j)
	{
		vector<int> col;
		for (int i = 0; i < n; ++i) {
			col.push_back(board[i][j]);
		}
		if (canGo(col)) {
			ret++;
		}
	}
	cout << ret << "\n";
	return 0;
}