#include <bits/stdc++.h>

using namespace std;
int arr[15] = {0};
int choose[6] = {0};
bool check[15] = {0};
int num = 0;

void func(int k, int idx){
    if(k == 6){
        for(int i = 0; i < 6; i++){
            cout << choose[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i = idx; i < num; i++){
        if(!check[i]){
            choose[k] = arr[i];
            check[i] = 1;
            idx++;
            func(k + 1, idx);
            check[i] = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while(true){
        cin >> num;
        if(!num) break;
        
        for(int i = 0; i < num; i++){
            cin >> arr[i];
        }
        
        func(0, 0);
        cout << "\n";
    }
}