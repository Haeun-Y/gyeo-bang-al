//240211
//BOJ 14890 경사로
//GOLD 3
#include <iostream>
#include <vector>
using namespace std;
int n, l;
vector<vector<int>> land;
bool isPassableRoadRow(int row)
{
    int beforeHeight = land[row][0];
    int beforeNum = 1;
    for(int i = 1; i<n; i++)
    {
        int curHeight = land[row][i];
        int difference = curHeight - beforeHeight;
        if(abs(difference) > 1) return false;
        else if(difference == 0) beforeNum++;
        else if(difference == 1)
        {
            if(beforeNum < l) return false;
            beforeNum = 1;
        }
        else//difference == -1
        {
            beforeNum = 1;
            while(++i<n && land[row][i] == curHeight && beforeNum < l) beforeNum++;
            if(beforeNum < l) return false;
            i--;
            beforeNum = 0;
        }
        beforeHeight = curHeight;
    }
    return true;

}
bool isPassableRoadCol(int col)
{
    int beforeHeight = land[0][col];
    int beforeNum = 1;
    for(int i = 1; i<n; i++)
    {
        int curHeight = land[i][col];
        int difference = curHeight - beforeHeight;
        if(abs(difference) > 1) return false;
        else if(difference == 0) beforeNum++;
        else if(difference == 1)
        {
            if(beforeNum < l) return false;
            beforeNum = 1;
        }
        else//difference == -1
        {
            beforeNum = 1;
            while(++i<n && land[i][col] == curHeight && beforeNum < l) beforeNum++;
            if(beforeNum < l) return false;
            i--;
            beforeNum = 0;
        }
        beforeHeight = curHeight;
    }
    return true;

}
int findRoute()
{
    int cnt = 0;
    for(int i = 0; i<n; i++)
    {
        if(isPassableRoadRow(i)) cnt++;
        if(isPassableRoadCol(i)) cnt++;
        
    }
    return cnt;
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> l;
    land = vector<vector<int>>(n, vector<int>(n, 0));

    for(int i = 0; i<n; i++)
        for(int j = 0; j<n; j++)
            cin >> land[i][j];

    cout << findRoute();

}