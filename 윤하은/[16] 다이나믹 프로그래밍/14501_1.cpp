//240126
//BOJ 14501 퇴사
//SILVER 3
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<pair<int, int>> consultings;
vector<int> maxProfit;
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    consultings = vector<pair<int, int>>(n+1, make_pair(0, 0));
    maxProfit = vector<int>(n+1, 0);
    

    for(int i = 1; i<=n; i++)
        cin >> consultings[i].first >> consultings[i].second;
        

    for(int i = 1; i<=n; i++)
    {
        maxProfit[i] = max(maxProfit[i-1], maxProfit[i]);
        //cout << "maxProfit[" << i << "] : " << maxProfit[i] << "\n"; 
        int endDate = i + consultings[i].first - 1;
        if(endDate > n) continue;
        maxProfit[endDate] = max(maxProfit[endDate], maxProfit[i-1] + consultings[i].second);
        //cout << "maxProfit[" << endDate << "] stated from " << i << "day : "<< maxProfit[endDate] << "\n";
    }

    cout << *max_element(maxProfit.begin(), maxProfit.end());


}