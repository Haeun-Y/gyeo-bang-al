vector<int> divisor(int n) {
	vector<int> div;

	for (int i = 1; i * i <= n; i++) if (n % i == 0) div.push_back(i);

	for (int j = div.size()-1; j > 0; j--) {
		if (div[j] * div[j] == n) continue;
		div.push_back(n / div[j]);
	}
	return div;
}