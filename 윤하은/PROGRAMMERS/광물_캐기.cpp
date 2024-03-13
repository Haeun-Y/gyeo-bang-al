//240313
//PROGRAMMERS 광물캐기
//Lv.2
#include <bits/stdc++.h>
using namespace std;
int computeFatigue(vector<string>& minerals, int idx, int pickType)
{
    map<string, int> dia = {{"diamond", 1}, {"iron", 1}, {"stone", 1}};
    map<string, int> iron = {{"diamond", 5}, {"iron", 1}, {"stone", 1}};
    map<string, int> stone = {{"diamond", 25}, {"iron", 5}, {"stone", 1}};
    int total = 0;
    
    for(int i = idx; i<idx+5; i++)
    {
        if(pickType == 0)
            total += dia[minerals[i]];
            
        else if(pickType == 1)
            total += iron[minerals[i]];
        else
            total += stone[minerals[i]];
    }
    return total;
    
}
int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    
    int pickNum = picks[0] + picks[1] + picks[2];
    int mineralNum = minerals.size();
    int curIdx = 0;
    while(curIdx <= mineralNum && pickNum > 0)
    {
        vector<int> fatigue(3, 125);
        if(picks[0] >= 1)
            fatigue[0] = computeFatigue(minerals, curIdx, 0);
        if(picks[1] >= 1)
            fatigue[1] = computeFatigue(minerals, curIdx, 1);
        if(picks[2] >= 1)
            fatigue[2] = computeFatigue(minerals, curIdx, 2);
        
        int minIdx = min_element(fatigue.begin(), fatigue.end()) - fatigue.begin();
        answer += fatigue[minIdx];
        pickNum[minIdx]--;
        curIdx += 5;
    }
    
    return answer;
}