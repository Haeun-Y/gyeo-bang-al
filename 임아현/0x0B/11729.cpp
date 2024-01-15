#include <bits/stdc++.h>

using namespace std;

void hanoi(int a, int b, int n){
    if(n == 1){
    cout << a << ' ' << b << '\n';
    return;
    }
    hanoi(a, 6 - a - b, n - 1);
    cout << a << ' ' << b << '\n';
    hanoi(6 - a - b, b, n - 1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    //횟수 출력: 비트 연산자, 1을 비트 기준으로 k칸 2^k란 뜻
    cout << (1<<N) - 1 << '\n';
    hanoi(1, 3, N); //시작 

    return 0;
}