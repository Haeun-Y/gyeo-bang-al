#include <bits/stdc++.h>

using namespace std;

int num[8];

int N, M;

void func(int n, int depth){
    if(depth == M){
        for(int i = 0; i < M; i++){
            cout << num[i] << " ";
        }
        cout << '\n';
        return;
    }
    
    for(int i = n; i <= N; i++){
        num[depth] = i;
        func(i, depth + 1);
    }
    
}


int main()
{
    cin >> N >> M; //1~N M개 고르기 
    
    func(1, 0);
    
    
}