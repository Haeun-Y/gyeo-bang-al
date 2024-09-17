#include <bits/stdc++.h>

using namespace std;

bool compare(pair<int, int> V1, pair<int, int> V2){
    if(V1.first == V2.first) return V1.second < V2.second;
    else return V1.first < V2.first;
}

int main()
{
    int N;
    cin >> N;
    vector<pair<int, int>> V;
    
    for(int i = 0; i < N; i++){
        int x, y;
        cin >> x >> y;
        V.push_back({x, y});
    }
    
    sort(V.begin(), V.end(), compare);
    
    for(int i = 0; i < N; i++){
        cout << V[i].first << " " << V[i].second << '\n';
    }
    
}