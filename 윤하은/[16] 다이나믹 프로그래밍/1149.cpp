//BOJ 1149 RGB 거리
#include <bits/stdc++.h>
using namespace std;
typedef struct house
{
    int red;
    int green;
    int blue;

}house;
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    const int COLOR_NUM = 3;

    int houseNum;
    cin >> houseNum;

    vector<house> prices(houseNum);
    vector<house> paintings(houseNum);

    for(int i = 0; i< houseNum; i++)
    {
        cin >> prices[i].red;
        cin >> prices[i].green;
        cin >> prices[i].blue;
    }

    paintings[0] = prices[0];

    for(int i = 1; i<houseNum; i++)
    {
        paintings[i].red = min(paintings[i-1].green, paintings[i-1].blue)+ prices[i].red;
        paintings[i].green = min(paintings[i-1].red, paintings[i-1].blue)+ prices[i].green;
        paintings[i].blue = min(paintings[i-1].red, paintings[i-1].green)+ prices[i].blue;
    }

    int minResult = min(paintings[houseNum-1].red, paintings[houseNum-1].green);
    minResult = min(minResult, paintings[houseNum-1].blue);

    cout << minResult;





}