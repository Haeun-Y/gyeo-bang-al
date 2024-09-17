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
        for(int col = 0; col<n; col++)
        {
            for(int row = 0; row<n; row++)
            {
                //cout << "v[" << row << "][" << col << "] : " << v[row][col] << "\n";
                if(v[row][col] == 0) continue;
                for(int k = row+1; k<n; k++)
                {
                    if(v[k][col] == 0)
                        continue;
                    else
                    {
                        if(v[row][col] == v[k][col])
                        {
                            v[row][col] *= 2;
                            v[k][col] = 0;
                            row = k;
                        }
                        break;
                    }
                }
            }
            //print2048(v);
            int movedIdx = 0;
            for(int row = 0; row < n; row++)
            {
                if(v[row][col] != 0)
                    v[movedIdx++][col] = v[row][col];
            }
            for(;movedIdx < n; movedIdx++)
                v[movedIdx][col] = 0;
            //cout << "after remove 0s\n";
            //print2048(v);
        }

    }
    else if(direction == 'd')
    {
        for(int col = 0; col<n; col++)
        {
            for(int row = n-1; row>=0; row--)
            {
                //cout << "v[" << row << "][" << col << "] : " << v[row][col] << "\n";
                if(v[row][col] == 0) continue;
                for(int k = row-1; k>=0; k--)
                {
                    if(v[k][col] == 0) continue;
                    else
                    {
                        if(v[row][col] == v[k][col])
                        {
                            v[row][col] *= 2;
                            v[k][col] = 0;
                            row = k;
                        }
                        break;
                    }
                }
            }
            //print2048(v);
            int movedIdx = n-1;
            for(int row = n-1; row >= 0; row--)
            {
                if(v[row][col] != 0)
                    v[movedIdx--][col] = v[row][col];
            }
            for(;movedIdx >= 0; movedIdx--)
                v[movedIdx][col] = 0;
            //cout << "after remove 0s\n";
            //print2048(v);
        }
        

    }
    else if(direction == 'l')
    {
        for(int row = 0; row < n; row++)
        {
            for(int col = 0; col < n; col++)
            {
                if(v[row][col] == 0) continue;
                for(int k = col + 1; k < n; k++)
                {
                    if(v[row][k] == 0) continue;
                    else
                    {
                        if(v[row][col] == v[row][k])
                        {
                                v[row][col] *= 2;
                                v[row][k] = 0;
                                col = k;
                        }
                        break;
                    }
                }
            }
            int movedIdx = 0;
            for(int col = 0; col <n; col++)
            {
                if(v[row][col] != 0)
                    v[row][movedIdx++] = v[row][col];
            }
            for(; movedIdx < n; movedIdx++)
                v[row][movedIdx] = 0;
        }

            
    }
    else//direction == 'r' 
    {
        for(int row = 0; row < n; row++)
        {
            for(int col = n-1; col >= 0; col--)
            {
                if(v[row][col] == 0) continue;
                for(int k = col - 1; k >= 0; k--)
                {
                    if(v[row][k] == 0) continue;
                    else
                    {
                        if(v[row][col] == v[row][k])
                        {
                            v[row][col] *= 2;
                            v[row][k] = 0;
                            col = k;
                        }
                        break;
                    }

                }
                
            }

            int movedIdx = n-1;
            for(int col = n-1; col >= 0; col--)
            {
                if(v[row][col] != 0)
                    v[row][movedIdx--] = v[row][col];
            }
            for(; movedIdx >= 0; movedIdx--)
                v[row][movedIdx] = 0;
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
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
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