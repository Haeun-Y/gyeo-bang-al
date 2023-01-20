#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll fun(int a, int b, int c){
    if(b == 1) return a % c;
    ll val = fun(a, b/2, c);
    val = val * val % c;
    if(b % 2 == 0) return val;
    return val * a % c; //홀수 이면 한 번 더 곱해서 짝수로 만들어 반환
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll a, b, c;
    cin >> a >> b >> c;
    cout << fun(a, b, c);
}