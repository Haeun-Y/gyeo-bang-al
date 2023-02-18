//BOJ 9095 1,2,3 더하기
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> v(11);

    v[1] = 1;
    v[2] = 2; //v[1] + 1
    v[3] = 4; //v[2] + v[1] + 1

    for(int i = 4; i<11; i++)
        v[i] = v[i-1] + v[i-2] + v[i-3];

    int tc;
    cin >> tc;

    int n;

    while(tc--)
    {
        cin >> n;
        cout << v[n] << "\n";

    }

}