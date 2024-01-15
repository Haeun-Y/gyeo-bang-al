#include <bits/stdc++.h>

using namespace std;

int main (){
  ios::sync_with_stdio (0);
  cin.tie (0);

  int TC;
  cin >> TC;

  while(TC--){
       int N;
       cin >> N;
       vector<int> V;
    
       for(int i = 1; i <= N; i++){
         int num;
         cin >> num;
         V.push_back(num);
       }
    
       int mx = V[N - 1];
       long long prof = 0;
       
       for(int i = N - 2; i >=0; i--){
          if(mx < V[i]){
              mx = V[i];
          }
          else if(mx > V[i]){
              prof += mx - V[i];
          }
       }
       cout << prof <<'\n';
    }
}