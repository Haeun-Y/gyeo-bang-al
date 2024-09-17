//240213
//BOJ 15684 사다리조작
//GOLD 3
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, h;
vector<vector<bool>> ladder;
vector<vector<bool>> ladder2;
bool isManipulationSuccessed()
{
    for(int i = 0; i<n; i++)
    {
        int curPosV = i;
        int curPosH = 0;
        while(curPosH < h)
        {
            for(int j = curPosH; j<h; j++)
            {
                if(ladder2[j][curPosV])
                {
                    curPosV++;
                    curPosH++;
                    break;
                }
            }
        }
        if(curPosV != i) return false;
    }

    return true;

}
int computeMinHorizontal()
{
    int maxHorizontal = (n-1) * h;
    for(int i = 0; i<4; i++)
    {
        vector<int> v(maxHorizontal, 0);
        int idx = maxHorizontal-1;
        for(int j = 0; j<i; j++)
            v[idx--] = 1;
        do 
        {
            ladder2 = ladder;
            for(int j = 0; j<maxHorizontal; j++)
                if(v[j] == 1)
                    ladder2[j/(n-1)][j%(n-1)] = true;
            if(isManipulationSuccessed())
                return i;
        }while(next_permutation(v.begin(), v.end()));
    }
    return -1;

}
int main(void)
{
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);

    cin >> n >> m >> h;
    ladder = vector<vector<bool>>(h, vector<bool>(n, false));

    for(int i = 0; i<m; i++)
    {
        int a, b;
        cin >> a >> b;
        ladder[a-1][b-1] = true;
    }

    cout << computeMinHorizontal();

}