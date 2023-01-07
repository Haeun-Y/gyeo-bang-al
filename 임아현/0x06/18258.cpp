#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<int> Q;
    int N;
    cin >> N;
    
    string cmd;
    while(N--){
        cin >> cmd;
        if(cmd == "push"){
            int num;
            cin >> num;
            Q.push(num);
        }
        else if(cmd == "pop"){
            if(Q.empty()) cout << -1 << '\n';
            else{
             cout << Q.front() << '\n';
             Q.pop();
            }
        }
        else if(cmd == "size") cout << Q.size() << '\n';
        else if(cmd == "front"){
            if(Q.empty()) cout << -1 << '\n';
            else{
                cout << Q.front() << '\n';
            }
        }
        else if(cmd == "back"){
            if(Q.empty()) cout << -1 << '\n';
            else{
                cout << Q.back() << '\n';
            }
        }
        else{
            if(Q.empty()) cout << 1 << '\n';
            else{
                cout << 0 << '\n';
            }
        }
    }
}