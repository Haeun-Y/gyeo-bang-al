/*
����
M�̻� N������ �Ҽ��� ��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
�Է�
ù° �ٿ� �ڿ��� M�� N�� �� ĭ�� ���̿� �ΰ� �־�����. (1 �� M �� N �� 1,000,000) M�̻� N������ �Ҽ��� �ϳ� �̻� �ִ� �Է¸� �־�����.
���
�� �ٿ� �ϳ���, �����ϴ� ������� �Ҽ��� ����Ѵ�.
*/
vector<bool> state(1000005, true); // �Ҽ��� true, �Ҽ� �ƴϸ� false

void func(int n) {
	state[1] = false;
	for (int i = 2; i * i <= n; i++) { 
		if (state[i] == false) continue;
		for (int j = i + i; j <= n; j += i) // i + i ���� ����
			state[j] = false;

	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int M, N;
	cin >> M >> N;
	func(N);
	for (int i = M; i <= N; i++)
		if (state[i]) cout << i << "\n";
}