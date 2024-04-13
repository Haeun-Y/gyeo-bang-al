//240413
//BOJ 17144 미세먼지 안녕!
//GOLD 4
#include <iostream>
#include <vector>
using namespace std;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int r, c, t;
vector<vector<int>> room;
vector<pair<int, int>> airCleaner;
void diffuse()
{
    vector<vector<int>> diffResult(r, vector<int>(c, 0));

    for(int i = 0; i<r; i++)
    {
        for(int j = 0; j<c; j++)
        {
            int diffNum = 0;
            if(room[i][j] <= 0) continue;
            int diffAmt = room[i][j]/5;
            for(int k = 0; k<4; k++)
            {
                int nx = i + dx[k];
                int ny = j + dy[k];

                if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
                if(room[nx][ny] == -1) continue;

                diffNum++;
                diffResult[nx][ny] += diffAmt;
            }
            diffResult[i][j] -= (diffAmt * diffNum);
        }
    }

    //diffuse 반영
    for(int i = 0; i<r; i++)
        for(int j = 0; j<c; j++)
            room[i][j] += diffResult[i][j];

}
void airClean()
{
    //위쪽 방향

    for(int i = airCleaner[0].first-1; i>0; i--)
        room[i][0] = room[i-1][0];
    
    for(int i = 0; i<c-1; i++)
        room[0][i] = room[0][i+1];
    
    for(int i = 0; i<airCleaner[0].first; i++)
        room[i][c-1] = room[i+1][c-1];

    for(int i = c-1; i>1; i--)
        room[airCleaner[0].first][i] = room[airCleaner[0].first][i-1];


    //아래쪽 방향

    for(int i = airCleaner[1].first+1; i<r-1; i++)
        room[i][0] = room[i+1][0];
    
    for(int i = 0; i<c-1; i++)
        room[r-1][i] = room[r-1][i+1];
    
    for(int i = r-1; i > airCleaner[1].first; i--)
        room[i][c-1] = room[i-1][c-1];

    for(int i = c-1; i>1; i--)
        room[airCleaner[1].first][i] = room[airCleaner[1].first][i-1];
    
    room[airCleaner[0].first][1] = 0;
    room[airCleaner[1].first][1] = 0;

}
int solution()
{
    for(int i = 0; i<t; i++)
    {
        diffuse();
        airClean();
    }

    int answer = 0;

    for(int i = 0; i<r; i++)
    {
        for(int j = 0; j<c; j++)
        {
            if(room[i][j] == -1) continue;
            answer += room[i][j];
        }

    }
    return answer;

}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> r >> c >> t;
    room = vector<vector<int>>(r, vector<int>(c, 0));

    for(int i = 0; i<r; i++)
    {
        for(int j = 0; j<c; j++)
        {
            cin >> room[i][j];
            if(room[i][j] == -1)
                airCleaner.push_back({i,j});
        }
    }

    cout << solution();

}