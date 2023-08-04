#include <bits/stdc++.h>

using namespace std;

bool compare(tuple<string, int, int, int> T1, tuple<string, int, int, int> T2){
    if(get<1>(T1) == get<1>(T2)){
        if(get<2>(T1) == get<2>(T2)){
            if(get<3>(T1) == get<3>(T2)){
                return get<0>(T1) < get<0>(T2);
            }
            return get<3>(T1) > get<3>(T2);
        }
        return  get<2>(T1) < get<2>(T2);
    }
    return get<1>(T1) > get<1>(T2);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    vector<tuple<string, int, int, int>> V;
    int N;
    cin >> N;
    
    for(int i = 0; i < N; i++){
        string name;
        int kor, eng, math;
        cin >> name >> kor >> eng >> math;
        V.push_back({name, kor, eng, math});
    }
    
    sort(V.begin(), V.end(), compare);
    
    for(int i = 0; i < N; i++){
        cout << get<0>(V[i]) << '\n';
    }
}