//BOJ 1780 종이의 개수
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> v;
int nums[3] = {0, 0, 0};
int isSame(int n, pair<int, int> start)
{
    int x = start.first;
    int y = start.second;
    int num = v[x][y];
    
    for(int i = x; i<x+n; i++)
    {
        for(int j = y; j<y+n; j++)
        {
            if(v[i][j] != num)
                return -2;
        }
    }
    return num;

}
void cutPaper(int n, pair<int, int> start)
{
    int num = isSame(n, start);
    
    if(num != -2)
    {
        nums[num+1]++;
        return;
    }
    else
    {
        int x = start.first;
        int y = start.second;

        for(int i =0; i<n; i+=(n/3))
        {
            for(int j= 0; j<n; j+=(n/3))
            {
                //cout << "n : " << n << "\t" << "call cutPaper(" << n/3 << ", {" << x+i << ", " << y+j << "})\n";
                cutPaper(n/3, {x+i, y+j});

            }
                
        }
    }

}
int main(void)
{
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);

    int n;
    cin >> n;

    for(int i = 0; i<n; i++)
    {
        vector<int> tmp(n, 0);
        v.push_back(tmp);
    }

    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
            cin >> v[i][j];
    }

    cutPaper(n, {0, 0});
    cout << nums[0] << "\n" << nums[1] << "\n" << num[2];

}
