#include <bits/stdc++.h>

using namespace std;

int num[102];

int main()
{
    int N, M;
    cin >> N >> M;
    
    for(int i = 1; i <= N; i++){
        num[i] = i;
    }
    
    while(M--){
        int start, end;
        cin >> start >> end;
        
        int sum = start + end;
        
        for(int i = end; i > sum / 2; i--){
            swap(num[i], num[sum - i]);
        }
    }
    
    for(int i = 1; i <= N; i++){
        cout << num[i] << ' ';
    }

}