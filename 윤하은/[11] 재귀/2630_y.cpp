#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> paper;
int result[2] = {0, 0};
int isSameColor(int n, pair<int, int> start)
{
    int x = start.first;
    int y = start.second;

    int color = paper[x][y];

    for(int i = x; i<x+n; i++)
    {
        for(int j = y; j<y+n; j++)
        {
            if(paper[i][j] != color)
                return -1;
        }
    }

    return color;

}
void cutPaper(int n, pair<int, int> start)
{
    int color = isSameColor(n, start);

    if(color != -1)//색이 같을 때
    {
        result[color]++;
        return;
    }

    else
    {
        int x = start.first;
        int y = start.second;
        int num = n/2;

        cutPaper(num, start);
        cutPaper(num, {x, y+num});
        cutPaper(num, {x+num, y});
        cutPaper(num, {x+num, y+num});
    }

}
int main(void)
{
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);

    int n;
    cin >> n;

    paper = vector<vector<int>>(n, vector<int>(n));
    
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
            cin >> paper[i][j];
    }
    
    cutPaper(n, {0,0});

    cout << result[0] << "\n" << result[1];


    
    

}