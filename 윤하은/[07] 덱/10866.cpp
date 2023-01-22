//BOJ 10866 덱
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);

    int commandNum;
    cin >> commandNum;

    deque<int> dq;

    for(int i= 0; i<commandNum; i++)
    {
        string command;
        cin >> command;

        bool isEmpty = dq.empty();


        if(command == "push_front")
        {
            int num;
            cin >> num;
            dq.push_front(num);
        }
        else if(command == "push_back")
        {
            int num;
            cin >> num;
            dq.push_back(num);

        }
        else if(command == "pop_front")
        {
            if(isEmpty) cout << "-1\n";
            else
            {
                cout << dq.front() << "\n";
                dq.pop_front();
            }

        }
        else if(command == "pop_back")
        {
            if(isEmpty) cout << "-1\n";
            else
            {
                cout << dq.back() << "\n";
                dq.pop_back();
            }

        }
        else if(command == "size")
        {
            cout << dq.size() << "\n";
        }
        else if(command == "empty")
        {
            cout << isEmpty << "\n";

        }
        else if(command == "front")
        {
            if(isEmpty) cout << "-1\n";
            else
                cout << dq.front() << "\n";
            
        }
        else//command == "back"
        {
            if(isEmpty) cout << "-1\n";
            else
                cout << dq.back() << "\n";
            
        }
    }
}