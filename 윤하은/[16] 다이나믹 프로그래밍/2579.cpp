//BOJ 2579 계단 오르기
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);

    int stairNum;
    cin >> stairNum;

    vector<int> stairs(stairNum, 0);
    vector<vector<int>> scores(stairNum, vector<int>(2, 0));

    for(int i = 0; i<stairNum; i++)
        cin >> stairs[i];

    scores[0][0] = scores[0][1] = stairs[0];
    
    
    //이부분 리팩토링해야할 듯..
    if(stairNum > 1)
    {
        scores[1][0] = scores[0][0] + stairs[1];
        scores[1][1] = stairs[1];
    }
    

    //scores[i][0] : i-1번째 계단까지 도달하는 값 중 더 점수 높은 것 하나 + stairs[i]
    //scores[i][1] : i-2번째 계단까지 도달하는 값 중 더 점수 높은 것 하나 + stairs[i]
    for(int i = 2; i<stairNum; i++)
    {
        //i-1번째 계단에서 i번째 계단으로 이동
        scores[i][0] = scores[i-1][1] + stairs[i];

        //i-2번째 계단에서 i번째 계단으로 이동
        scores[i][1] = max(scores[i-2][0], scores[i-2][1]) + stairs[i];

    }

    cout << max(scores[stairNum-1][0], scores[stairNum-1][1]);

}