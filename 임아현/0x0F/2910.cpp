#include <bits/stdc++.h>

using namespace std;

bool comp(tuple<long long, int, int> v1, tuple<long long, int, int> v2){
    if(get<1>(v1) == get<1>(v2)) return get<2>(v1) < get<2>(v2); //stable할 수 있게 idx 비교
    return get<1>(v1) > get<1>(v2);
}

int main()
{
    int N;
    long long C;
    vector<tuple<long long, int, int>> V;
    
    cin >> N >> C;
    int idx = 0;
    for(int i = 0; i < N; i++){
        long long temp;
        bool check = false;
        cin >> temp;
       for(int j = 0; j < V.size(); j++){
           if(get<0>(V[j]) == temp){
               (get<1>(V[j]))++;
               check = 1;
               break;
           }
       }
       if(!check){
           V.push_back({temp, 1, idx}); idx++;
       }
    }
    
    sort(V.begin(), V.end(), comp); //stable 하지 않을 수
    
    for(int i = 0; i < V.size(); i++){
        long long num = get<0>(V[i]);
        int cnt = get<1>(V[i]);
        while(cnt--){
            cout << num << ' ';
        }
    }
}