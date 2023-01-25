#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[10]; //숫자 담음
int idx[10]; //숫자 배열의 인덱스 담음

void func(int k, int cur){ //depth, 현재 idx
    if(k == m){
        for(int  i = 0; i < m; i++){
            cout << idx[i] << ' ';
        }                                                                                                                                                                                                                                                                                                                                                                          cout << '\n';
        return;
    }
    int tmp = 0; //중복 체크
    for(int i = cur; i < n; i++){
        if(tmp != arr[i]){ //양끝이 달라야 함
            idx[k] = arr[i];
            tmp = idx[k];
            func(k + 1, i); //현재 idx부터
        }
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
    
    func(0, 0);
}