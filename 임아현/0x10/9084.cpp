#include <bits/stdc++.h>
using namespace std;
int T;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T; //test case
    
    while(T--){
        int N, M;
        int arr[10002] = {0};
        int num[10002] = {0};
        cin >> N; //동전 가지 수
        for(int i = 0; i < N; i++){
            cin >> num[i];
        }
        cin >> M;
        arr[0] = 1;
        for(int i = 0; i < N; i++){
            //동전 차례대로 빼서 경우의 수 더해줌줌
            for(int j = num[i]; j <= M; j++){
                arr[j] += arr[j - num[i]];
            }
        }
        cout << arr[M] << '\n';
    }
}