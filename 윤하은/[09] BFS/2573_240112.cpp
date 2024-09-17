//240112
//BOJ 2573 빙산
//GOLD 4
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1}; 
int row, col;
vector<vector<int>> iceberg;
vector<vector<int>> icebergLater;
void printIceberg()
{
    cout << "***************\n";
    for(int i = 0; i<row; i++)
    {
        for(int j= 0; j<col; j++)
            cout << iceberg[i][j] << " ";
        cout << "\n";
    }
}
bool yearLater(int& year)
{
    int isAllMelted = true;
    //check the melted part of iceberg
    for(int i = 1; i<row-1; i++)
    {
        for(int j = 1; j<col-1; j++)
        {
            if(iceberg[i][j] == 0) continue;
            int waterNum = 0;
            for(int k = 0; k<4; k++)
            {
                int nx = i + dx[k];
                int ny = j + dy[k];

                if(nx < 0 || nx >= row || ny < 0 || ny >= col) continue;
                if(iceberg[nx][ny] == 0) waterNum++;
            }
            int tmp = iceberg[i][j] - waterNum;
            icebergLater[i][j] = (tmp < 0)? 0 : tmp;
            if(icebergLater[i][j] != 0)
                isAllMelted = false;
        }
    }
    iceberg = icebergLater;
    year++;
    //printIceberg();
    return isAllMelted;
}
int bfs()
{
    vector<vector<bool>> isVisited(row, vector<bool>(col, false));
    int areaNum = 0;
    queue<pair<int, int>> q;

    //check the areaNum
    for(int i = 0; i<row; i++)
    {
        for(int j = 0; j<col; j++)
        {
            if(iceberg[i][j] == 0 || isVisited[i][j]) continue;
            
            areaNum++;
            q.push(make_pair(i, j));
            isVisited[i][j] = true;

            while(!q.empty())
            {
                pair<int, int> cur = q.front();
                q.pop();

                for(int k = 0; k<4; k++)
                {
                    int nx = cur.first + dx[k];
                    int ny = cur.second + dy[k];

                    if(nx < 0 || nx >= row || ny < 0 || ny >= col) continue;
                    if(iceberg[nx][ny] == 0 || isVisited[nx][ny]) continue;

                    q.push(make_pair(nx, ny));
                    isVisited[nx][ny] = true;
                }
            }

        }
    }

    return areaNum;
}
int meltIceberg()
{
    int year = 0;
    while(!yearLater(year))
    {
        if(bfs() >= 2)
            return year;
    }
    return 0;
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> row >> col;
    iceberg = vector<vector<int>>(row, vector<int>(col, 0));
    icebergLater = vector<vector<int>>(row, vector<int>(col, 0));
    
    for(int i = 0; i<row; i++)
    {
        for(int j = 0; j<col; j++)
            cin >> iceberg[i][j];
    }

    cout << meltIceberg();


}