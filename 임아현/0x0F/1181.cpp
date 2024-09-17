#include <bits/stdc++.h>

using namespace std;

bool comp(pair<string, int> v1, pair<string, int> v2){
    if(v1.second != v2.second) return v1.second < v2.second;
    else return v1.first < v2.first;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<pair<string, int>> V;
    
    for(int i = 0; i < N; i++){
        string str;
        cin >> str;
        V.push_back({str, str.length()});
    }
    
    sort(V.begin(), V.end(), comp);
    V.erase(unique(V.begin(), V.end()), V.end());
    
    for(int i = 0; i < V.size(); i++){
        cout << V[i].first << '\n';
    }
}