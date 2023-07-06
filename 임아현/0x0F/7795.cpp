#include <bits/stdc++.h>

using namespace std;

bool compare(int v1, int v2){
    return v2 < v1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T; 
    cin >> T;
    
    while(T--){
        int cnt = 0;
        int A, B;
        vector<int> V1, V2;
        cin >> A >> B;
        for(int i = 0; i < A; i++){
            int tmp;
            cin >> tmp;
            V1.push_back(tmp);
        }
        sort(V1.begin(), V1.end(), compare);
        
        for(int i = 0; i < B; i++){
            int tmp;
            cin >> tmp;
            V2.push_back(tmp);
        }
        sort(V2.begin(), V2.end());
    
        for(int i = 0; i < V1.size(); i++){
            if(V1[i] < V2[0]) break;
            for(int j = 0; j < V2.size(); j++){
                if(V1[i] > V2[j]) cnt++;
                else if(V1[i] < V2[j]) break;
            }
        }
        cout << cnt << '\n';
    }
}