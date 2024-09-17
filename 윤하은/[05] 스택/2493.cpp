//BOJ 2493 탑
#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    stack<pair<int, int>> s;

    for(int i = 0; i<n; i++)
    {
        int height;
        cin >> height;
        while(!s.empty() && s.top().first < height)
            s.pop();
        
        if(s.empty()) cout << "0 ";
        else // !s.empty()
        {
            if(s.top().first >= height)
                cout << s.top().second << " ";
        }
        s.push({height, i+1});
    }
}