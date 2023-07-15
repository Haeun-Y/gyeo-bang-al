/*
����
�־��� �� N�� �߿��� �Ҽ��� �� ������ ã�Ƽ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
�Է�
ù �ٿ� ���� ���� N�� �־�����. N�� 100�����̴�. �������� N���� ���� �־����µ� ���� 1,000 ������ �ڿ����̴�.
���
�־��� ���� �� �Ҽ��� ������ ����Ѵ�.
*/
int isprime(int n) {
	if (n ==1) return 0;
	for (int i = 2; i * i <= n; i++) 
		if (n % i == 0) return 0;
	return 1;
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, ans = 0;

	cin >> N;
	while (N--) {
		int tmp;
		cin >> tmp;
		ans += isprime(tmp);
	}
	cout << ans << "\n";
}