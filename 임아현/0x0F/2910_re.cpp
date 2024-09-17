#include <bits/stdc++.h>

using namespace std;

bool compare(tuple<int, int, int> V1, tuple<int, int, int>V2){
   if(get<1>(V1) == get<1>(V2)) return get<2>(V1) < get<2>(V2);
   return get<1>(V1) > get<1>(V2);
}

int main()
{
    int N, C;
    cin >> N >> C;
    vector<tuple<int, int, int>> V ; // number, freq, order
    
    int order = 0;
    for(int i = 0; i < N; i++){
        int num;
        bool check = 0;
        cin >> num;
        for(int i = 0; i < V.size(); i++){
            if(get<0>(V[i]) == num){
                get<1>(V[i])++;
                check = 1;
            }
        }
        if(!check){
            V.push_back({num, 1, order}); 
            order++;
        }
    }
    
    //순서대로 정렬 보장 X idx 넣어줘야 
    sort(V.begin(), V.end(), compare);
    
    for(int i = 0; i < V.size(); i++){
        while(get<1>(V[i])--){
            cout <<get<0>(V[i]) << " ";
        }
    }
}