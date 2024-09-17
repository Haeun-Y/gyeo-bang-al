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
        int a, b;
        cin >> a >> b;
        V.push_back({a, b});
    }
    
    sort(V.begin(), V.end());
    
    int start = V[0].first;
    int end = V[0].second;
    int sum = 0, check = 0;
    for(int i = 1; i < N; i++){
        if(end < V[i].first){
            check = 1;
            sum += end - start;
            start = V[i].first;
            end = V[i].second;
            check = 0;
        }
        if(end < V[i].second){
            end = V[i].second;
        }
    }
    if(!check) sum += end - start;
    cout << sum;
    
}