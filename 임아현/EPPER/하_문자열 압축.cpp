#include <bits/stdc++.h>
using namespace std;

void solution(string str){
	string ans;
	
	int cnt = 0;
	char cur = str[0];
	
	str += " ";
	
	if(cur == '1') ans += '1';
	
	for(int i = 0; i < str.length(); i++){
		if(cur != str[i]){
			char temp = cnt + 64;
			ans += temp;
			cnt = 1;
			cur = str[i];
		}
		else cnt++;
	}
	cout << ans;
}

int main() {
	string str;
	cin >> str;
	solution(str);
	return 0;
}