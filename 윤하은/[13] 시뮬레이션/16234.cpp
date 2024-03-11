//240305
//BOJ 16234
//GOLD 4
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, l, r;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1}; 
vector<vector<int>> countries;
void movePopulation(vector<pair<int, int>>& unions, int population)
{
    int newPopulation = population/unions.size();
    for(int i = 0; i<unions.size(); i++)
        countries[unions[i].first][unions[i].second] = newPopulation;
}
int computeMovementDays()
{
    bool movementFlg;
    int days = -1;
    do
    {
        movementFlg = false;
        
        days++;

        vector<vector<bool>> isVisited(n, vector<bool>(n, false));
        queue<pair<int, int>> q;

        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<n; j++)
            {
                if(isVisited[i][j]) continue;
                vector<pair<int, int>> unions;

                q.push({i, j});
                unions.push_back({i, j});
                isVisited[i][j] = true;
                int population = countries[i][j];

                while(!q.empty())
                {
                    pair<int, int> cur = q.front();
                    int curPopulation = countries[cur.first][cur.second];
                    q.pop();

                    for(int k = 0; k<4; k++)
                    {
                        int nx = cur.first + dx[k];
                        int ny = cur.second + dy[k];

                        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                        if(isVisited[nx][ny]) continue;
                        
                        int dif = abs(curPopulation - countries[nx][ny]);
                        if(dif < l || dif > r) continue;
                        
                        q.push({nx, ny});
                        unions.push_back({nx, ny});
                        isVisited[nx][ny] = true;
                        population += countries[nx][ny];
                    }

                }

                if(unions.size() > 1)
                {
                    movementFlg = true;
                    movePopulation(unions, population);
                }
            }
        }

    }while(movementFlg);

    return days;
}
int main(void)
{
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);

    cin >> n >> l >> r;
    countries = vector<vector<int>>(n, vector<int>(n, 0));

    for(int i = 0; i<n; i++)
        for(int j = 0; j<n; j++)
            cin >> countries[i][j];
    
    cout << computeMovementDays();

}