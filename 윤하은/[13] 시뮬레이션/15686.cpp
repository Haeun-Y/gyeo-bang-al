//240201
//BOJ 15686 치킨 배달
//GOLD 5
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int n, m;
vector<vector<int>> city;
vector<pair<int, int>> chickenRest;
vector<pair<int, int>> houses;
const int CHICKEN_RESTAURANT = 2;
const int CHICKEN_RESTAURANT_M = 3;
const int HOUSE = 1;
const int BLANK = 0;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int computeChickenDist(vector<pair<int, int>>& curChickenRest)
{
    vector<vector<bool>> isVisited(n, vector<bool>(n, false));
    vector<vector<int>> dist(n, vector<int>(n, 0));
    queue<pair<int, int>> q;

    //cout << "***computeChickenDist***\n";

    for(int i = 0; i<m; i++)
    {
        pair<int, int> cur = curChickenRest[i];
        q.push(cur);
        isVisited[cur.first][cur.second] = true;
        city[cur.first][cur.second] = CHICKEN_RESTAURANT_M;
        //cout << "selected chicken restaurant : (" << cur.first << ", " << cur.second << ")\n"; 
    }

    while(!q.empty())
    {
        pair<int, int> cur = q.front();
        int curDist = dist[cur.first][cur.second];
        q.pop();

        for(int i = 0; i<4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(isVisited[nx][ny] || city[nx][ny] == CHICKEN_RESTAURANT_M) continue;
            
            dist[nx][ny] = curDist+1;
            q.push(make_pair(nx, ny));
            isVisited[nx][ny] = true;            
        }

    }

    int chickenDist = 0;

    for(int i = 0; i<houses.size(); i++)
    {
        //cout << "chickenDist[" << houses[i].first << "][" << houses[i].second << "] : " << dist[houses[i].first][houses[i].second] << "\n";
        chickenDist += dist[houses[i].first][houses[i].second];
    }

    for(int i = 0; i<m; i++)
    {
        pair<int, int> cur = curChickenRest[i];
        city[cur.first][cur.second] = CHICKEN_RESTAURANT;
    }
    //cout << "***chickenDist : " << chickenDist << "***\n";

    return chickenDist;

}
int computeMinChickenDist()
{
    int minChickenDist = 4 * n * n;
    vector<int> combinations;

    for(int i = 0; i<chickenRest.size()-m; i++)
        combinations.push_back(0);
    for(int i = 0; i<m; i++)
        combinations.push_back(1);

    do
    {
        vector<pair<int, int>> chickenRestM;
        for(int i = 0; i<combinations.size(); i++)
        {
            if(combinations[i] == 1)
                chickenRestM.push_back(chickenRest[i]);
        }

        int chickenDist = computeChickenDist(chickenRestM);
        if(chickenDist < minChickenDist)
            minChickenDist = chickenDist;

    }while(next_permutation(combinations.begin(), combinations.end()));
    
    return minChickenDist;
}
int main(void)
{
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);
    
    cin >> n >> m;

    city = vector<vector<int>>(n, vector<int>(n, 0));

    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            int num;
            cin >> num;
            if(num == CHICKEN_RESTAURANT)
                chickenRest.push_back(make_pair(i, j));
            else if(num == HOUSE)
                houses.push_back(make_pair(i, j));
            city[i][j] = num;
        }
    }

    cout << computeMinChickenDist();

}