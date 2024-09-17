#include <bits/stdc++.h>

using namespace std;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  list<char> L;
  list<char>::iterator it = L.end(); //iterator, 맨끝을 가리킴 
  string str;
  cin >> str; //ex)abcd 
  
  for(auto c: str){
      L.push_back(c);
  }
  
  int num; //명렁 개수
  cin >> num;
  
  for(int i = 0; i < num; i++){
      char cmd; //입력된 명령어
      cin >> cmd;
      if(cmd == 'L'){
          if(it != L.begin()) it--;
      }
      else if(cmd == 'D'){
          if(it != L.end()) it++;  
      } 
      else if(cmd == 'B'){
          if(it != L.begin()){
             it--;
             it = L.erase(it);
          }
      }
      else if(cmd == 'P'){
          char add;
          cin >> add;
          L.insert(it, add);
      }
  }
  for(auto c: L){
      cout << c;
  }
}