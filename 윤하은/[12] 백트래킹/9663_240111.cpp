//240111
//BOJ 9663 N-Queen
//GOLD 4
#include <iostream>
#include <vector>
using namespace std;
vector<bool> isUsedRightDown;//row - col + n - 1
vector<bool> isUsedRightUp;//row + col
vector<bool> isUsedCol;//col
int n, result;
//row행에 queen을 배치하는 함수
void putQueen(int row)
{
    if(row == n)
    {
        result++;
        return;
    }
    else
    {
        for(int col = 0; col < n; col++)
        {
            int rightDownNum = row - col + n - 1;
            int rightUpNum = row + col;

            if(!isUsedRightDown[rightDownNum] && !isUsedRightUp[rightUpNum] && !isUsedCol[col])
            {
                //put queen in (row, col)
                isUsedRightDown[rightDownNum] = isUsedRightUp[rightUpNum] = isUsedCol[col] = true;
                putQueen(row+1);
                isUsedRightDown[rightDownNum] = isUsedRightUp[rightUpNum] = isUsedCol[col] = false;

            }
            
        }


    }
}
int main(void)
{
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);

    cin >> n;
    isUsedRightDown = vector<bool>(2 * n, false);
    isUsedRightUp = vector<bool>(2 * n, false);
    isUsedCol = vector<bool>(n, false);

    putQueen(0);

    cout << result;
}