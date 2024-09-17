#include <bits/stdc++.h>

using namespace std;
int N, M;
vector<long long> V;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    
    for(int i = 0; i < N; i++){
        long long num;
        cin >> num;
        V.push_back(num);
    }
    
    while(M--){
        sort(V.begin(), V.end());
        V[0] = V[0] + V[1];
        V[1] = V[0];
    }
    
    long long sum = 0;
    for(int i = 0; i < V.size(); i++){
        sum += V[i];
    }
    
    cout << sum;
   
};