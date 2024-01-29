//240122
//BOJ 12100 2048 (Easy)
//GOLD 2
#include <iostream>
#include <vector>
using namespace std;
const int MAX_MOVE = 5;
int maxResult;
int n;
vector<vector<int>> board;
int findMaxBlock(vector<vector<int>>& board)
{
    int result = 0;
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            if(result < board[i][j])
                result = board[i][j];
        }
    }

    return result;
}
void moveBlocks(vector<vector<int>>& v, char direction)//u:up, d:down, l:left, r:right
{
    if(direction == 'u')
    {
        int movedIdx = 0;
        for(int col = 0; col<n; col++)
        {
            for(int row = 0; row<n; row++)
            {
                for(int k = row+1; k<n; k++)
                {
                    if(v[row][col] == v[row][k])
                    {
                        v[row][movedIdx++] = v[row][col] + v[row][k];
                        row = k+1;
                        break;
                    }
                }
            }
        }

    }
    else if(direction == 'd')
    {
        int movedIdx = n-1;
        for(int col = 0; col<n; col++)
        {
            for(int row = n-1; row>=0; row--)
            {
                for(int k = row-1; k>=0; k--)
                {
                    if(v[row][col] == v[row][k])
                    {
                        v[row][movedIdx--] = v[row][col] + v[row][k];
                        row = k-1;
                        break;
                    }
                }
            }
        }

    }
    else if(direction == 'l')
    {
        int movedIdx = 0;
        for(int row = 0; row<n; row++)
        {
            for(int col = 0; col<n; col++)
            {
                for(int k = col+1; k<n; k++)
                {
                    if(v[row][col] == v[row][k])
                    {
                        v[row][movedIdx++] = v[row][col] + v[row][k];
                        col = k+1;
                        break;
                    }
                }
            }
        }

    }
    else//direction == 'r' 
    {
        int movedIdx = 0;
        for(int row = 0; row<n; row++)
        {
            for(int col = 0; col<n; col++)
            {
                for(int k = col+1; k<n; k++)
                {
                    if(v[row][col] == v[row][k])
                    {
                        v[row][movedIdx++] = v[row][col] + v[row][k];
                        row = k+1;
                        break;
                    }
                }
            }
        }

    }

}
//v : move-1까지의 이동을 완료한 벡터
void play2048(vector<vector<int>> v, int move)
{
    if(move > MAX_MOVE)
    {
        int result = findMaxBlock(v);
        if(result > maxResult)
            maxResult = result;
    }
    else
    {
        string str = "udlr";

        for(int i = 0; i<4; i++)
        {
            vector<vector<int>> v2 = v;
            moveBlocks(v2, str[i]);
            play2048(v2, move+1);
        }

    }

}
int main(void)
{
    //ios::sycn_with_stdio(false);
    //cin.tie(NULL);
    cin >> n;

    board = vector<vector<int>>(n, vector<int>(n, 0));

    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
            cin >> board[i][j];
    }

    play2048(board, 1);

    cout << maxResult;
    
}