#include <iostream>
using namespace std;

int main(void)
{
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);

    int tc;
    cin >> tc;

    pair<int, int> fibo[41];

    fibo[0].first = 1;
    fibo[1].second = 1;

    for(int i =2; i<= 40; i++)
    {
        fibo[i].first = fibo[i-1].first + fibo[i-2].first;
        fibo[i].second = fibo[i-1].second + fibo[i-2].second;

    }

    while(tc--)
    {
        int n;
        cin >> n;

        cout << fibo[n].first << " " << fibo[n].second;

    }
}