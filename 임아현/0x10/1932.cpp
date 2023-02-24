#include <bits/stdc++.h>

using namespace std;

int N;
int arr[502][502];
int sum[502][502];

int rec(int r, int c){
    if(r == N - 1) return sum[r][c];
    if(!sum[r][c]) sum[r][c] = max(rec(r + 1, c), rec(r + 1, c + 1)) + arr[r][c];
    return sum[r][c];
}

int main()
{
    cin >> N;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j <= i; j++){
            cin >> arr[i][j];
        }
    }
    
    for(int i = 0; i < N; i++){
        sum[N - 1][i] = arr[N - 1][i];
    }
    
    cout << rec(0, 0);
}