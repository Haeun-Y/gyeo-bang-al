#include <bits/stdc++.h>

using namespace std;

int N; //숫자 개수 
int arr[12]; //숫자 
vector<int> cal; // 0: + 1: - 2: * 3:/
int ex[12]; //고른 수식 
bool vis[12]; //골랐는지지
int max_ans = -1000000000;
int min_ans = 1000000000;

 
void solution(int k){
    if(k == N - 1){
        //수식 순서대로 계산하기 
        int result = arr[0];
        for(int i = 0; i < N - 1; i++){
            switch(ex[i]){
                case 0: result = result + arr[i + 1]; break;
                case 1: result = result - arr[i + 1]; break;
                case 2: result = result * arr[i + 1]; break; 
                case 3: result = result / arr[i + 1]; break;
            }
        }
        min_ans = min(min_ans, result);
        max_ans = max(max_ans, result);
        return;

    }
    //수식 고르기 
    for(int i = 0; i < N - 1; i++){
        if(!vis[i]){
            ex[k] = cal[i];
            vis[i] = 1;
            solution(k + 1);
            vis[i] = 0;
        }
    }
    
}

int main()
{
    cin >> N;
    for(int i = 0; i < N; i++) cin >> arr[i];
    for(int i = 0; i < 4; i++){
        int temp;
        cin >> temp;
        while(temp--){
            cal.push_back(i);
        }
    }
    solution(0);
    cout << max_ans << '\n' << min_ans;
}