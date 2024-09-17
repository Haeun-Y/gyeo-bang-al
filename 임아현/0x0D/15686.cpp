#include <bits/stdc++.h>

using namespace std;
#define X first
#define Y second

int N, M; //N X N, 폐업시키지 않을 치킨집 수
int ccnt = 0, hcnt = 0, answer = 10000;
int city[52][52];
int pick[15]; //고른 치킨집
bool isused[15]; //고른 치킨집 체크
int dist[102][102]; //치킨집 거리 R: 집 번호, C: 각각 치킨집과의 거리

//해당 치킨집의 치킨 거리 확인...
int mindist(){
    //선택된 번호 (pick)
    int sum = 0;
    for(int i = 0; i < hcnt; i++){
        int mindist = 10000;
        for(int j = 0; j < M; j++){
            mindist = min(mindist, dist[i][pick[j]]);
        }
        sum += mindist;
    }
    return sum;
}
//치킨 집 고르는 함수(백트래킹)
void choose(int k, int cur){
    if(k == M){
        int sum = mindist();
        answer = min(answer, sum);
        return;
    }
    
    for(int i = cur; i < ccnt; i++){
        if(!isused[i]){
            pick[k] = i;
            isused[i] = 1;
            cur++;
            choose(k + 1, cur);
            isused[i] = 0;
        }
        
    }
    
}

int main()
{
    cin >> N >> M;
    
    queue<pair<int, int>> CQ; //치킨
    queue<pair<int, int>> HQ; //집
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            int temp;
            cin >> temp;
            city[i][j] = temp;
            if(temp == 1){
                HQ.push({i, j});
                hcnt++;
            }
            if(temp == 2){
                CQ.push({i, j});
                ccnt++;
            }
        }
    }

    int idx1 = 0; //집
    
    //모든 거리 계산
    while(!HQ.empty()){
        auto cur = HQ.front(); HQ.pop();
        int idx2 = 0; //
        while(idx2 < ccnt){
            auto chk = CQ.front(); CQ.pop(); CQ.push(chk);
            dist[idx1][idx2] = abs(cur.X - chk.X) + abs(cur.Y - chk.Y);
            idx2++;
        }
        idx1++;
    }
    
    //M개 고르기
    choose(0, 0);
    cout << answer;
}