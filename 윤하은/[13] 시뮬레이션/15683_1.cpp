//240119
//BOJ 15683 감시
//GOLD 4
#include <iostream>
#include <vector>
using namespace std;
typedef struct
{
    int row;
    int col;
    int cctvNum;
}cctv;
vector<cctv> cctvs;
vector<vector<int>> office;
int n, m;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
void monitor(vector<vector<int>>& office2, pair<int, int> cctvPos, int dirIdx)
{
    dirIdx %= 4;
    int nx = cctvPos.first + dx[dirIdx];
    int ny = cctvPos.second + dy[dirIdx];

    for(; nx >= 0 && nx < n && ny >= 0 && ny < m; nx += dx[dirIdx], ny += dy[dirIdx])
    {
        if(office2[nx][ny] == 6) break;
        if(office2[nx][ny] >= 1 && office2[nx][ny] <= 5) continue;
        
        office2[nx][ny] = 7;
    }
}
void printOffice(vector<vector<int>>& v)
{
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            if(v[i][j] == 7)
                cout << "#";
            else cout << v[i][j];
        }
        cout << "\n";
    }
    cout << "\n";
}
int computeBlindSpotNum(vector<int>& dir)
{
    vector<vector<int>> office2 = office;
    
    for(int i = 0; i<dir.size(); i++)
    {
        int curCCTVNum = cctvs[i].cctvNum;
        if(curCCTVNum == 1)
            monitor(office2, make_pair(cctvs[i].row, cctvs[i].col), dir[i]);
        
        else if(curCCTVNum == 2)
        {
            monitor(office2, make_pair(cctvs[i].row, cctvs[i].col), dir[i]);
            monitor(office2, make_pair(cctvs[i].row, cctvs[i].col), dir[i]+2);
        }
        else if(curCCTVNum == 3)
        {
            monitor(office2, make_pair(cctvs[i].row, cctvs[i].col), dir[i]);
            monitor(office2, make_pair(cctvs[i].row, cctvs[i].col), dir[i]+1);
        }
        else if(curCCTVNum == 4)
        {
            monitor(office2, make_pair(cctvs[i].row, cctvs[i].col), dir[i]);
            monitor(office2, make_pair(cctvs[i].row, cctvs[i].col), dir[i]+1);
            monitor(office2, make_pair(cctvs[i].row, cctvs[i].col), dir[i]+2);
        }
        else//curCCTVNum == 5
        {
            monitor(office2, make_pair(cctvs[i].row, cctvs[i].col), dir[i]);
            monitor(office2, make_pair(cctvs[i].row, cctvs[i].col), dir[i]+1);
            monitor(office2, make_pair(cctvs[i].row, cctvs[i].col), dir[i]+2);
            monitor(office2, make_pair(cctvs[i].row, cctvs[i].col), dir[i]+3);
        }
        //printOffice(office2);
    }
    
    int blindSpotNum = 0;
    for(int i = 0; i<n; i++)
        for(int j = 0; j<m; j++)
            if(office2[i][j] == 0) blindSpotNum++;
    
    //cout << "blindSpotNum : " << blindSpotNum << "\n\n"; 
    return blindSpotNum;
    
}
int computeMinBlindSpotNum()
{
    int minBlindSpotNum = n * m;
    int total = 1;
    for(int i = 0; i< cctvs.size(); i++)
        total *= 4;
    
    for(int i = 0; i<total; i++)
    {
        int num = i;
        vector<int> cctvDir;
        for(int j = 0; j<cctvs.size(); j++)
        {
            cctvDir.push_back(num%4);
            num /= 4;
        }
        minBlindSpotNum = min(minBlindSpotNum, computeBlindSpotNum(cctvDir));
    }
    
    return minBlindSpotNum;
    
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    office = vector<vector<int>>(n, vector<int>(m, 0));

    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            int num;
            cin >> num;
            if(num >= 1 && num <= 5)//cctv
            {
                cctv cur = {i, j, num};
                cctvs.push_back(cur);
            }
            office[i][j] = num;
        }
    }
    
    cout << computeMinBlindSpotNum();

}