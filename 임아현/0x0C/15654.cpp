#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[10]; //숫자 담음
int idx[10]; //숫자 배열의 인덱스 담음
bool isused[10]; //해당 인덱스 사용 여부

void func(int k){
    if(k == m){
        for(int  i = 0; i < m; i++){
            cout << arr[idx[i]] << ' ';
        }
                                                                                                                                                                                                                                                                                                                                                                                   cout << '\n';
        return;
    }
    for(int i = 0; i < n; i++){
        if(!isused[i]){
            idx[k] = i;
            isused[i] = 1;
            func(k + 1);
            isused[i] = 0;
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

    func(0);
    
}