#include <bits/stdc++.h>
using namespace std;

int N, W, L;//트럭 수, 다리 길이, 하중
int sum = 0;
int cnt = 0;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> N >> W >> L; //트럭 수, 다리 길이, 하중

  queue<int> Q;//모든 트럭
  
  while(N--){
      int weight;
      cin >> weight;
      Q.push(weight);
  }

  //어쨌든 매초 출발 시키기? 
  //무게가 넘으면 0인 걸 임의로 넣기
  
  queue<int> CQ; //현재 다리에 있는 트럭
  int timeout = 0;
  
  while(true){
      int temp = 0;
      cnt++; //시간 재기
      if(!Q.empty()) temp = Q.front();
      else{
          cnt += W; break;
      }
      if(cnt > W){
          sum -=  CQ.front(); 
          CQ.pop();
      }
      
      if(sum + temp > L){
          CQ.push(0);
      }
      
      else{
          Q.pop();
          CQ.push(temp);
          sum += temp;
      }
  }
  cout << cnt - 1;
}