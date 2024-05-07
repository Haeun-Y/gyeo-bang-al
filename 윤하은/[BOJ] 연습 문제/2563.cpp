//240420
//BOJ 2563 색종이
//SILVER 5
#include <bits/stdc++.h>
using namespace std;
const int whWidth = 100;
const int bWidth = 10;
int n;
vector<pair<int, int>> blackPos;
vector<vector<bool>> whitePaper;
int solution()
{
	int answer = 0;

	for(int i = 0; i<n; i++)
	{
		pair<int, int> cur = blackPos[i];
		for(int x = cur.first; x < cur.first + bWidth; x++)
			for(int y = cur.second; y<cur.second + bWidth; y++)
				whitePaper[x][y] = true;
	}

	for(int i = 0; i<whWidth; i++)
	{
		for(int j = 0; j < whWidth; j++)
		{
			if(whitePaper[i][j])
				answer++;
		}
	}
	return answer;

}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	
	whitePaper = vector<vector<bool>>(whWidth, vector<bool>(whWidth, false));
	blackPos = vector<pair<int, int>>(n);
	
	for(int i = 0; i<n; i++)
		cin >> blackPos[i].first >> blackPos[i].second;

	cout << solution();


}
