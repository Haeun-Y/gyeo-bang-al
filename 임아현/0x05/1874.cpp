#include <bits/stdc++.h>

using namespace std;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int K;  
  cin >> K;
  
  stack<int> S;
  string result;
  int cnt = 1;
  
  int flag = 0;
  
 for(int i = 0; i < K; i++){
     int num;
     cin >> num;
     
      while(cnt <= num){
          cout << "push ";
           S.push(cnt++);
           result += "+\n";
      }
      
      if(S.top() != num){
          flag = 1;
          break;
      }
      cout << "pop ";
      S.pop();
      result += "-\n";
  }
  
  if(flag != 1) cout << result;
  else cout << "NO";
}
