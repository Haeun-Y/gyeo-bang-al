//240413
//BOJ 16986 인싸들의 가위바위보
//GOLD 3
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> winLose;
vector<vector<int>> motionInfo;
int n, requiredWinNum;
int nextParticipant(int p1, int p2)
{
    vector<bool> v(3, false);
    v[p1] = v[p2] = true;

    for(int i = 0; i<3; i++)
        if(!v[i]) return i;
}
int playGame()
{
    vector<pair<int, int>> gameInfo(3, {0, 0});//first : 진행수, second : 우승수

    int participant1 = 0;//지우
    int participant2 = 1;//경희

    while(gameInfo[0].first < n && gameInfo[1].first < 20 && gameInfo[2].first < 20)
    {
        int motion1 = motionInfo[participant1][gameInfo[participant1].first];
        int motion2 = motionInfo[participant2][gameInfo[participant2].first];

        int result = winLose[motion1][motion2];//participant1 기준 결과

        if(result == 0)//participant1 lose
        {
            gameInfo[participant2].second++;
            participant1 = nextParticipant(participant1, participant2);
        }
        else if(result == 1)//participant1 draw
        {
            if(participant1 > participant2)
            {
                gameInfo[participant2].second++;
                participant1 = nextParticipant(participant1, participant2);
            }
            else
            {
                gameInfo[participant1].second++;
                participant2 = nextParticipant(participant1, participant2);
            }
        }
        else//result == 2, participant1 win
        {
            gameInfo[participant1].second++;
            participant2 = nextParticipant(participant1, participant2);
        }
        gameInfo[participant1].first++;
        gameInfo[participant2].first++;

        if(gameInfo[0].second == requiredWinNum) return 1;
        else if(gameInfo[1].second == requiredWinNum || gameInfo[2].second == requiredWinNum) return 0;
    }

    return 0;

}
int solution()
{
    vector<int> jiwoo(n, 0);
    for(int i = 0; i<n; i++)
        jiwoo[i] = i+1;//1, 2, 3, ... n
    
    do
    {
        for(int i = 0; i<n; i++)
            motionInfo[0][i] = jiwoo[i];
        int result = playGame();
        if(result == 1)
            return 1;

    }while(next_permutation(jiwoo.begin(), jiwoo.end()));

    return 0;

}
int main(void)
{
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);

    cin >> n >> requiredWinNum;
    winLose = vector<vector<int>>(n+1, vector<int>(n+1));
    motionInfo = vector<vector<int>>(3, vector<int>(20));

    for(int i = 1; i<=n; i++)
        for(int j = 1; j<=n; j++)
            cin >> winLose[i][j];

    for(int i = 1; i<=2; i++)
        for(int j = 0; j<20; j++)
            cin >> motionInfo[i][j];

    cout << solution();

}
