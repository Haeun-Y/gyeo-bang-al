//240505
//BOJ 17070 파이프 옮기기 1
//GOLD 5
#include <iostream>
#include <vector>
using namespace std;
int n;
vector<vector<bool>> isWall;
int answer;
bool isEmptyFor45(pair<int, int> target)
{
    int dx[3] = {0, 1, 1};
    int dy[3] = {1, 0, 1};

    for(int i = 0; i<3; i++)
    {
        int nx = target.first + dx[i];
        int ny = target.second + dy[i];

        if(nx < 0 || nx >= n || ny < 0 || ny >= n)
            return false;
        if(isWall[nx][ny]) return false;
    }
    return true;

}
void backtracking(pair<int, int> pipe1, pair<int, int> pipe2, int dir)
{
    if((pipe1.first == n-1 && pipe1.second == n-1) || (pipe2.first == n-1 && pipe2.second == n-1))
    {
        //cout << "reached!!!\n";
        //cout << dir << " pipe pos : [" << pipe1.first << ", " << pipe1.second <<"], [" << pipe2.first << ", " << pipe2.second << "]\n"; 
        answer++;
        return;
    }
    else
    {
        //cout << "not yet reached\n";
        //cout << dir << " pipe pos : [" << pipe1.first << ", " << pipe1.second <<"], [" << pipe2.first << ", " << pipe2.second << "]\n";
        if(isEmptyFor45({pipe2}))//회전 이동
                backtracking(pipe2, {pipe2.first+1, pipe2.second+1}, 2);
        //else cout << "No rotateMove\n";
        if(dir == 0 || dir == 2)//가로 이동
        {
            if(pipe2.second + 1 < n && !isWall[pipe2.first][pipe2.second+1])
                backtracking(pipe2, {pipe2.first, pipe2.second+1}, 0);
            //else cout << "No horizontalMove\n";
        }
        if(dir == 1 || dir == 2)//세로 이동
        {
            if(pipe2.first + 1 < n && !isWall[pipe2.first+1][pipe2.second])
                backtracking(pipe2, {pipe2.first+1, pipe2.second}, 1);
            //else cout << "No verticalMove\n";
        }
        
    }


}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    isWall = vector<vector<bool>>(n, vector<bool>(n, false));

    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            int flg;
            cin >> flg;
            isWall[i][j] = flg;
        }
    }

    backtracking({0, 0}, {0, 1}, 0);
    cout << answer;


}