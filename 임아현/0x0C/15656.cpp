#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[10]; //숫자 담음
int idx[10]; //숫자 배열의 인덱스 담음

void func(int k){ //depth, 현재 인덱스 
    if(k == m){
        for(int  i = 0; i < m; i++){
            cout << arr[idx[i]] << ' ';
        }
                                                                                                                                                                                                                                                                                                                                                                                   cout << '\n';
        return;
    }
    for(int i = 0; i < n; i++){ //0부터 n까지 (중복 상관 X)
            idx[k] = i;
            func(k + 1);
    }
    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    sort(arr, arr + n); //사전순 정렬

    func(0);
    
}