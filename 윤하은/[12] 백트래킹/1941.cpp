#include <iostream>
#include <vector>
using namespace std;
const int PRINCESS_NUM = 7;
const int N = 5;
int dx[4] = {-1, 1, 0, 0};//UDLR
int dy[4] = {0, 0, -1, 1};//UDLR
bool students[5][5];
bool isBelongTo[5][5];
int ans;
void find7princesses(int idx, int sNum, pair<int, int> pos)
{
    if(idx == PRINCESS_NUM)
    {
        cout << "...finish checking 7 students...\n";
        if(sNum >= 4)
        {
            ans++;
            cout << "success to find the 7 princesses.\n";
        }
        return;
    }
    //이거 분기하는 위치가 좀 별로인듯
    /*else if(4 - sNum > PRINCESS_NUM - idx)
    {
        cout << "reamained princess : " << PRINCESS_NUM - idx << ", 4-sNum : " << 4 - sNum << "\n";
        return;
    }*/
    else
    {
        int curSNum = (students[pos.first][pos.second])? sNum+1 : sNum;
        isBelongTo[pos.first][pos.second] = true;
        cout << idx << "th princess is "<< ((students[pos.first][pos.second])?'S':'Y') << " : (" << pos.first << ", " << pos.second << ")\n"; 
        if(4 - curSNum > PRINCESS_NUM - idx - 1)
        {
            cout << "reamained princess : " << PRINCESS_NUM - idx - 1 << ", 4-sNum : " << 4 - curSNum << "\n";
            return;
        }
        for(int k = 0; k<4; k++)
        {
            int nx = pos.first + dx[k];
            int ny = pos.second + dy[k];

            if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if(isBelongTo[nx][ny]) continue;
            find7princesses(idx+1, curSNum, make_pair(nx, ny));
        }
        isBelongTo[pos.first][pos.second] = false;
    }

}
int main(void)
{
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);

    for(int i = 0; i<N; i++)
    {
        for(int j = 0; j<N; j++)
        {
            char ch;
            cin >> ch;
            students[i][j] = (ch == 'S')? true : false;
        }
    }
    find7princesses(0, 0, make_pair(0, 0));
    cout << ans;

}