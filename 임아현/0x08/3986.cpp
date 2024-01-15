#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int cnt = 0;
    int flag;

    int N;
    cin >> N;
    
    string word;
    while(N--){
        flag = 0;
        stack<char> S;
        cin >> word;
        for(auto c: word){
            if(word.length() % 2 != 0){
               flag = 1;
               break;
            }
            if(S.empty()) 
                S.push(c);
            else{
                if(c == S.top()) S.pop();
                else S.push(c);
            }
        }
        if(S.empty() && flag == 0){
            cnt++;
        }
    }
    cout << cnt;
}