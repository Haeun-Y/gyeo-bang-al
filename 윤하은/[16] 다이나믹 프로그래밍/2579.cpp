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
    vector<vector<pair<int, int>>> scores(stairNum, vector<pair<int, int>>());

    for(int i = 0; i<stairNum; i++)
        cin >> stairs[i];

    scores[0].push_back({stairs[0], 1});
    
    scores[1].push_back({scores[0][0].first + stairs[1], 2});

    for(int i = 2; i<stairNum; i++)
    {
        for(int j = 0; j<scores[i-2].size(); j++)
            scores[i].push_back({scores[i-2][j].first + stairs[i], 0});

        for(int j = 0; j<scores[i-1].size(); j++)
        {
            if(scores[i-1][j].second == 3)
                continue;

            scores[i].push_back({scores[i-1][j].first + stairs[i], scores[i-1][j].second+1});

        }
        
    }

    int maxResult = 0;

    for(int i = 0; i<scores[stairNum-1].size(); i++)
        maxResult = max(maxResult, scores[stairNum-1][i].first);

    cout << maxResult;
    
}