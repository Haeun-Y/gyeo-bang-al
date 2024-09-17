//240121
//BOJ 18808 스티커 붙이기
//GOLD 3
#include <iostream>
#include <vector>
using namespace std;
int laptopRow;
int laptopCol;
int stickerNum;
vector<vector<vector<bool>>> stickers;
vector<vector<bool>> laptop;
void printStickers()
{
    for(int i = 0; i<stickers.size(); i++)
    {
        for(int j = 0; j<stickers[i].size(); j++)
        {
            for(int k = 0; k<stickers[i][j].size(); k++)
            {
                if(stickers[i][j][k])
                    cout << "#";
                else cout << ".";
            }
            cout << "\n";
        }
        cout << "\n";
    }
}
void putSticker(vector<vector<bool>>& sticker, pair<int, int> pos)
{
    for(int i = 0; i<sticker.size(); i++)
    {
        for(int j  = 0; j<sticker[0].size(); j++)
        {
            pair<int, int> laptopPos = make_pair(pos.first + i, pos.second + j);
            if(sticker[i][j])
                laptop[laptopPos.first][laptopPos.second] = true;
        }
    }

}
bool checkAttachableInPosition(vector<vector<bool>>& sticker, pair<int, int> pos)
{
    //1. check index
    int stickerRow = sticker.size();
    int stickerCol = sticker[0].size();
    //pos2 : bottom right vertext position if sticker attached starting from pos 
    pair<int, int> pos2 = make_pair(pos.first + stickerRow - 1, pos.second + stickerCol -1);
    
    if(pos.first + stickerRow > laptopRow || pos.second + stickerCol > laptopCol)
        return false;

    //2. check attached sticker on laptop
    for(int i = 0; i < stickerRow; i++)
    {
        for(int j = 0; j < stickerCol; j++)
        {
            pair<int, int> laptopPos = make_pair(pos.first + i, pos.second + j);
            if(laptop[laptopPos.first][laptopPos.second] && sticker[i][j])
                return false;
        }

    }

    return true;

}
pair<int, int> checkAttachable(vector<vector<bool>>& sticker)
{
    for(int i = 0; i<laptopRow; i++)
    {
        for(int j = 0; j<laptopCol; j++)
        {
            if(checkAttachableInPosition(sticker, make_pair(i, j)))
                return make_pair(i, j);
        }
    }
    //sticker can't be attached in current shape.
    return make_pair(-1, -1);
}
void rotate90degree(vector<vector<bool>>& sticker)
{
    int row = sticker.size();
    int col = sticker[0].size();
    vector<vector<bool>> tmp(col, vector<bool>(row, false));
    for(int i = 0; i<row; i++)
    {
	    for(int j = 0; j<col; j++)
            tmp[j][row-i-1] = sticker[i][j];
    }
    sticker = tmp;
}
int computeStickerArea()
{
    int cnt = 0;
    for(int i = 0; i<laptopRow; i++)
    {
        for(int j = 0; j<laptopCol; j++)
        {
            if(laptop[i][j]) cnt++;
        }
    }
    return cnt;
}
int func1()
{
    for(int i = 0; i<stickerNum; i++)
    {
        for(int j = 0; j<4; j++)
        {
            pair<int, int> startPos = checkAttachable(stickers[i]);
            if(startPos.first != -1 && startPos.second != -1)//attachable
            {
                putSticker(stickers[i], startPos);
                break;
            }
            rotate90degree(stickers[i]);
        }
    }

    return computeStickerArea();
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> laptopRow >> laptopCol >> stickerNum;
    laptop = vector<vector<bool>>(laptopRow, vector<bool>(laptopCol, false));
    

    for(int i = 0; i<stickerNum; i++)
    {
        int row, col;
        cin >> row >> col;
        vector<vector<bool>> v(row, vector<bool>(col, 0));
        for(int j = 0; j<row; j++)
        {
            for(int k = 0; k<col; k++)
            {
                int num;
                cin >> num;
                v[j][k] = num;
            }
        }
        stickers.push_back(v);
    }

    cout << func1();

}