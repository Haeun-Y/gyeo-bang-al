//BOJ 10828 스택
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int commandNum;
    cin >> commandNum;

    stack<int> s;

    for(int i = 0; i<commandNum; i++)
    {
        string command;
        cin >> command;

        if(command == "push")
        {
            int x;
            cin >> x;
            s.push(x);
        }
        else if(command == "pop")
        {
            if(s.empty())
                cout << "-1\n";
            else
            {
                cout << s.top() << "\n";
                s.pop();
            }
        }
        else if(command == "size")
        {
            cout << s.size() << "\n";

        }
        else if(command == "empty")
        {
            cout << s.empty() << "\n";
        }
        else //command == "top"
        {
            if(s.empty())
                cout << "-1\n";
            else cout << s.top() << "\n";
        }
    }
}