#include <bits/stdc++.h>

using namespace std;

int N;
int MAX;
int cnt = 0;
vector<pair<int, int>> V;

void func(int k){
    if(k == N){ //손에 든 계란이 가장 오른쪽 
        MAX = max(MAX, cnt);
        return;
    }
    
    if(V[k].first <= 0 ||  cnt == N - 1){ //깨졌거나, 깨지지 않은 다른 계란이 없음 
        func(k + 1); //오른쪽 계란 
        return;
    }
    
    for(int i = 0; i < N; i++){
        if(k == i || V[i].first <= 0) continue;
        V[k].first -= V[i].second;
        V[i].first -= V[k].second;
        if(V[k].first <= 0) cnt++;
        if(V[i].first <= 0) cnt++;
        func(k + 1); //오른쪽 계란 
        if(V[k].first <= 0) cnt--;
        if(V[i].first <= 0) cnt--;
        V[k].first += V[i].second;
        V[i].first += V[k].second;
        
    }
    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    
    for(int i = 0; i < N; i++){
        int S, W;
        cin >> S >> W;
        V.push_back({S, W});
    }
    
    func(0);//맨왼쪽부터
    cout << MAX;
    
}