#include <bits/stdc++.h>
using namespace std;
int solution(int n, int m)
{
	int noteBookNum = n;
	int day = 1;
	
	while(noteBookNum-- > 0) 
	{
		if(day%m == 0) noteBookNum++;
		if(noteBookNum == 0) return day;
		
		day++;
		
	}
	
}
int main() {
	
	int n, m;
	cin >> n >> m;
	
	cout << solution(n, m);
	
	return 0;
}
