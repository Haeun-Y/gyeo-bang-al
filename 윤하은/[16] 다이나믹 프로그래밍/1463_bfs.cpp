//BOJ 1463 1로 만들기
//BFS
#include <bits/stdc++.h>
using namespace std;
int bfs(int x)
{
    vector<int> dist(x+1, -1);

    queue<int> q;
    q.push(x);
    dist[x] = 0;

    //1을 초기값으로 한 뒤 x2, x3, +1로 뻗어나가는 방식도 가능함
    
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        int operationNum = dist[cur];
        
        if(cur == 1)
            return operationNum;

        if(cur%3 == 0 && dist[cur/3] == -1)
        {
            q.push(cur/3);
            dist[cur/3] = operationNum+1;
        }
        if(cur%2 == 0 && dist[cur/2] == -1)
        {
            q.push(cur/2);
            dist[cur/2] = operationNum+1;
        }
        if(cur-1 >= 0 && dist[cur-1] == -1)
        {
            q.push(cur-1);
            dist[cur-1] = operationNum+1;
        }


    }

}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int x;
    cin >> x;

    cout << bfs(x);

}