// // https://www.acmicpc.net/problem/1759

#include<bits/stdc++.h>
using namespace std;
int L, C; char alpha[16]; bool isused[16];

void func(int n, int idx, string s) {
	if (n == L) {
		int consonant = 0, vowel = 0;
		for (int i = 0; i < L; i++) {
			if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
				vowel++;
			}
			else consonant++;
		}
		if (consonant > 1 && vowel > 0) {
			cout << s << '\n';
			return;
		}
		return;
	}
	for (int i = idx; i < C; i++) {
		if (!isused[i]) {
			isused[i] = 1;
			func(n + 1, i + 1, s + alpha[i]);
			isused[i] = 0;
		}
	}
}
int main(void) {

	cin >> L >> C;
	for (int i = 0; i < C; i++) cin >> alpha[i];
	sort(alpha, alpha + C);
	func(0, 0, "");

}