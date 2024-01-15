//BOJ 15683 감시
#include <bits/stdc++.h>
using namespace std;
typedef struct overlap
{

}overlap;
int main(void)
{
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);

    int row, col;
    cin >> row >> col;

    vector<vector<int>> office(row, vector<int>(col,0));
    vector<pair<int, int>> cctvs;

    for(int i = 0; i<row; i++)
    {
        for(int j = 0; j<col; j++)
        {
            int num;
            cin  >> num;
            if(num >= 1 && num <= 5)
                cctvs.push_back({i, j});
            office[i][j] = num;
        } 
    }

    int blindSpot = row * col;
    
    
    int cctvNum = cctvs.size();

    vector<pair<int, int>>

    for(pair<int, int> cur : cctvs)
    {
        int x = cur.first;
        int y = cur.second;
        switch(office[x][y])
        {
            case 1:
                int start = x-1;
                while(start >= 0 && office[start][y] == 0)
                    office[start--][y] = 11;
                start = y+1;
                while(start < col && office[x][start] == 0)
                    office[x][start++] = 12;
                start = x+1;
                while(start < row && office[start][y] == 0)
                    office[start++][y] = 13;
                start = y-1;
                while(start >= 0 && office[x][start] == 0)
                    office[x][start--] = 14;
                break;
            case 2: 
            case 3: 
            case 4:
            case 5:
        }
    }






}