//BOJ 2240 자두나무
//시간초과
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<bool> plumfall;
int t, w;
int maxPlum;
void backtracking(int curT, int curMove, int curPlum, bool isUnderTree1)
{
    //cout << "curTime : " << curT << ", curMove : " << curMove << ", curPlum : " << curPlum << ", curPos : ";
    //if(isUnderTree1) cout << "1\n";
    //else cout << "2\n";
    
    if(curT > t)
    {
        maxPlum = max(maxPlum, curPlum);
        //cout << "**************curPlum : " << curPlum << "**************\n";
        return;
    }
    
    else
    {
        if(isUnderTree1 == plumfall[curT])
            backtracking(curT+1, curMove, curPlum+1, isUnderTree1);
        else
        {
            if(curMove < w)
                backtracking(curT+1, curMove+1, curPlum+1, !isUnderTree1);
            backtracking(curT+1, curMove, curPlum, isUnderTree1);
        }
    }
    
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> t >> w;
    
    maxPlum = 0;
    plumfall = vector<bool>(t+1, false);
    
    for(int i = 1; i<= t; i++)
    {
        int treeNum;
        cin >> treeNum;
        if(treeNum == 1) plumfall[i] = true;
    }
    
    backtracking(1, 0, 0, true);
    cout << maxPlum;
    
    
    
}
