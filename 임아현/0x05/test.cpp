#include <bits/stdc++.h>

using namespace std;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int K;  
  cin >> K;
  
  stack<int> S;
  vector<char> V;
  int num; //입력받은 수
  
  for(int i = 0; i < K; i++){
      cout << "입력받기 시작"; 
      cin >> num;
      S.push(num);
      cout << "top: " << S.top() << '\n';
  }
  
  int top, flag; //stack의 top, flag (가능 여부)
  int idx = 1;
  while(idx < K){
      top = S.top();
      cout << "top: " << top << '\n';
      S.pop();
      
      if(top > idx){
          while(num == idx){
              idx++;
              V.push_back('+');
          }
      }
      else if(top == idx){
          V.push_back('-');
      }
      else{
          flag = 1;
          break;
      }
  }
  
  if(flag != 1){
      cout << "test";
      for(auto c: V){
        cout << c << '\n';
        cout << "뭐가되긴";
      }
  }
  else cout << "NO";
}
