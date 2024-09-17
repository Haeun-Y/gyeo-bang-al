#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL);
    
    stack<pair<int, int>> S; //높이 저장할 stack
    //stack<int> R; //결과값
    int height; //높이 
    
    int N; //탑 개수
    cin >> N;
    
    int first;
    cin >>first;
    S.push({first, 1});
    
    int idx = 2;
    cout << "0" << ' ';
    
    for(int i = 2; i<= N; i++){
        cin >> height;
        int flag = 0;
        while(!S.empty()){
          if(height < S.top().first){
            cout << S.top().second << ' ';
            flag = 1;
            break;
          }
          S.pop();
      }
      S.push({height, i});
      idx++;
      if(flag == 0) cout << "0 ";
    }
}