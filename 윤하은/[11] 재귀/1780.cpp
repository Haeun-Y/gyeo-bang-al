//BOJ 1780 종이의 개수
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> v;
int nums[3] = {0, 0, 0};
int isSameNum(int n, pair<int, int> start)
{
    int num = v[start.first][start.second];
    
    for(int i = 0; i<n; i++)
    {
        for(int j = 0 ;j<n; j++)
        {
            if(v[i][j] != num)
                return -2;
        }
    }
    return num;

}
void cutPaper(int n, pair<int, int> start)
{
    int num = isSameNum(n, start);
    //종이가 모두 같은수로 되어있음
    if(num != -2)
    {
        cout << "start : " << "(" << start.first << ", " << start.second << ")\tisSameNum : " << num << "\n";
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
                cout << "call cutPaper(" << n/3 << ", {" << x+i << ", " << y+j << "})\n";
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

    cutPaper(9, {0, 0});
    cout << nums[0] << "\n";
    cout << nums[1] << "\n";
    cout << nums[2]; 


}