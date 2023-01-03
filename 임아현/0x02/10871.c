#include <stdio.h> //정수 n개로 이루어진 수열 a에서 x보다 작은 수를 모두 출력하시오
int main() {
	int n, x, input;
	int a[1000];

	scanf("%d %d", &n, &x);
	for (int i = 0; i < n; i++) {
		scanf("%d", &input);
		a[i] = input; 
		if (x > a[i])
			printf("%d ", a[i]);
	}
}