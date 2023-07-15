// by. 유클리드 호제법

int gcd(int a, int b) {
	if (a == 0) return b;
	return gcd(b % a, a);
}

int lcm(int a, int b) {
	// return a * b / gcd(a, b);
	return a / gcd(a, b) * b; // int overflow 방지
}