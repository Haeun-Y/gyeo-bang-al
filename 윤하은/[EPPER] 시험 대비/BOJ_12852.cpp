#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n;
    cin >> n;

    vector<pair<int, int>> operations(n+1);

    operations[1].first = 0;

    for(int i = 2; i<=n; i++)
    {
        int cnt = operations[i-1].first;
        int interResult = i-1;

        if(i%2 == 0 && cnt > operations[i/2].first)
        {
            cnt = operations[i/2].first;
            interResult = i/2;
        }

        if(i%3 == 0 && cnt > operations[i/3].first)
        {
            cnt = operations[i/3].first;
            interResult = i/3;
        }

        operations[i].first = cnt + 1;
        operations[i].second = interResult;

    }

    cout << operations[n].first << "\n";

    for(int i = n; i > 0; i = operations[i].second)
        cout << i << " ";

}