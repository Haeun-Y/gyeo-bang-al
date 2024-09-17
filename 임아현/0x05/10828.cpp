#include <bits/stdc++.h>

using namespace std;
int main(void) {
  //ios::sync_with_stdio(0);
 // cin.tie(0);
  
  int N; //명령의 수 
  cin >> N;
  
  stack<int> S;
  
  string cmd;
  for(int i = 0; i < N; i++){
      cin >> cmd;
      if(cmd == "push"){
          int num;
          cin >> num;
          S.push(num);
      }
      else if(cmd == "pop"){
          if(S.empty()) cout << "-1" << '\n';
          else{
              cout << S.top() << '\n';
              S.pop();
          }
      }
      else if(cmd == "size") cout << S.size() << '\n';
      else if(cmd == "empty"){
          if(S.empty()) cout << 1 << '\n';
          else cout << 0 << '\n';
      }
      else{
          if(S.empty()) cout << -1 << '\n';
          else cout << S.top() << '\n';
      }
  }
}