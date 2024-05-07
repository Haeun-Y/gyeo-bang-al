//240424
//BOJ 19236 청소년 상어
//SILVER 2
#include <iostream>
#include <vector>
using namespace std;
const int row = 4;
const int col = 4;
vector<vector<pair<int, int>>> fish;
vector<pair<int, int>> fishPos;
typedef struct shark
{
    int x;
    int y;
    int dir;
}shark;
int maxSum;
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};
bool isMovable(vector<vector<pair<int, int>>>& f, pair<int, int> pos, int dir)
{   
    int nx = pos.first + dx[dir];
    int ny = pos.second + dy[dir];

    if(nx < 0 || nx >= row || ny < 0 || ny >= col) return false;
    if(f[nx][ny].first == 0) return false;
    return true;

}
void swapFish(vector<vector<pair<int, int>>>& f, vector<pair<int, int>>& fp, int num1, int num2)
{
    pair<int, int> tmp = f[fp[num1].first][fp[num1].second];
    f[fp[num1].first][fp[num1].second] = f[fp[num2].first][fp[num2].second];
    f[fp[num2].first][fp[num2].second] = tmp;

    tmp = fp[num1];
    fp[num1] = fp[num2];
    fp[num2] = tmp;

}
void solution(shark teen, pair<int, int> targetPos, int sum, vector<vector<pair<int, int>>> f, vector<pair<int, int>> fp)
{
    if(targetPos.first == -1 && targetPos.second == -1)
    {
        maxSum = max(maxSum, sum);
        return;
    }
    else
    {
        //상어가 물고기 먹음
        pair<int, int> target = f[targetPos.first][targetPos.second];
        teen = {targetPos.first, targetPos.second, target.second};
        sum += target.second;
        f[targetPos.first][targetPos.second].first = 0;//상어

        //물고기 이동
        for(int i = 1; i<=16; i++)
        {
            pair<int, int> pos = {fp[i].first, fp[i].second};
            pair<int, int> cur = f[pos.first][pos.second];
            while(!isMovable(f, pos, cur.second))
                cur.second++;
            f[pos.first][pos.second].second = cur.second;
            swapFish(f, fp, i, f[pos.first+dx[cur.second]][pos.second+dy[cur.second]].first);
        }

        int xDiff = dx[teen.dir];
        int yDiff = dy[teen.dir]; 

        bool flg = false;

        int nx = teen.x + xDiff;
        int ny = teen.y + yDiff;

        while(1)
        {
            if(nx < 0 || nx >= row || ny < 0 || ny >= col) break;

            flg = true;
            solution(teen, {nx, ny}, sum, f, fp);
            nx += xDiff;
            ny += yDiff;
        }

        if(!flg) solution(teen, {-1, -1}, sum, f, fp);


    }


}
int main(void)
{
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);

    fish = vector<vector<pair<int, int>>>(row, vector<pair<int ,int>>(col, {0, 0}));
    fishPos = vector<pair<int, int>>(row*col+1);
    for(int i = 0; i<row; i++)
    {
        for(int j = 0; j<col; j++)
        {
            int num, dir;
            cin >> num >> dir;
            fish[i][j] = {num, dir-1};
            fishPos[num] = {i, j};
        }

    }
    cout << maxSum;

}