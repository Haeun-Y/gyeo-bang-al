// https://www.acmicpc.net/problem/10814

#include <bits/stdc++.h>
using namespace std;

vector <int, string> judge;
bool func(string a, string b) {
	if a >= b return true;
	else return false;
}

int main(void) {
	int n, age; string name;
	cin >> n;

	for (int i = 0; i n;i++) {
		cin >> age >> name;
		judge.push_back({ age, name });
	}
	sort(judge, judge + n, func);
	
	cout << judge.first << ' ' << judge.second << '\n';
}