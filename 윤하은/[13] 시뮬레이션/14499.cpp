//BOJ 14499 주사위 굴리기
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    const int TOP = 0;
    const int BOTTOM = 1;
    const int FRONT = 2;
    const int BACK = 3;
    const int LEFT = 4;
    const int RIGHT = 5;
    
    const int N = 3;
    const int S = 4;
    const int E = 1;
    const int W = 2;
    
    int row, col, posX, posY, commandNum;
    cin >> row >> col >> posX >> posY >> commandNum;
    
    vector<vector<int>> paperMap(row, vector<int>(col));
    vector<int> dice(6, 0);
    
    for(int i = 0; i<row; i++)
    {
        for(int j =0; j<col; j++)
            cin >> paperMap[i][j];
    }
    
    for(int i =0; i<commandNum; i++)
    {
        int command, tmp = 0;
        cin >> command;
        bool isMoved = false;
        
        
        switch(command)
        {
            case N:
                if(posX-1 >= 0)
                {    
                    isMoved = true;
                    tmp = dice[TOP];
                    dice[TOP] = dice[FRONT];
                    dice[FRONT] = dice[BOTTOM];
                    dice[BOTTOM] = dice[BACK];
                    dice[BACK] = tmp;
                    posX--;
                    
                    
                }
                break;
            case S:
                if(posX+1 < row)
                {    
                    isMoved = true;
                    tmp = dice[TOP];
                    dice[TOP] = dice[BACK];
                    dice[BACK] = dice[BOTTOM];
                    dice[BOTTOM] = dice[FRONT];
                    dice[FRONT] = tmp;
                    posX++;
                }
                break;
            case E:
                if(posY+1 < col)
                {
                    isMoved = true;
                    tmp = dice[TOP];
                    dice[TOP] = dice[LEFT];
                    dice[LEFT] = dice[BOTTOM];
                    dice[BOTTOM] = dice[RIGHT];
                    dice[RIGHT] = tmp;
                    posY++;
                }
                break;
            case W:
                if(posY-1 >= 0)
                {
                    isMoved = true;
                    tmp = dice[TOP];
                    dice[TOP] = dice[RIGHT];
                    dice[RIGHT] = dice[BOTTOM];
                    dice[BOTTOM] = dice[LEFT];
                    dice[LEFT] = tmp;
                    posY--;
                }
                break;
                
        }
        
        if(isMoved)
        {
            if(paperMap[posX][posY] == 0)
                paperMap[posX][posY] = dice[BOTTOM];
            else
            {    
                dice[BOTTOM] = paperMap[posX][posY];
                paperMap[posX][posY] = 0;
            }
                
            cout << dice[TOP] << "\n";
            /*cout << i <<"위" <<dice[TOP] << "바닥" << dice[BOTTOM];
            cout << "앞" <<dice[FRONT] <<"뒤" << dice[BACK];
            cout <<"왼" << dice[LEFT] <<"오" << dice[RIGHT];
            cout << "\n";*/
         }
        
        
    }
    
}
