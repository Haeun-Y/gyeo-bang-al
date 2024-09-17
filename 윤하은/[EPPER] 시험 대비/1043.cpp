#include <bits/stdc++.h>
#include <iostream>
using namespace std;
const int MAX = 51;
bool known[MAX];
int parent[MAX];
int find(int node)
{
    if(parent[node] == -1) return node;
    return find(parent[node]);
}
void merge(int x, int y)
{
    x = find(x);
    y = find(y);
    
    if(x == y) return;
    
    if(known[x]) parent[y] = x;
    else if(known[y]) parent[x] = y;
    
    else parent[x] = y;
    
}
int countParty(int m, vector<vector<int>> party) {
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		int r = find(party[i][0]);
		if (!known[r]) { 
			cnt++;
		}
	}
	return cnt;
}
int solution(int n, int m, vector<int>& truth, vector<vector<int>>party)
{
    //정점들의 부모를 -1로 초기화
    for(int i = 1; i <= n; i++)
        parent[i] = -1;
    
    //진실을 아는 사람 표시
    for(int t : truth)
        known[t] = true;
    
    
    //각 파티마다 정점들끼리 연결
    for(int i = 0; i<m; i++)
    {
        int fp = party[i][0];
        for(int p : party[i])
            merge(fp, p);
        
    }
    
    return countParty(m, party);
    
}
int main()
{
    int n, m, init;
	//입력
	cin >> n >> m >> init;
	vector<int> truth;
	vector<vector<int>> party(m);

	while (init--) { 
		int p; cin >> p;
		truth.push_back(p);
	}
	for (int i = 0; i < m; i++) {
		int sz; cin >> sz;
		while (sz--) {
			int x; cin >> x;
			party[i].push_back(x);
		}
	}
	//연산 & 출력
	cout << solution(n, m, truth, party);

	return 0;
}