#include <bits/stdc++.h>

using namespace std;

int arr[52][10];
vector<int>order = {1, 2, 3, 4, 5, 6, 7, 8};
int hscore = 0;
int N; //이닝 수수

void hit(){
    order.insert(order.begin() + 3, 0); //4번 주자는 늘 1번 선수
    int ocnt = 0; // outcount
    int inning = 0; //이닝
    int idx = 0; //현재 타순
    int score = 0; //점수
    while(inning < N){
        bool mound[4] = {0};
        ocnt = 0; //새로운 이닝마다 outcount 초기화화
        while(ocnt != 3){ //한 이닝은 아카 3번 차기 전까지... 
            int hitscore = arr[inning][order[idx]];
            if(hitscore == 0) ocnt++; //아웃
            else if(hitscore == 4){ //홈런
                score++;
                for(int i = 1; i < 4; i++) { //주자 다 홈으로
                    if(mound[i]){
                        mound[i] = 0;
                        score++;
                    }
                }
            }
            else{
                //안타 침 -> 주자들 다 이동 시킴킴
                for(int i = 3; i > 0; i--){
                    if(mound[i]){
                        if(i + hitscore > 3){
                            score++;
                            mound[i] = 0;
                        }
                        else{
                            mound[i + hitscore] = 1;
                            mound[i] = 0;
                        }
                    }
                }
                //안타 친 사람 이동
                mound[hitscore] = 1;
            }
            idx = (idx + 1) % 9; //타순은 3아웃 전까지 돌고 되니까...
        }
        inning++;
    }
    hscore = max(hscore, score);
    order.erase(order.begin() + 3); //4번 주자는 늘 1번 선수
}

int main()
{
    cin >> N; //이닝 수
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < 9; j++){
            cin >> arr[i][j];
        }
    }
    int test = 0;
    do{
        hit();
    }while(next_permutation(order.begin(), order.end()));
    
    cout << hscore;
    
}