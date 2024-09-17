#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int fib[42][2];
    
    int TC;
    cin >> TC;
    
    fib[0][0] = 1; fib[0][1] = 0;
    fib[1][0] = 0; fib[1][1] = 1;
    
    for(int i = 2; i <= 40; i++){
        fib[i][0] = fib[i - 1][0] + fib[i - 2][0];
        fib[i][1] = fib[i - 1][1] + fib[i - 2][1];
    }
    
    for(int i = 0; i < TC; i++){
        int num = 0;
        cin >> num;
        cout << fib[num][0] << " " << fib[num][1] <<'\n';
    }

}