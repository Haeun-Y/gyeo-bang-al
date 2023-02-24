#include <bits/stdc++.h>

using namespace std;
long long arr[102];
long long p[102];
int T;

long long pado(int N){
    if(arr[N] == -1)  arr[N] = (pado(N - 5) + pado(N - 1));
    return arr[N];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    
    for(int i = 5; i < 101; i++){
        arr[i] = -1;
    }
    
    arr[0] = 0; arr[1] = 1; arr[2] = 1; arr[3] = 1; arr[4] = 2;
    
    for(int i = 0; i < T; i++){
        int N;
        cin >> N;
        p[i] = pado(N);
    }
    
    for(int i = 0; i < T; i++){
        cout << p[i] << '\n';
    }
}