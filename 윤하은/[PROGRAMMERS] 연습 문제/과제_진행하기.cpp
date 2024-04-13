//230319
//PROGRAMMERS 과제 진행하기
//Lv.2
#include <bits/stdc++.h>
using namespace std;
int computeMin(string str)
{
    return stoi(str.substr(0, 2)) * 60 + stoi(str.substr(3,2));
}
bool cmp(vector<string> a, vector<string> b)
{
    return computeMin(a[1]) < computeMin(b[1]);
}
vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    sort(plans.begin(), plans.end(), cmp);
    stack<pair<string, int>> stoppedHw;
    int hwNum = plans.size();
    for(int i = 0; i<hwNum-1; i++)
    {
        int curStartTime = computeMin(plans[i][1]);
        int curNeedTime = stoi(plans[i][2]);
        int curFinTime = curStartTime + curNeedTime;
        int nextStartTime = computeMin(plans[i+1][1]);
        
        if(curFinTime == nextStartTime)
        {
            answer.push_back(plans[i][0]);
            continue;
        }
        else if(curFinTime > nextStartTime)
            stoppedHw.push({plans[i][0], curNeedTime - (nextStartTime - curStartTime)});
        else //curFinTime < nextStartTime
        {
            answer.push_back(plans[i][0]);
            int curTime = curFinTime;
            while(!stoppedHw.empty())
            {
                pair<string, int> curHw = stoppedHw.top();
                stoppedHw.pop();
                
                int targetFinTime = curTime + curHw.second;
                if(targetFinTime == nextStartTime)
                {
                    answer.push_back(curHw.first);
                    break;
                }
                else if(targetFinTime > nextStartTime)
                {
                    stoppedHw.push({curHw.first, curHw.second - (nextStartTime - curTime)});
                    break;
                }
                else//targetFinTime < nextStartTime
                {
                    answer.push_back(curHw.first);
                    curTime = targetFinTime;   
                }
                
                
            }
            
        }
    }
    answer.push_back(plans[hwNum-1][0]);
    while(!stoppedHw.empty())
    {
        pair<string, int> curHw = stoppedHw.top();
        stoppedHw.pop();
        answer.push_back(curHw.first);
    }
    return answer;
}
/*
//중심 반복문 -> while 문 하나로 수정해보기
vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    sort(plans.begin(), plans.end(), cmp);
    stack<pair<string, int>> s;
    int hwNum = plans.size();
    
    s.push({plans[0][0], computeMin(plans[0][2])});
    int i = 0;
    int curTime = computeMin(plans[0][1]);
    
    while(!s.empty() && i < hwNum-1)
    {
        int nextStartTime = computeMin(plans[i+1][1]);
        
        pair<string, int> curHw = s.top();
        s.pop();
                
        int targetFinTime = curTime + curHw.second;
        if(targetFinTime == nextStartTime)
        {
            answer.push_back(curHw.first);
            s.push({plans[i+1][0], computeMin(plans[i+1][2])});
            i++;
            break;
        }
        else if(targetFinTime > nextStartTime)
        {
            s.push({curHw.first, curHw.second - (nextStartTime - curTime)});
            s.push({plans[i+1][0], computeMin(plans[i+1][2])});
            i++;
            break;
        }
        else//targetFinTime < nextStartTime
        {
            answer.push_back(curHw.first);
            curTime = targetFinTime;   
        }
                
                
    }
    
    answer.push_back(plans[hwNum-1][0]);
    while(!s.empty())
    {
        pair<string, int> curHw = s.top();
        s.pop();
        answer.push_back(curHw.first);
    }
    return answer;
}

*/