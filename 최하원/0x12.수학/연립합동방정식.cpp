// 6명씩 조를 짯을 때 3명이 남았다.
// 5명씩 조를 짰을 때 2명이 남았다.
// 학생은 30명 미만이다.
int chk(int n) { // O(n)
	for (int i = 0; i < 30; i++)
		if (i % 6 == 3 && i % 5 == 2) return i;
	return -1;
}

int chk2(int n) { // 시간복잡도 줄이기
	int ans = 3;
	for (int i = 0; i < n; i += 6)
		if (ans % 5 == 2) return ans;
	return -1;
	}