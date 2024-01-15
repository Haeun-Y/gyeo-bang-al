#include <bits/stdc++.h>
using namespace std;
bool board[20][20];
int cnt;
bool diagonal(pair<int, int> a, pair<int, int> b)
{
    if(abs(a.first - b.first) == abs(a.second - b.second))
        return true;
    return false;
}
bool isAllowed(pair<int, int> pos, int n)
{
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            if(board[i][j])
            {
                if(pos.first == i || pos.second == j)
                    return false;
                if(diagonal(pos, {i, j}))
                    return false;
            }
        }
    }
    return true;
    
}
//cur번째 행에 말 배치
void backtracking(int cur, int n)
{
    if(n == cur)
    {
        cnt++;
        return;
    }
        
    
    else
    {
        for(int i = 0; i<n; i++)
        {
            if(!board[cur][i] && isAllowed({cur, i}, n))
            {
                board[cur][i] = true;
                backtracking(cur+1, n);
                board[cur][i] = false;
            }
        }
    }
}
int solution(int n) {
    
    backtracking(0, n);
    int answer = cnt;
    return answer;
}
int main(void)
{
    int n;
    cin >> n;

    cout << solution(n);
}