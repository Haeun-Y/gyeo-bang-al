//240222
//BOJ 15988 1, 2, 3 더하기 3
//SILVER 2
#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<long long> v(1000000+1, 0);

    v[1] = 1;
    v[2] = 2;
    v[3] = 4;

    for(int i = 4; i<= 1000000; i++)
        v[i] = (v[i-3] + v[i-2] + v[i-1])%1000000009;

    int tc;
    cin >> tc;

    while(tc--)
    {
        int num;
        cin >> num;
        cout << v[num] << "\n";
    }

}