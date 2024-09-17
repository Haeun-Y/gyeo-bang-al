#include <bits/stdc++.h>

using namespace std;

int num[15];
int arr[15];
bool isused[15];

#define LNUM 6
int N;

void func(int k, int idx){
    if(k == LNUM){
        for(int i = 0; i < LNUM; i++){
            cout << arr[i] << ' '; 
        }
        cout << "\n";
        return;
    }
    for(int i = idx; i < N; i++){
        if(!isused[i]){
            arr[k] = num[i];
            isused[i] = 1;
            idx++;
            func(k + 1,  idx);
            isused[i] = 0;
        }
        
    }
}

int main()
{
    while(1){
        cin >> N;
        if(N == 0) break;
        for(int i = 0; i < N; i++){
            cin >> num[i];
        }
        func(0, 0);
        cout << '\n';
    } 
}