#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    vector<pair<int, int>> V;
    
    for(int i = 0; i < N; i++){
        int s, ed;
        cin >> s >> ed;
        V.push_back({s, 1}); //시작 
        V.push_back({ed, -1}); //끝
    }
    
    sort(V.begin(), V.end()); //정렬하면 섞임 1, -1로 시작 끝 구분
    
    int cur = V[0].first; //현재 시간 (시작은 맨 첫번째째)
    int sum = 0; //현 시간 강의실 개수 
    int idx = 0; //idx
    int num = 0; //강의실 개수 
    
    while(true){
        while(idx < 2 * N && V[idx].first == cur){
            sum += V[idx].second;
            idx++;
        }
        num = max(sum, num);
        if(idx == 2 * N) break;
        cur = V[idx].first;
    }
    cout << num;
}