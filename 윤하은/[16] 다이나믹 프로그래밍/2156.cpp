//240221
//BOJ 2156 포도주 시식
//SILVER 1
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct
{
    int size;
    int x;
    int drink1;
    int drink2;
}wine;
int n;
vector<wine> tasting;
int computeMaxPerCup(int i)
{
    return max({tasting[i].x, tasting[i].drink1, tasting[i].drink2});
}
int computeMaxSize()
{
    tasting[0].drink1 = tasting[0].size;
    
    int maxPerCup = computeMaxPerCup(0);
    int maxResult = max(maxResult, maxPerCup);
    for(int i = 1; i<n; i++)
    {
        tasting[i].x = maxPerCup;
        tasting[i].drink1 = tasting[i].size + tasting[i-1].x;
        tasting[i].drink2 = tasting[i].size + tasting[i-1].drink1;
        
        maxPerCup = computeMaxPerCup(i);
        maxResult = max(maxResult, maxPerCup);
    }
    return maxResult;
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    tasting = vector<wine>(n, {0, 0, 0, 0});
    
    for(int i = 0; i<n; i++)
        cin >> tasting[i].size;
    
    cout << computeMaxSize();
    
}
