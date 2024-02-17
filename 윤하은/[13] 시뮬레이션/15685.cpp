//240217
//BOJ 15685 드래곤 커브
//GOLD 3
#include <iostream>
#include <vector>
using namespace std;
typedef struct
{
    pair<int, int> start;
    pair<int, int> end;
    int direction;

}dragon;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1}; 
vector<vector<bool>> dragonCurve;
void findDragonCurve(vector<dragon>& v)
{
    int size = v.size();

    for(int i = size-1; i>= 0; i--)
    {
        dragon cur;
        cur.start = v[i].end;
        if(v[i].direction%2 == 0)
            cur.direction = v[i].direction + 1;
        else cur.direction = v[i].direction - 1;
        cur.end.first = cur.start.first + dx[cur.direction];
        cur.end.second = cur.start.second + dy[cur.direction];
        v.push_back(cur);
        dragonCurve[cur.start.first][cur.start.first] = dragonCurve[cur.end.first][cur.end.first] = true;
    }

}
int findDragonSquare()
{
    int cnt = 0;

    for(int i = 0; i<100; i++)
    {
        for(int j = 0; j<100; j++)
        {
            pair<int, int> cur = make_pair(i, j);

            int sx[4] = {0, 0, 1, 1};
            int sy[4] = {0, 1, 0, 1}; 
            int isDragonSquare = true;

            for(int k = 0; k<4; k++)
            {
                int nx = cur.first + sx[k];
                int ny = cur.second + sy[k];

                if(dragonCurve[nx][ny])
                {
                    isDragonSquare = false;
                    break;
                }
            }
            if(isDragonSquare) cnt++;
        }
    }

    return cnt;

}
int main(void)
{
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);

    int dragonCurveNum;
    cin >> dragonCurveNum;

    dragonCurve = vector<vector<bool>>(105, vector<bool>(105, false));

    for(int i = 0; i<dragonCurveNum; i++)
    {
        dragon cur;
        int g;
        cin >> cur.start.first >> cur.start.second >> cur.direction >> g;
        
        cur.end.first = cur.start.first + dx[cur.direction];
        cur.end.second = cur.start.second + dy[cur.direction];
        dragonCurve[cur.start.first][cur.start.second] = dragonCurve[cur.end.first][cur.end.second] = true;

        vector<dragon> v;
        v.push_back(cur);

        for(int j = 1; j<= g; j++)
            findDragonCurve(v);
    }

    cout << findDragonSquare();




}