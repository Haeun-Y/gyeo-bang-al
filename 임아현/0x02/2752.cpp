#include <bits/stdc++.h>
using namespace std; //std name space std:: 생략 가능
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	int a, b, c;
	cin >> a >> b >> c;
	
	int first = min({a, b, c});
	int last = max({a, b, c});
	int second = (a + b + c) - (first + last);
	
	cout << first << ' ' << second << ' ' << last;
	
}