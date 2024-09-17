//240208
//BOJ 14502 연구소
//GOLD 4
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int row, col;
vector<vector<int>> lab;
vector<pair<int, int>> virus;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int computeSafeZone()
{
    queue<pair<int, int>> q;

    vector<vector<bool>> isVisited(row, vector<bool>(col, false));
    vector<vector<bool>> isInfected(row, vector<bool>(col, false));

    for(int i = 0; i<virus.size(); i++)
    {
        q.push(virus[i]);
        isVisited[virus[i].first][virus[i].second] = true;
    }

    while(!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();

        for(int i = 0; i<4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx < 0 || nx >= row || ny <0 || ny >= col) continue;
            if(isVisited[nx][ny] || lab[nx][ny] != 0) continue;

            q.push(make_pair(nx, ny));
            isVisited[nx][ny] = true;
        }
    }

    int result = 0;
    for(int i = 0; i<row; i++)
    {
        for(int j = 0; j<col; j++)
        {
            if(lab[i][j] != 0) continue;
            if(!isVisited[i][j]) result++;
        }
    }

    return result;
    
}
int computeMaxSafeZone()
{
    int maxSafeZone = 0;
    vector<int> combination(row*col, 0);
    combination[row*col - 1] = combination[row*col - 2] = combination[row*col - 3] = 1;

    do
    {
        vector<pair<int, int>> newWall;
        bool canBuildWall = true;
        for(int i = 0; i< row*col; i++)
        {
            if(combination[i] == 0) continue;
            int curRow = i/col;
            int curCol = i%col;

            if(lab[curRow][curCol] != 0)
            {
                canBuildWall = false;
                break;
            }
            else
            {
                lab[curRow][curCol] = 1;
                newWall.push_back(make_pair(curRow, curCol));
            }
        }

        if(canBuildWall)
            maxSafeZone = max(maxSafeZone, computeSafeZone());
        
        for(int i = 0; i<newWall.size(); i++)
            lab[newWall[i].first][newWall[i].second] = 0;

    }while(next_permutation(combination.begin(), combination.end()));
    return maxSafeZone;
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> row >> col;

    lab = vector<vector<int>>(row, vector<int>(col, 0));

    for(int i = 0; i<row; i++)
    {
        for(int j = 0; j<col; j++)
        {
            cin >> lab[i][j];
            if(lab[i][j] == 2)
                virus.push_back(make_pair(i, j));
        }
    }
    
    cout << computeMaxSafeZone();

}