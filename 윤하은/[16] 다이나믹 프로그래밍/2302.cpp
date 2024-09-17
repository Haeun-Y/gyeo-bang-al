//240223
//BOJ 2302 극장 좌석
//SILVER 1
#include <iostream>
#include <vector>
using namespace std;
int n, m, cnt;
vector<bool> isVipMember;
vector<bool> isOccupied;
void findSeat(int memberNum)
{
    if(memberNum > n)
    {
        //cout << "***********\n";
        cnt++;
    }
    else
    {
        if(isVipMember[memberNum])
            findSeat(memberNum+1);
        
        else
        {
            for(int i = -1; i<2; i++)
            {
                int cur = memberNum + i;
                if(cur < 1 || cur > n) continue;
                if(isOccupied[cur] || isVipMember[cur]) continue;
                isOccupied[cur] = true;
                //cout << memberNum << " member takes seat " << cur << "\n";
                findSeat(memberNum+1);
                isOccupied[cur] = false;
            }     

        }
        
    }

}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    isVipMember = vector<bool>(n+1, false);
    isOccupied = vector<bool>(n+1, false);
    cnt = 0;

    for(int i = 0; i<m; i++)
    {
        int memberNum;
        cin >> memberNum;
        isVipMember[memberNum] = true;
        isOccupied[memberNum] = true;
    }

    findSeat(1);
    cout << cnt;
    
}