//240417
//BOJ 17779 게리맨더링
//GOLD 3
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<vector<int>> populations;
/*int getMinMaxDiff(int x, int y, int d1, int d2)
{
    vector<int> votePopulations(5, 0);

    for(int r = 1; r<=n; r++)
    {
        for(int c = 1; c<=n; c++)
        {
            int curPopulation = populations[r][c];
            if(r < x + d1 && c <= y)
                votePopulations[0] += curPopulation;
            else if(r <= x+d2 && y < c)
                votePopulations[1] += curPopulation;
            else if(x+d1 <= r && c < y-d1+d2)
                votePopulations[2] += curPopulation;
            else if(x+d2 < r && y-d1+d2<=c)
                votePopulations[3] += curPopulation;
            else 
                votePopulations[4] += curPopulation;
        }
    }
    sort(votePopulations.begin(), votePopulations.end());
    return votePopulations[4] - votePopulations[0];

}*/
bool isGroup5(int x, int y, int d1, int d2, int r, int c)
{
    vector<vector<int>> v(n+1);

    for(int i = 0; i<=d1; i++)
        v[x+i].push_back(y-i);

    for(int i = 1; i<=d2; i++)
        v[x+d1+i].push_back(y-d1+i);
        
    for(int i = 1; i<=d2; i++)
        v[x+i].push_back(y+i);
    
    for(int i = 1; i<=d1; i++)
        v[x+d2+i].push_back(y+d2-i);

    for(int i = 1; i<=n; i++)
    {
        cout << i << " row's borderline\n";
        for(int j = 0; j<v[i].size(); j++)
            cout << v[i][j] << " ";
        cout << "\n";
    }
    int size = v[r].size();
    if(size == 0) return false;
    else if(size == 1)
    {
        if(v[r][0] == c) return true;
        else false;
    }
    else//size == 2
    {
        if(v[r][0] <= c && c <= v[r][1]) return true;
        else false;
    }
}
int getMinMaxDiff(int x, int y, int d1, int d2)
{
    vector<int> votePopulations(5, 0);

    for(int r = 1; r<=n; r++)
    {
        for(int c = 1; c<=n; c++)
        {
            int idx = 0;
            if(isGroup5(x, y, d1, d2, r, c))
                idx = 4;
            else if(r < x + d1 && c <= y)
                idx = 0;
            else if(r <= x+d2 && y < c)
                idx = 1;
            else if(x+d1 <= r && c < y-d1+d2)
                idx = 2;
            else idx = 3;
            votePopulations[idx] += populations[r][c];
            cout << idx+1 << " ";
        }
        cout << "\n";
    }
    sort(votePopulations.begin(), votePopulations.end());
    return votePopulations[4] - votePopulations[0];

}
int solution()
{
    int minDiff = 0x7fffffff;
    for(int x = 1; x<= n; x++)
    {
        for(int d1 = 1; d1<=n; d1++)
        {
            for(int d2 = 1; d2<=n; d2++)
            {
                if(x+d1+d2 > n) continue;
                for(int y = d1+1; y<= n-d2; y++)
                {
                    printf("x : %d, y : %d, d1 : %d, d2 : %d\n", x, y, d1, d2);
                    minDiff = min(minDiff, getMinMaxDiff(x, y, d1, d2));
                }
            }
            
        }
    }
    return minDiff;
}
int main(void)
{
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);
    
    cin >> n;
    populations = vector<vector<int>>(n+1, vector<int>(n+1));

    for(int i = 1; i<=n; i++)
        for(int j = 1; j<=n; j++)
            cin >> populations[i][j];

    cout << solution();

}