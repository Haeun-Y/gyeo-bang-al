#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[10]; //수열 담음
bool isused[10]; //특정 수가 쓰였는지 (상태)

void func(int k, int idx){ //depth, idx
    if(k == m){
        for(int  i = 0; i < m; i++){
            cout << arr[i] << ' ';
        }
                                                                                                                                                                                                                                                                                                                                                                                   cout << '\n';
        return;
    }
    for(int i = idx; i <= n; i++){
        if(!isused[i]){
            arr[k] = i;
            isused[i] = 1;
            idx++; //idx 하나 증가시키기
            func(k + 1, idx);
            isused[i] = 0;
        }
    }
    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    func(0, 1);
    
}