#include <bits/stdc++.h>
using namespace std;

int freq[10];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b, c, s;
    cin >> a >> b >> c;
    s = a * b * c;

    while (s > 0) {
        freq[s % 10]++;
        s /= 10;
    }
    for (int i = 0; i < 10; i++) cout << freq[i] << '\n';
}