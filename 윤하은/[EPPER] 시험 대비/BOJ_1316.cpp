#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n;
    cin >> n;

    int answer = 0;

    while(n--)
    {
        string str;
        cin >> str;

        vector<int> alphabets(26, -1);
        bool result = true;

        for(int i = 0; i<str.length(); i++)
        {
            int chIdx = str[i] - 'a';

            //기존에 등장한적 없는 문자 또는 문자끼리 연속해서 등장
            if(alphabets[chIdx] == -1 || alphabets[chIdx]+1 == i)
                alphabets[chIdx] = i;
            
            else
            {
                result = false;
                break;
            }

        }

        if(result) answer++;

    }

    cout << answer;
}