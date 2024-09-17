#include <bits/stdc++.h>

using namespace std;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int t;
  cin >> t; //TC 개수
  
  for(int i = 0; i < t; i++){
      string str;
      cin >> str; //test case
      
      list<char> L; //string list 저장
      auto it = L.begin(); //iterator
      
      for(auto c: str){
          if(c =='<'){
              if(it != L.begin()) it--;
          }
          else if(c =='>'){
              if(it != L.end()) it++;
          }
          else if(c == '-'){
              if(it != L.begin()){
                  it--;
                  it = L.erase(it);
              };
          }
          else{
              L.insert(it, c);
          }
      }
      for(auto c: L) cout << c;
      cout << '\n';
 }
}