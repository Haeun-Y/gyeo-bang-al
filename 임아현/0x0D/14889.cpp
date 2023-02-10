#include <bits/stdc++.h>
using namespace std;

int MIN = 10000;
int N;
bool num[22];
int arr[22][22];

void cal(){
    //링크 스타트
    int L = 0, S = 0;
    for(int i = 0; i < N - 1; i++){
        for(int j = i + 1; j < N; j++){
            if(num[i] && num[j]){
                L += arr[i][j];
                L += arr[j][i];
            }
            else if(!num[i] && !num[j]){
                S += arr[i][j];
                S += arr[j][i];
            }
        }
    }
    
    int dif = abs(L - S);
    if(dif == 0){
        cout << dif;
        exit(0);
    }
    MIN = min(dif, MIN);
}

void find(int idx, int depth){
    if(depth == N/2){
        cal();
        return;
    }
    for(int i = idx; i < N; i++){
        if(!num[i]){
            num[i] = 1;
            find(i + 1, depth + 1);
            num[i] = 0;
        }
    }
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> arr[i][j];
        }
    }
    find(0, 0);
    cout << MIN;
}
