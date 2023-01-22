//BOJ 13549 숨바꼭질3
#include <bits/stdc++.h>
using namespace std;
int dx[3] = {0, -1, 1};
int bfs(int soobin, int sister)
{
    vector<int> v(200002, -1);
    int maxIdx = 100000;

    v[soobin] = 0;
    queue<int> q;
    q.push(soobin);

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();

        if(cur == sister) return v[cur];

        for(int i = 0; i<3; i++)
        {
            int nx;
            int time;

            if(i == 0) 
            {
                nx = cur * 2;
                time = 0;
            }
            else
            {
                nx = cur + dx[i];
                time = 1;
            } 

            if(nx < 0 || nx > maxIdx) continue;
            if(v[nx] != -1) continue;

            if(nx == sister) return v[cur] + time;
            v[nx] = v[cur] + time;

            q.push(nx);
        }

        
    }
    

}
int main(void)
{
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);

    int posSoobin, posSister;
    cin >> posSoobin >> posSister;

    cout << bfs(posSoobin, posSister);

}