#include <bits/stdc++.h>

using namespace std;

int N;
long long MAX = 0;
vector <pair<int, int>> V;
vector <long long> VS;

int main()
{
    cin >> N;
    
    V.push_back({0, 0});
    VS.push_back(0);
    for(int i = 1; i <= N; i++){
        int day, money;
        cin >> day >> money;
        V.push_back({day, money});
        VS.push_back(0);
    }
    
    V.push_back({0, 0});
    VS.push_back(0);
    
    for(int i = N; i >= 1; i--){
        //퇴사일 넘기지 않는 경우
        if(i + V[i].first <= N + 1) VS[i]= max(VS[i + V[i].first] + V[i].second, VS[i + 1]);
        //퇴사일 넘기는 경우 전의 최대값 그대로
        else VS[i] = VS[i + 1];
    }
    
    for(int i = 1; i <= N + 1; i++){
        MAX = max(MAX, VS[i]);
    }
    
    cout << MAX;
}