// 나중에 다시 풀어보고 싶음 (시간초과)

#include<bits/stdc++.h>
using namespace std;
#define std first
#define cho second

int board[100001] = {0};
int vis[100001] = {0};
int num, cnt, check, depth;


int main(){
    int TC;
    cin >> TC;
    
    while(TC--){
        num = 0;
        cnt = 0;
        check = 0;
        
        cin >> num;
        
        for(int i = 1; i <= num; i++){
            cin >> board[i]; //인덱스 - 학생, 값 - 선택한 학생
            if(i == board[i]){//팀이 정해짐
                vis[i] = 1;
                cnt++;
            }
            else vis[i] = 0;
        }
       
        for(int i = 1; i <= num; i++){
            depth = 0;
            if(vis[i] > 0) continue;
            stack<pair<int, int>> S;
            S.push({i, board[i]});
            depth++;
            while(!S.empty()){
                if(depth > num){
                    check = 1;
                    break;
                }
                auto cur = S.top();
                if(vis[cur.cho] > 0){
                    depth++;
                    vis[i] = 1;
                    while(!S.empty()){
                        auto put = S.top(); S.pop();
                    }
                }
                else{ 
                    depth++;
                    S.push({cur.cho, board[cur.cho]});
                    if(i == board[cur.cho]){
                      while(!S.empty()){
                          auto put = S.top(); S.pop();
                          vis[put.std] = 1;
                          cnt++;
                       }
                   }
                }
            }
            if(check && i == num) break;
        }
        cout << num - cnt << '\n';
    }
}