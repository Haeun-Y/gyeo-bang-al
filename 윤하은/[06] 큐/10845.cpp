//BOJ 10845 큐
#include <bits/stdc++.h>
using namespace std; 

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    queue<int> q;
    int commandNum;
    cin >> commandNum;

    for(int i = 0; i<commandNum; i++)
    {
        string command;
        cin >> command;

        if(command == "push")
        {
            int num;
            cin >> num;
            q.push(num);

        }
        else if(command == "pop")
        {
            if(q.empty()) cout << -1;
            else 
            {
                cout << q.front();
                q.pop();
            }
            cout << "\n";

        }
        else if(command == "size")
        {
            cout << q.size() << "\n";
        }
        else if(command == "empty")
        {
            cout << q.empty() << "\n";
        }
        else if(command == "front")
        {
            if(q.empty()) cout << -1;
            else
                cout << q.front();
            cout << "\n";

        }
        else //command == "back"
        {
            if(q.empty()) cout << -1;
            else
                cout << q.back();
            cout << "\n";

        }
    }
}