#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    deque<int> D;
    int N, M; //숫자 몇 개, 몇 개 뽑을지
    cin >> N >> M;
    
    for(int i = 1; i <= N; i++){
        D.push_back(i);
    }
    
    int cnt = 0;
    int idx, ft;
    while(M--){
        int num = 0;
        cin >> num;
        
        //앞이 빠른지 뒤가 빠른지 체크? 어딘지 알아야 됨
        for(int i = 0; i < D.size(); i++){
            //deque 배열처럼 접근 가넝
            if(D[i] == num) idx = i;
        }
        
        if(idx < D.size() - idx){
          while(true){
            if(num == D.front()){
                D.pop_front();
                break;
            }
            cnt++;
            ft = D.front();
            D.push_back(ft); //앞에서 뒤로 2번 연산
            D.pop_front();
           }
        }
        
        else{
           while(true){
            if(num == D.front()){
                D.pop_front();
                break;
            }
            cnt++;
            ft = D.back(); 
            D.push_front(ft); //뒤에서 앞으로 3번 연산
            D.pop_back();
        }
      }
    }
    cout<<cnt;
}