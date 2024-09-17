//종료 시간이 짧은 순으로 정렬하기
//첫 번째 자리부터 쭉 앉히다 더 이상 앉힐 수 없으면 두 번째에 앉히기 
//첫 번쨰 자리, 두 번째 자리 둘 다 된다면 더 시간이 차이가 적은 곳에 

#include <bits/stdc++.h> 
using namespace std;
int s[1002];
int e[1002];
vector <pair<int, int>> V;
int N;

bool compare(pair<int, int> V1, pair<int, int> V2){
	if(V1.second == V2.second) return V1.first > V2.first;
	return V1.second < V2.second;
}

int solution(){
	int cnt = 0;
	
	auto cur1 = make_pair(-1, -1); //1번 자리 
	auto cur2 = make_pair(-1, -1);  //2번 자리
	
	for(int i = 0; i < N; i++){
		if(V[i].first >= cur1.second || V[i].first >= cur2.second){
			if(V[i].first >= cur1.second && V[i].first >= cur2.second){
				if(V[i].first - cur1.second < V[i].first - cur2.second){
					cnt++;
					cur1 = V[i];
				}
				else{
					cnt++;
					cur2 = V[i];
				}
			}
			else if(V[i].first < cur2.second){
				cnt++;
				cur1 = V[i];
			}
			else{
				cnt++;
				cur2 = V[i];
			}
		}
	}
	return cnt;
}

int main() {

	cin >> N;
	for(int i = 0; i < N; i++) cin >> s[i];
	for(int i = 0; i < N; i++) cin >> e[i];
	for(int i = 0; i < N; i++) V.push_back({s[i], e[i]});
	
	sort(V.begin(), V.end(), compare);
	cout << solution();
}