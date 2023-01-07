#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    vector<int> alphabets(26);

    for(int i = 0; i< s.length(); i++)
        alphabets[s[i]-'a']++;
    
    for(int i = 0; i< alphabets.size(); i++)
        cout << alphabets[i] << " ";
}