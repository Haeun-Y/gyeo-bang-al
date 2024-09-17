//240127
//softeer 출퇴근길
//Lv.3
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int nodeNum, edgeNum;
int sNode, tNode;
vector<vector<bool>> route;
vector<vector<bool>> isReachable;
void computeReachableFromST(int n1, int n2, int idx)
{
    vector<bool> isVisited(nodeNum+1, false);
    queue<int> q;
    q.push(n1);
    isVisited[n1] = true;

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();

        for(int i = 1; i<nodeNum+1; i++)
        {
            if(!route[cur][i] || isVisited[i]) continue;
            if(i == n2) continue;
            //cout << i << " is reachable from " << n1 << "\n";
            isReachable[idx][i] = true;
            q.push(i);
            isVisited[i] = true;
        }
    }
}
void computeReachableToST(int n1, int idx)
{
    for(int i = 1; i<=nodeNum; i++)
    {
        if(i == sNode || i == tNode) continue;
        if(isReachable[idx][i]) continue;

        queue<int> q;
        vector<bool> isVisited(nodeNum+1, false);
        q.push(i);
        isVisited[i] = true;
        bool flg = false;

        while(!q.empty() && !flg)
        {
            int cur = q.front();
            q.pop();

            for(int j = 1; j <= nodeNum; j++)
            {
                if(isVisited[j] || !route[cur][j]) continue;
                if(isReachable[idx][j] || j == n1)
                {
                    isReachable[idx][i] = true;
                    //cout << i << " is reachable to " << n1 << "\n";
                    flg = true;
                    break;
                }
                q.push(j);
                isVisited[j] = true;
            }
        }

    }

}
int computeNodeVisitedInDuplicated()
{
    int cnt = 0;
    //cout << "check s -> idx\n";
    computeReachableFromST(sNode, tNode, 0);
    //cout << "\ncheck idx -> t\n";
    computeReachableToST(tNode, 1);
    //cout << "\ncheck t -> idx\n";
    computeReachableFromST(tNode, sNode, 2);
    //cout << "\ncheck idx -> s\n";
    computeReachableToST(sNode, 3);

    for(int i = 1; i<=nodeNum; i++)
    {
        if(i == sNode || i == tNode) continue;
        if(isReachable[0][i] && isReachable[1][i] && isReachable[2][i] && isReachable[3][i])
            cnt++;
    }
    return cnt;
}
int main(void)
{
    cin >> nodeNum >> edgeNum;

    route = vector<vector<bool>>(nodeNum+1, vector<bool>(nodeNum+1, false));
    /*
    0 : sNode -> idx
    1 : idx -> tNode
    2 : tNode -> idx
    3 : idx -> sNode
    */
    isReachable = vector<vector<bool>>(4, vector<bool>(nodeNum+1, false));

    for(int i = 0; i<edgeNum; i++)
    {
        int n1, n2;
        cin >> n1 >> n2;
        route[n1][n2] = true;
    }
    cin >> sNode >> tNode;

    cout << computeNodeVisitedInDuplicated();

}