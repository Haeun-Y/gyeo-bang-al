#include <bits/stdc++.h>

int num[12];
int op[5];
int N;
int MAX = INT_MIN;
int MIN = INT_MAX;


using namespace std;

void find(int n, int idx){
    //연산자 네 개 다 골랐으면 계산 결과 비교
    if(idx == N){
        MAX = max(MAX, n);
        MIN = min(MIN, n);
        return;
    }
    
    for(int i = 0; i < 4; i++){
        //백트래킹
        if(op[i] > 0){
            //연산자 하나 선택했으므로
            op[i]--;
            switch(i){
                case 0: find(n + num[idx], idx + 1); break;
                case 1: find(n - num[idx], idx + 1); break;
                case 2: find(n * num[idx], idx + 1); break;
                case 3: find(n / num[idx], idx + 1); break;
            }
            //return후엔 줄인 연산자 다시 늘리기
            op[i]++;
        }
    }
    
}

int main()
{
    cin >> N;
    
    for(int i = 0; i < N; i++){
        cin >> num[i];
    }
    for(int i = 0; i < 4; i++){
        cin >> op[i];
    }
    
    find(num[0], 1);
    cout << MAX << '\n' << MIN;
}