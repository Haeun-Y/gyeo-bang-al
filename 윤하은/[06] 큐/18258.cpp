//BOJ 18258 큐2
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

        bool isEmpty = q.empty();

        if(command == "push")
        {
            int num;
            cin >> num;
            q.push(num);

        }
        else if(command == "pop")
        {
            if(isEmpty) cout << -1;
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
            cout << isEmpty << "\n";
        }
        else if(command == "front")
        {
            if(isEmpty) cout << -1;
            else
                cout << q.front();
            cout << "\n";

        }
        else //command == "back"
        {
            if(isEmpty) cout << -1;
            else
                cout << q.back();
            cout << "\n";

        }
    }
}