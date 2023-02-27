#include <bits/stdc++.h>

using namespace std;

int N, M;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    vector<pair<int, int>> V;
    
    cin >> N >> M;
    
    int sum = 0;
    V.push_back({0, 0});
    
    //미리 구간 합 저장해 두기
    for(int i = 1; i <= N; i++){
        int tmp;
        cin >> tmp;
        sum += tmp;
        V.push_back({tmp, sum});
    }
    
    //입력이 들어오면 합 차이를 구해서 구간 합 구하기
    while(M--){
        int ST, ED;
        cin >> ST >> ED;
        cout << V[ED].second - V[ST - 1].second << '\n';
    }
    
}