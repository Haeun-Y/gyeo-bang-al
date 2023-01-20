#include<bits/stdc++.h>
using namespace std;
// 규칙성을 잘 파악하고(여기서 애먹음) & 재귀로 구현
// 바로 출력을 시도했으나 복잡해서 행렬에 저장 후 한꺼번에 출력 예정
const int MAX = 3072;// n = 3X2^k (k = 0,1,2 ... 10) 최대 3072, int 이용 
char m[MAX][MAX * 2]; // 예제에서 행 24, 열 48임을 이용하여 설정

void star(int row, int col) { // star: * 저장 함수, row, col 은 꼭짓점 별의 위치

	// 첫 번째 줄										*
	m[row][col] = '*';
	// 두 번째 줄									   * * 	
	m[row + 1][col - 1] = m[row + 1][col + 1] = '*';
	// 세 번째 줄									  *****
	for (int i = col - 2; i <= col + 2; i++)
		m[row + 2][i] = '*';
}

void func(int n, int row, int col) { // func : star 함수 재귀적으로 실행하는 함수, 한 번 실행될 때 마다 6줄 삼각형 하나 생성
	if (n == 3) { // base condition
		star(row, col);
		return;
	}
	int mid = n / 2;

	func(mid, row, col); // 위 중앙 삼각형
	func(mid, row + mid, col - mid); // 아래 왼쪽 삼각형
	func(mid, row + mid, col + mid); // 아래 오른쪽 삼각형 


}
int main(void) { // main : 사용자 입력, 결과 출력
	ios::sync_with_stdio(0);
	cin.tie(0);

	// 사용자 입력
	int n;
	cin >> n;
	// func 함수 실행
	// matrix 크기[n][2n], 맨 위 꼭지점 별의 위치 (0, n-1)
	func(n, 0, n - 1);

	// 결과 출력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n * 2; j++) {
			if (m[i][j] == '*') cout << '*';
			else cout << ' ';
		}
		cout << "\n";
	}
}