//230708 여방알
//BOJ 15683 감시 
//GOLD 4

#include <iostream>
#include <vector>
#include <utility>
using namespace std;
int office[10][10];
int row, col, minBlindSpot;
typedef struct cctv 
{
    pair<int, int> pos;
    int num;
}cctv;
vector<cctv> cctvs;
void watchOffice(int curId)
{
    if(curId == cctvs.size())
    {
        //여기서 office blindSpot 세기
        return;
    }
    //TODO: 방향 정보 넣어서 for문 짜기
    /*
    for(int i = 0; i<directionForCCTV[cctvs[curId].num].size(); i++)
    {
        현재 CCTV의 방향 -> 어쩌고 저쩌고 배열[i] 인것임 이 값이 방향정보를 나타냄 
        현재 방향에 따라서 checkXXX함수 호출
        watchOffice(curId+1);
        undoChecking(cctvs[curId].pos, curId);
    }
    
    */


}
//TODO : 여기 다 VOID로 바꾸고 RESULT 없애기
int checkUp(pair<int, int> target, int cctvId)
{
    int result = 0;
    for(int i = target.first-1; i>=0; i--)
    {
        if(office[i][target.second] == 6) break;
        if(office[i][target.second] == 0)
        {
            office[i][target.second] = cctvId;
            result++;
        }
    }
    return result;
}
int checkDown(pair<int, int> target, int cctvId)
{
    int result = 0;
    for(int i = target.first+1; i<row; i++)
    {
        if(office[i][target.second] == 6) break;
        if(office[i][target.second] == 0)
        {
            office[i][target.second] = cctvId;
            result++;
        }
    }
    return result;
}
int checkLeft(pair<int, int> target, int cctvId)
{
    int result = 0;
    for(int i = target.second-1; i>=0; i--)
    {
        if(office[target.first][i] == 6) break;
        if(office[target.first][i] == 0)
        {
            office[target.first][i] = cctvId;
            result++;
        }
    }
    return result;
}
int checkRight(pair<int, int> target, int cctvId)
{
    int result = 0;
    for(int i = target.second+1; i<col; i++)
    {
        if(office[target.first][i] == 6) break;
        if(office[target.first][i] == 0)
        {
            office[target.first][i] = cctvId;
            result++;
        }
    }
    return result;
}
void undoChecking(pair<int, int> target, int cctvId)
{
    for(int i = 0; i<row; i++)
    {
        if(office[i][target.second] == cctvId)

            office[i][target.second] = 0;
    }

    for(int i = 0; i<col; i++)
    {
        if(office[target.first][i] == cctvId)
        {
            office[target.first][i] = 0;
        }
    }

}
int main(void)
{
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);

    cin >> row >> col;
    minBlindSpot = row*col;

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            cin >> office[i][j];
            if(office[i][j] > 0 && office[i][j] < 6)
            {
                //save cctv information to cctvs
                cctv c;
                c.pos = make_pair(i, j);
                c.num = office[i][j];
                cctvs.push_back(c);
            }
        }
    }



    

    
}