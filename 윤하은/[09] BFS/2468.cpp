//240101
//BOJ 2468 안전 영역
//SILVER 1
#include <iostream>
#include <queue>
using namespace std;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int area[102][102];
int findSafeZone(int& n, int& x)//the area is unsafe where x >= height
{
    int safeZoneNum = 0;
    bool isVisited[102][102] = {false, };

    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            //already visited or unsafe
            if(isVisited[i][j] || area[i][j] <= x) continue;
            queue<pair<int, int>> q;

            q.push(make_pair(i, j));
            isVisited[i][j] = true;
            safeZoneNum++;

            while(!q.empty())
            {
                pair<int, int> cur = q.front();
                q.pop();

                for(int k = 0; k<4; k++)
                {
                    int nx = dx[k] + cur.first;
                    int ny = dy[k] + cur.second;

                    //outOfIndex
                    if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    //already visited or unsafe
                    if(isVisited[nx][ny] || area[nx][ny] <= x) continue;

                    q.push(make_pair(nx, ny));
                    isVisited[nx][ny] = true;
                }

            }
            
        }
    }

    return safeZoneNum;


}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int maxHeight = 0;
    int minHeight = 101;

    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            cin >> area[i][j];
            if(area[i][j] > maxHeight)
                maxHeight = area[i][j];
            if(area[i][j] < minHeight)
                minHeight = area[i][j];
        }
    }

    int maxSafeZoneNum = 0;

    for(int i = minHeight-1; i<maxHeight; i++)
    {
        int safeZoneNum = findSafeZone(n, i);
        if(maxSafeZoneNum < safeZoneNum)
            maxSafeZoneNum = safeZoneNum;
    }

    cout << maxSafeZoneNum;
}