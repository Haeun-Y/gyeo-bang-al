#include <bits/stdc++.h>

using namespace std;
int N, M;
int arr[2005];
int p[2005][2005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    
    for(int i = 1; i <= N; i++){
        cin >> arr[i];
    }
    
    for(int i = 1; i <= N; i++){
        p[i][i] = 1; // 11, 22, 33 이런 숫자들은 무조건 대칭
        if(arr[i - 1] == arr[i]){
            p[i - 1][i] = 1;
        }
    }
   
    for(int i = N - 1; i > 0; i--){
        for(int j = i + 2; j <= N; j++){
            if(arr[i] == arr[j] && p[i + 1][j - 1] == 1){
                p[i][j] = 1;
            }
        }
    }
    
    cin >> M;
    while(M--){
        int S, E;
        cin >> S >> E;
        cout << p[S][E] << '\n';
    }
}