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
typedef struct
{
    bool up;
    bool right;
    bool down;
    bool left;
}direction;
vector<cctv> cctvs;
vector<vector<direction>> cctvDir;
vector<vector<int>> office;
int n, m, minBlindSpotNum;
void printCCTVDir()
{
    for(int i = 1; i<cctvDir.size(); i++)
    {
        cout << "cctvNum : " << i << "\n";
        for(int j = 0; j<cctvDir[i].size(); j++)
        {
            direction cur = cctvDir[i][j];
            if(cur.up)
                cout << "up ";
            if(cur.right)
                cout << "right ";
            if(cur.down)
                cout << "down ";
            if(cur.left)
                cout << "left ";
        
            cout << "\n";
        }
        cout << "************\n";
    }
}
void setCCTVDir()
{
    //dummy
    vector<direction> cctv0 = vector<direction>(1, {false, false, false, false});
    cctvDir.push_back(cctv0);
    
    vector<direction> cctv1;
    cctv1.push_back({true, false, false, false});//up
    cctv1.push_back({false, true, false, false});//right
    cctv1.push_back({false, false, true, false});//down
    cctv1.push_back({false, false, false, true});//left
    cctvDir.push_back(cctv1);

    vector<direction> cctv2;
    cctv2.push_back({true, false, true, false});//up down
    cctv2.push_back({false, true, false, true});//right left
    cctvDir.push_back(cctv2);

    vector<direction> cctv3;
    cctv3.push_back({true, true, false, false});//up right
    cctv3.push_back({false, true, true, false});//right down
    cctv3.push_back({false, false, true, true});//down left
    cctv3.push_back({true, false, false, true});//left up
    cctvDir.push_back(cctv3);

    vector<direction> cctv4;
    cctv4.push_back({true, true, true, false});//up right down
    cctv4.push_back({false, true, true, true});//right down left
    cctv4.push_back({true, false, true, true});//down left up
    cctv4.push_back({true, true, false, true});//left up right
    cctvDir.push_back(cctv4);

    vector<direction> cctv5;
    cctv5.push_back({true, true, true, true});//up right down left
    cctvDir.push_back(cctv5);

}
int computeBlindSpot()
{
    int cnt = 0;
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            if(office[i][j] == 0)
                cnt++;
        }
    }
    return cnt;
}
void printOffice()
{
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            if(office[i][j] < 0)
                cout << "#";
            else cout << office[i][j];
            cout << " ";
        }
        cout << "\n";
    }
}
void monitor(direction dir, cctv cctvPos, int idx, bool flg)
{
    
    int target = (flg)?0:-idx;
    int num = (flg)?-idx:0;
    
    //cout << idx << "th CCTV : (" << cctvPos.row << ", " << cctvPos.col << ")\n";
    //cout << ((flg)?"...monitor...\n":"...ignore...\n");
    if(dir.up)
    {
        //cout << "up ";
        for(int i=cctvPos.row-1; i>=0; i--)
        {
            if(office[i][cctvPos.col] == 6) break;
            if(office[i][cctvPos.col] == target)
                office[i][cctvPos.col] = num;
        }
        
    }
    
    if(dir.right)
    {
        //cout << "right ";
        for(int i = cctvPos.col+1; i<m; i++)
        {
            if(office[cctvPos.row][i] == 6) break;
            if(office[cctvPos.row][i] == target)
                office[cctvPos.row][i] = num;
        }
        
    }
    
    if(dir.down)
    {
        //cout << "down ";
        for(int i = cctvPos.row+1; i<n; i++)
        {
            if(office[i][cctvPos.col] == 6) break;
            if(office[i][cctvPos.col] == target)
                office[i][cctvPos.col] = num;
        }
        
    }
    
    if(dir.left)
    {
        //cout << "left ";
        for(int i = cctvPos.col-1; i>=0; i--)
        {
            if(office[cctvPos.row][i] == 6) break;
            if(office[cctvPos.row][i] == target)
                office[cctvPos.row][i] = num;
        }
        
    }
    //cout << "\n";
    
    //printOffice();
    
}
void findCCTVDir(int idx)
{
    if(idx == cctvs.size())
    {
        int blindSpotNum = computeBlindSpot();
        if(blindSpotNum < minBlindSpotNum)
            minBlindSpotNum = blindSpotNum;
        return;
    }
    
    else
    {
        cctv curCCTV = cctvs[idx];
        for(int i = 0; i<cctvDir[curCCTV.cctvNum].size(); i++)
        {
            direction curDir = cctvDir[curCCTV.cctvNum][i];
            monitor(curDir, curCCTV, idx, true);
            findCCTVDir(idx+1);
            monitor(curDir, curCCTV, idx, false);
        }
    }
    
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    setCCTVDir();
    cin >> n >> m;
    minBlindSpotNum = n * m;
    office = vector<vector<int>>(n, vector<int>(m, 0));
    cctvs.push_back({0, 0, 0});

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
    
    findCCTVDir(1);
    cout << minBlindSpotNum;
    


}