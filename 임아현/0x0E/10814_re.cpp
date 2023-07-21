#include <bits/stdc++.h>

using namespace std;

bool compare(tuple<int, int, string> T1, tuple<int, int, string> T2){
    if(get<0>(T1) == get<0>(T2)) return get<1>(T1) < get<1>(T2);
    return get<0>(T1) < get<0>(T2);
}

int main()
{
    int N;
    vector<tuple<int, int, string>> V;
    cin >> N;
    for(int i = 0; i < N; i++){
        int age;
        string name;
        cin >> age >> name;
        V.push_back({age, i, name});
    }
    sort(V.begin(), V.end(), compare);
    
    for(int i = 0; i < N; i++){
        cout << get<0>(V[i]) << " " << get<2>(V[i]) << '\n';
    }
}