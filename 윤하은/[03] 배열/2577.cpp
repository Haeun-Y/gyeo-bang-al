#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c;
    cin >> a >> b >> c;

    string result = to_string(a * b * c);
    vector<int> num(10);

    for(char ch : result)
        num[ch-'0']++;
    
    for(int i = 0; i<num.size(); i++)
        cout << num[i] << "\n";
}