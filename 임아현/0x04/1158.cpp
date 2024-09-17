#include <bits/stdc++.h>

using namespace std;
int main(void) {
  //ios::sync_with_stdio(0);
 // cin.tie(0);
  
  int N; //N명
  cin >> N;
   
  int K; //K명
  cin >> K;
  
  vector<int> V;
  vector<int> result;
  
  for(int i = 1; i <= N; i++){
      V.push_back(i);
  }
  
  for(int i = 0; result.size() < N; i++){
      if(i % K == K - 1) result.push_back(V[i]); //k번째 사람에 해당할 경우
      else V.push_back(V[i]); //제거되지 않은 것은 뒤로 보냄 (앞으로 갈 필요 없이 간 것처럼)
  }
  
  cout << '<';
  for(int i = 0; i < N; i++){
      if(i == N - 1) cout << result[i]; //vector 배열처럼 접근 가능
      else cout << result[i] << ", ";
  }
  cout << '>';
}
