//BOJ 1463 1로 만들기
//백트래킹 -> 시간초과
#include <bits/stdc++.h>
using namespace std;
int minResult;
void func1(int x, int operationNum)
{
    if(x == 1)
    {
        if(operationNum < minResult)
            minResult = operationNum;
        return;
    }
    else
    {
        if(x%2 == 0)
            func1(x/2, operationNum+1);
        if(x%3 == 0)
            func1(x/3, operationNum+1);
        func1(x-1, operationNum+1);
    }
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int x;
    cin >> x;
    
    minResult = x;

    func1(x, 0);

    cout << minResult;
    
}