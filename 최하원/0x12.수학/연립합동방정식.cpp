// 6�� ���� ­�� �� 3���� ���Ҵ�.
// 5�� ���� ®�� �� 2���� ���Ҵ�.
// �л��� 30�� �̸��̴�.
int chk(int n) { // O(n)
	for (int i = 0; i < 30; i++)
		if (i % 6 == 3 && i % 5 == 2) return i;
	return -1;
}

int chk2(int n) { // �ð����⵵ ���̱�
	int ans = 3;
	for (int i = 0; i < n; i += 6)
		if (ans % 5 == 2) return ans;
	return -1;
	}