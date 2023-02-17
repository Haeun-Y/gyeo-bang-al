#include <bits/stdc++.h>

using namespace std;

bool comp(tuple<string, int, int> v1, tuple<string, int, int> v2){
    if(get<1>(v1) == get<1>(v2)) return get<2>(v1) < get<2>(v2);
    return get<1>(v1) < get<1>(v2);
}

int main()
{
    vector<tuple<string, int, int>> V; //이름 나이 가입 순서
    
    int N; 
    cin >> N;
    
    for(int i = 0; i < N; i++){
        int age;
        string name;
        cin >> age >> name;
        V.push_back({name, age, i}); 
    }
    
    sort(V.begin(), V.end(), comp);
    
    for(int i = 0; i < V.size(); i++){
        cout << get<1>(V[i]) << ' ' << get<0>(V[i]) << '\n';
    }
}