//12852 1로 만들기2
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> v(n+1);
    vector<int> before(n+1);

    v[1] = 0;
    before[1] = 0;

    for(int i = 2; i<= n; i++)
    {
        v[i] = v[i-1] + 1;
        before[i] = i-1;

        if(i%3==0 && v[i/3] + 1 < v[i])
        {
            v[i] = v[i/3] + 1;
            before[i] = i/3;
        }

        if(i%2==0 && v[i/2] + 1 < v[i])
        {
            v[i] = v[i/2] + 1;
            before[i] = i/2;
        }
    }

    cout << v[n] << "\n";
    
    for(int i = n; i > 0; i = before[i])
        cout << i << " ";
}