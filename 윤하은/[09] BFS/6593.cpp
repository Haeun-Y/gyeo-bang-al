//240102
//BOJ 6593 상범 빌딩
//GOLD 5
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef struct pos{
    int floor;
    int row;
    int col;
    int curMin;

    //constructor
    pos() 
    {
        floor = 0;
        row = 0;
        col = 0; 
        curMin = 0;
    }
    pos(int f, int r, int c, int cm) : floor(f), row(r), col(c), curMin(cm) {}
}pos;

int df[6] = {0, 0, 0, 0, 1, -1};
int dr[6] = {-1, 1, 0, 0, 0, 0};
int dc[6] = {0, 0, -1, 1, 0, 0};
vector<vector<vector<bool>>> building;
vector<vector<vector<bool>>> isVisited;
pos startPos = pos();
pos exitPos = pos();

int findExit(int& l, int& r, int& c)
{
    queue<pos> q;
    q.push(startPos);
    isVisited[startPos.floor][startPos.row][startPos.col] = true;

    while(!q.empty())
    {
        pos cur = q.front();
        q.pop();

        for(int i = 0; i<6; i++)
        {
            int nf = cur.floor + df[i];
            int nr = cur.row + dr[i];
            int nc = cur.col + dc[i];
            int nmin = cur.curMin + 1;

            //outOfIndex
            if(nf < 0 || nf >= l || nr < 0 || nr >= r || nc < 0 || nc >= c) continue;
            //already visited or gold block
            if(isVisited[nf][nr][nc] || !building[nf][nr][nc]) continue;

            //find exit
            if(nf == exitPos.floor && nr == exitPos.row && nc == exitPos.col)
                return nmin;

            q.push(pos(nf, nr, nc, nmin));
            isVisited[nf][nr][nc] = true;
        }
        
    }

    return -1;
}
void printVec3(vector<vector<vector<bool>>>& building)
{
    for(int i = 0; i<building.size(); i++)
    {
        for(int j = 0; j<building[0].size(); j++)
        {
            for(int k = 0; k<building[0][0].size(); k++)
            {
                if(building[i][j][k]) cout << ".";
                else cout << "#";
            }
            cout << "\n";
        }
        cout << "\n\n";
    }
}
int main(void)
{
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);

    while(1)
    {
        int l, r, c;
        cin >> l >> r >> c;

        if(l == 0 && r == 0 && c == 0) break;
        
        building = vector<vector<vector<bool>>>(l, vector<vector<bool>>(r, vector<bool>(c, false)));
        isVisited = vector<vector<vector<bool>>>(l, vector<vector<bool>>(r, vector<bool>(c, false)));

        for(int i = 0; i<l; i++)
        {
            for(int j = 0; j<r; j++)
            {
                for(int k = 0; k<c; k++)
                {
                    char ch;
                    cin >> ch;
                    
                    if(ch != '#')
                    {
                        building[i][j][k] = true;
                        if(ch == 'S')
                        {
                            startPos.floor = i;
                            startPos.row = j;
                            startPos.col = k;
                            startPos.curMin = 0;
                        }
                        else if(ch == 'E')
                        {
                            exitPos.floor = i;
                            exitPos.row = j;
                            exitPos.col = k;
                            exitPos.curMin = 0;
                        }
                    }
                    
                    
                }
            }
        }

        int shortestMin = findExit(l, r, c);

        if(shortestMin < 0)
            cout << "Trapped!\n";
        else cout << "Escaped in " << shortestMin <<" minute(s).\n";
        
    }


}