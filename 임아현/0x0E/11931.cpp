#include <bits/stdc++.h>

using namespace std;

bool compare(int n1, int n2){
    return n1 > n2;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    vector<int> V;
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        int num;
        cin >> num;
        V.push_back(num);
    }
    sort(V.begin(), V.end(), compare);
    
    for(int i = 0; i < N; i++){
        cout << V[i] << '\n';
    }
    
}