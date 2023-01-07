#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    deque<int> D;
    int N;
    cin >> N;
    
    string cmd;
    while(N--){
        cin >> cmd;
        if(cmd == "push_front"){
            int num;
            cin >> num;
            D.push_front(num);
        }
        else if(cmd == "push_back"){
            int num;
            cin >> num;
            D.push_back(num);
        }
        else if(cmd == "pop_front"){
            if(D.empty()) cout << -1 << '\n';
            else{
             cout << D.front() << '\n';
             D.pop_front();
            }
        }
        else if(cmd == "pop_back"){
            if(D.empty()) cout << -1 << '\n';
            else{
             cout << D.back() << '\n';
             D.pop_back();
            }
        }
        else if(cmd == "size") cout << D.size() << '\n';
        else if(cmd == "front"){
            if(D.empty()) cout << -1 << '\n';
            else{
                cout << D.front() << '\n';
            }
        }
        else if(cmd == "back"){
            if(D.empty()) cout << -1 << '\n';
            else{
                cout << D.back() << '\n';
            }
        }
        else{
            if(D.empty()) cout << 1 << '\n';
            else{
                cout << 0 << '\n';
            }
        }
    }
}