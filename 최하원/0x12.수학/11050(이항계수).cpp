/*
����
�ڿ��� N�� ���� K�� �־����� �� ���� ��� NCK ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� N�� K�� �־�����. (1 �� N �� 10, 0 �� K �� N)

���
NCK�� ����Ѵ�.
*/
int func(int n) {
	if (n == 1 || n == 0) return 1;
	else return n * func(n - 1);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N, K, ans;
	cin >> N >> K;
	ans = func(N) / func(N - K) / func(K);
	cout << ans;
}