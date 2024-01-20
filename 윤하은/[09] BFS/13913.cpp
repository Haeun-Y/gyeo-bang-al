//240120
//BOJ 13913 숨바꼭질4
//GOLD 4
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
const int LENGTH = 100001;
int subinPos, sisterPos;
int dx[2] = {-1, 1};
void printResult(int timeResult, vector<int>& beforePos)
{
    cout << timeResult << "\n";

    stack<int> s;
    
    int i;
    for(i = sisterPos; i != beforePos[i]; i = beforePos[i])
        s.push(i);
    s.push(i);
    
    while(!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}
void findSister()
{
    vector<bool> isVisited = vector<bool>(LENGTH,false);
    vector<int> hideAndSeek = vector<int>(LENGTH, -1);
    vector<int> beforePos = vector<int>(LENGTH, -1);
    queue<int> q;
    q.push(subinPos);
    isVisited[subinPos] = true;
    hideAndSeek[subinPos] = 0;
    beforePos[subinPos] = subinPos;

    while(!q.empty())
    {
        int curPos = q.front();
        q.pop();

        if(curPos == sisterPos)
        {
            printResult(hideAndSeek[curPos], beforePos);
            return;
        }

        int nx = curPos * 2;
        
        if(nx >= 0 && nx < LENGTH && !isVisited[nx])
        {
            q.push(nx);
            isVisited[nx] = true;
            hideAndSeek[nx] = hideAndSeek[curPos]+1;
            beforePos[nx] = curPos;
        }

        for(int i = 0; i<2; i++)
        {
            nx = curPos + dx[i];
            
            if(nx < 0 || nx >= LENGTH) continue;
            if(isVisited[nx]) continue;

            q.push(nx);
            isVisited[nx] = true;
            hideAndSeek[nx] = hideAndSeek[curPos]+1;
            beforePos[nx] = curPos;
        }

    }



    
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> subinPos >> sisterPos;

    findSister();
}