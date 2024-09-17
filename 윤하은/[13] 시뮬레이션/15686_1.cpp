//240201
//BOJ 15686 치킨 배달
//GOLD 5
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int n, m;
vector<pair<int, int>> chickenRest;
vector<pair<int, int>> houses;
const int CHICKEN_RESTAURANT = 2;
const int HOUSE = 1;
int computeMinChickenDist()
{
    int minDist = 4 * n * n;
    vector<int> combinations;

    for(int i = 0; i<chickenRest.size()-m; i++)
        combinations.push_back(0);
    for(int i = 0; i<m; i++)
        combinations.push_back(1);

    do
    {
        vector<vector<int>> dist(n, vector<int>(n, 2 * n));
        int curDist = 0;
        for(int i = 0; i<combinations.size(); i++)
        {
            if(combinations[i] == 0) continue;

            pair<int, int> curChicken = chickenRest[i];

            for(int j = 0; j<houses.size(); j++)
            {
                pair<int, int> curHouse = houses[j];
                dist[curHouse.first][curHouse.second] 
                = min(dist[curHouse.first][curHouse.second], abs(curChicken.first - curHouse.first) + abs(curChicken.second - curHouse.second));
                //cout << "dist[" << curHouse.first << "][" << curHouse.second << "] : " << dist[curHouse.first][curHouse.second] << "\n";
            }
        }

        for(int i = 0; i<houses.size(); i++)
            curDist += dist[houses[i].first][houses[i].second];
        
        //cout << "curDist : " << curDist << "\n";

        minDist = min(minDist, curDist);

    }while(next_permutation(combinations.begin(), combinations.end()));
    
    return minDist;
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;

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
        }
    }

    cout << computeMinChickenDist();

}