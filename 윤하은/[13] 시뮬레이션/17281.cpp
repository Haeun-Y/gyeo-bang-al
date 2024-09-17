//240302
//BOJ 17281
//GOLD 4
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int inningNum, maxScore;
vector<vector<int>> players;
void computeScore(vector<int>& playOrders)
{
    int score = 0;

    for(int i = 0; i<inningNum; i++)
    {
        int outNum = 0;
        int j = 0;
        vector<bool> ground(3, false);

        while(outNum < 3)
        {
            int curResult = players[i][playOrders[j++]];
            if(curResult == 0) outNum++;
            else if(curResult == 1)//주자 1루 이동
            {
                for(int k = 2; k>=0; k--)
                {
                    if(ground[k])
                    {
                        if(k+1 >= 3)
                        {
                            score++;
                            ground[k] = false;
                        }
                        else ground[k+1] = true;
                    }
                }

            }
            else if(curResult == 2)//주자 2루 이동
            {
                for(int k = 2; k>=0; k--)
                {
                    if(ground[k])
                    {
                        if(k+2 >= 3)
                        {
                            score++;
                            ground[k] = false;
                        }
                        else ground[k+2] = true;
                    }
                }

            }
            else if(curResult == 3)//주자 3루 이동
            {
                for(int k = 2; k>=0; k--)
                {
                    if(ground[k])
                    {
                        if(k+3 >= 3)
                        {
                            score++;
                            ground[k] = false;
                        }
                        else ground[k+3] = true;
                    }
                }

            }
            else//타자 포함 주자 홈이동
            {
                for(int k = 0; k<3; k++)
                {
                    if(ground[k])
                    {
                        score++;
                        ground[k] = false;
                    }
                }
                score++;

            }


            

        }
    }

    maxScore = max(maxScore, score);

}
void setPlayersOrder()
{
    vector<int> playOrders;
    for(int i = 0; i<4; i++)
        playOrders.push_back(i);
    
    vector<int> tmp = {4, 5, 6, 7, 8};

    do
    {
        for(int i = 0; i<tmp.size(); i++)
            playOrders.push_back(tmp[i]); 
        computeScore(playOrders);

    }while(next_permutation(tmp.begin(), tmp.end()));

}
int main(void)
{
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);

    cin >> inningNum;
    players = vector<vector<int>>(inningNum, vector<int>(9, 0));
    maxScore = 0;

    for(int i = 0; i<inningNum; i++)
        for(int j = 0; j<9; j++)
            cin >> players[i][j];

    setPlayersOrder();
    cout << maxScore;

}