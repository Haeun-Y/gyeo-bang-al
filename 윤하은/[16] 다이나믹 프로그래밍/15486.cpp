//240124
//BOJ 15486 퇴사2
//SILVER 3
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct
{
    int startDate;
    int endDate;
    int profit;
}reservation;
int n;
vector<reservation> consulting;
long long computeMaxProfit()
{
    vector<int> maxProfit(n+1, 0);

    for(int i = 1; i<=n; i++)
    {
        reservation cur = consulting[i];
        maxProfit[cur.startDate] = max(maxProfit[i-1], maxProfit[i]); 
        
        if(consulting[i].endDate > n) continue;
        maxProfit[cur.endDate] = max(maxProfit[cur.endDate], maxProfit[i-1] + cur.profit);
    }

    return *max_element(maxProfit.begin(), maxProfit.end());
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;

    consulting = vector<reservation>(n+1, {0, 0, 0});
    for(int i = 1; i<=n; i++)
    {
        consulting[i].startDate = i;
        cin >> consulting[i].endDate >> consulting[i].profit;
        consulting[i].endDate += (i-1);
    }

    cout << computeMaxProfit();
}