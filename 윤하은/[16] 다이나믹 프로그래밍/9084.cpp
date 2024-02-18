//240218
//BOJ 9084 동전
//GOLD 5
#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);
    
    int tc;
    cin >> tc;

    while(tc--)
    {
        int coinNum;
        cin >> coinNum;

        vector<int> coins(coinNum, 0);

        for(int i = 0; i<coinNum; i++)
            cin >> coins[i];
        
        int targetPrice; 
        cin >> targetPrice;

        vector<pair<int, int>> price(targetPrice+10, make_pair(0, 0));

        price[0] = make_pair(1, 0);

        for(int i = 0; i<targetPrice; i++)
        {
            int curPrice = i; 
            if(price[curPrice].first == 0) continue;
            cout << "curPrice : " << curPrice << "\n";
            for(int j = 0; j<coinNum; j++)
            {
                if(curPrice + coins[j] > targetPrice) break;
                if(price[curPrice].second > coins[j]) continue;
                price[curPrice + coins[j]].first += price[curPrice].first;
                price[curPrice + coins[j]].second = coins[j];
                cout << "price[" << curPrice + coins[j] << "] : " << price[curPrice + coins[j]].first << "\n";
            }
        }

        cout << price[targetPrice].first;

    }


}