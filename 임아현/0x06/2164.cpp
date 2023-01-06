#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<int> Q;
    
    int N;
    cin >> N;
    
    for(int i = 1; i <= N; i++){
        Q.push(i);
    }
    
    while(Q.size() > 1){
        Q.pop();
        if(Q.size() == 1) break;
            
        else{
            int f = Q.front();
            Q.pop();
            Q.push(f);
        }
    }
    cout << Q.front();
}