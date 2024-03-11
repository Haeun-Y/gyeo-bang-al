//240229
//BOJ 9465 스티커
//SILVER 1
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<vector<pair<int, int>>> stickerSum;
vector<vector<int>> stickers;
int computeMaxStickerSum()
{
    stickerSum[0][0].first = stickers[0][0];
    for(int i = 1; i<n; i++)
    {
        stickerSum[0][i].first = stickerSum[0][i-1].second + stickers[0][i];
        stickerSum[0][i].second = max(stickerSum[0][i-1].first, stickerSum[0][i-1].second);
        //cout << "stickerSum[0][" << i << "] : (" << stickerSum[0][i].first << ", " << stickerSum[0][i].second << ")\n";
    }

    int maxTotal = 0;

    stickerSum[1][0] = make_pair(stickers[1][0], stickerSum[0][0].first);
    for(int i = 1; i<n; i++)
    {
        stickerSum[1][i].first = stickerSum[1][i-1].second + stickers[1][i];
        stickerSum[1][i].second = max(stickerSum[1][i-1].first + stickers[0][i], stickerSum[1][i-1].second);
        maxTotal = max({stickerSum[1][i].first, stickerSum[1][i].second, maxTotal});
        //cout << "stickerSum[1][" << i << "] : (" << stickerSum[1][i].first << ", " << stickerSum[1][i].second << ")\n";     
    }

    return maxTotal;
}
int main(void)
{
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);

    int tc;
    cin >> tc;
    
    while(tc--)
    {
        cin >> n;
        stickers = vector<vector<int>>(2, vector<int>(n, 0));
        stickerSum = vector<vector<pair<int, int>>>(2, vector<pair<int, int>>(n, {0, 0}));

        for(int i = 0; i<2; i++)
            for(int j = 0; j<n; j++)
                cin >> stickers[i][j];
        
        cout << computeMaxStickerSum() << "\n";
    }
}