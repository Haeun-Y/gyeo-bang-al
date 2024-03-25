//240323
//BOJ 16236 아기 상어
//GOLD 3
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n;
vector<vector<int>> sea;
typedef struct
{
    bool isEatable;
    int size;
    pair<int, int> pos;
    int dist;
    
}fish;
typedef struct
{
    int fishNum;
    int size;
    pair<int ,int> pos;
}shark;
vector<fish> fishes;
shark baby;
int computeEatableFishNum()
{
    int result = 0;
    //cout << "***computeEatableFishNum***\n";
    for(int i = 0; i<fishes.size(); i++)
    {
        if(fishes[i].isEatable)
        {
            result++;
            //cout << "pos : (" << fishes[i].pos.first << ", " << fishes[i].pos.second << ")\ndist :" << fishes[i].dist <<"\n";
        }
    }
    //cout << "***computeEatableFishNum***\n\n";

    
    return result;
}
void computeDist()
{
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    vector<vector<int>> isVisited;
    for(int i = 0; i<fishes.size(); i++)
    {
        if(fishes[i].size >= baby.size) continue;
        //cout << "compute dist between shark and (" << fishes[i].pos.first << ", " << fishes[i].pos.second << ")\n"; 
        int dist = -1;
        isVisited = vector<vector<int>>(n, vector<int>(n, -1));
        pair<int, int> destination = fishes[i].pos;
        queue<pair<int, int>> q;
        
        q.push(baby.pos);
        isVisited[baby.pos.first][baby.pos.second] = 0;
        
        bool flg = false;
        while(!q.empty() && !flg)
        {
            pair<int, int> cur = q.front();
            q.pop();
            
            for(int i = 0; i<4; i++)
            {
                int nx = cur.first + dx[i];
                int ny = cur.second + dy[i];
                
                if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if(isVisited[nx][ny] != -1 || sea[nx][ny] > baby.size) continue;
            
                q.push({nx, ny});
                isVisited[nx][ny] = isVisited[cur.first][cur.second] + 1;
                
                if(nx == destination.first && ny == destination.second)
                {
                    dist = isVisited[nx][ny];
                    flg = true;
                    break;
                }
            }
        }
        if(dist > 0)
        {
            fishes[i].isEatable = true;
            fishes[i].dist = dist;
        }
    }
}
bool cmp(fish a, fish b)
{
    if(a.isEatable == b.isEatable)
    {
        if(a.dist == b.dist)
        {
            if(a.pos.first == b.pos.first)
                return a.pos.second < b.pos.second;
            else return a.pos.first < b.pos.first;
        }
        else return a.dist < b.dist;
    }
    else return a.isEatable > b.isEatable;
}
int computeSharkTime()
{
    int result = 0;
    int eatableFishNum = 0;
    while(1)
    {
        computeDist();
        if(computeEatableFishNum() <= 0) break;
        sort(fishes.begin(), fishes.end(), cmp);
        
        fish cur = fishes[0];
        fishes.erase(fishes.begin());
        result += cur.dist;
        sea[baby.pos.first][baby.pos.second] = 0;
        baby.pos = cur.pos;
        sea[baby.pos.first][baby.pos.second] = 9;
        baby.fishNum++;
        if(baby.fishNum == baby.size)
        {
            baby.size++;
            baby.fishNum = 0;
        }
    }
    return result;
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    sea = vector<vector<int>>(n, vector<int>(n, 0));
    
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            cin >> sea[i][j];
            if(sea[i][j] == 9)
            {
                baby.fishNum = 0;
                baby.size = 2;
                baby.pos = {i, j};
            }
            else if(1 <= sea[i][j] && sea[i][j] <= 6)
            {
                fish f;
                f.isEatable = false;
                f.size = sea[i][j];
                f.pos = {i, j};
                f.dist = -1;
                fishes.push_back(f);
            }
        }
    }
    
    cout << computeSharkTime() << "\n";

    
}