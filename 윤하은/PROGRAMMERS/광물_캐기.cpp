//240313
//PROGRAMMERS 광물캐기
//Lv.2
#include <bits/stdc++.h>
using namespace std;
int computeFatigue(int pickType, int startIdx, int end, vector<string>& minerals)
{
    map<string, int> dia = {{"diamond", 1}, {"iron", 1}, {"stone", 1}};
    map<string, int> iron = {{"diamond", 5}, {"iron", 1}, {"stone", 1}};
    map<string, int> stone = {{"diamond", 25}, {"iron", 5}, {"stone", 1}};
    
    int fatigue = 0;
    for(int i = startIdx; i< end; i++)
    {
        if(pickType == 0)
            fatigue += dia[minerals[i]];
            
        else if(pickType == 1)
            fatigue += iron[minerals[i]];
        else
            fatigue += stone[minerals[i]];
    }
    return fatigue;
}
int solution(vector<int> picks, vector<string> minerals) {
    vector<int> picks2;
    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j<picks[i]; j++)
            picks2.push_back(i);
    }
    int mineralNum = minerals.size();
    int answer = 25 * mineralNum;
    int needPickNum = ceil((double)mineralNum/5);
    if(needPickNum < picks2.size()) picks2.resize(needPickNum);
    do
    {
        int fatigue = 0;
        int idx = 0;
        for(int i = 0; i<picks2.size(); i++)
        {
            fatigue += computeFatigue(picks2[i], min(idx, mineralNum-1), min(idx+5, mineralNum), minerals);
            idx += 5;
        }
        answer = min(fatigue, answer);
        
    }while(next_permutation(picks2.begin(), picks2.end()));
    return answer;
}