//https://www.acmicpc.net/problem/1919

#include <bits/stdc++.h>
using namespace std;

int arr1[27], arr2[27];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s1, s2; int sum = 0;
	cin >> s1 >> s2;

	for (int i = 0; i < s1.size(); i++) arr1[(s1[i] - 'a')]++;
	for (int i = 0; i < s2.size(); i++) arr2[(s2[i] - 'a')]++;
	for (int i = 0; i < 26; i++) sum += abs(arr1[i] - arr2[i]);

	cout << sum;
}