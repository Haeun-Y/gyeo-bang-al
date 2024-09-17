#include <bits/stdc++.h>
using namespace std;
int solution(int x, int y, int n) {
    vector<int> v(1000000, 0);
    queue<int> q;
    vector<bool> isVisited(1000000, 0);
    
    q.push(x);
    v[x] = 0;
    isVisited[x] = true;
    
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        
        for(int i = 0; i<3; i++)
        {
            int nx;
            if(i == 0)
                nx = cur + n;
            else if(i == 1)
                nx = cur * 2;
            else nx = cur * 3;
            
            if(nx < 1 || nx > 1000000) continue;
            if(isVisited[nx]) continue;
            v[nx] = v[cur] + 1;
            q.push(nx);
            isVisited[nx] = true;
            if(nx == y) return v[nx];
        }
    }
    
    return -1;
}
