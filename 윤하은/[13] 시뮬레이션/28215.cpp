//240409
//28215 대피소
//SILVER 4
#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<pair<int, int>> houses;
int computeMaxDist(vector<pair<int, int>>& v)
{
    int maxDist = 0;
    
    for(int i = 0; i<n; i++)
    {
        int minDist = 0x7fffffff;
        pair<int, int> cur = houses[i];
        for(int j = 0; j<v.size(); j++)
        {
            int dist = abs(v[j].first - cur.first) + abs(v[j].second - cur.second);
            minDist = min(minDist, dist);
        }
        maxDist = max(maxDist, minDist);
    }
    
    return maxDist;
    
}
int computeMinMaxDist()
{
    int minMaxDist = 0x7fffffff;
    
    vector<int> v(n, 1);
    for(int i = 0; i<k; i++)
        v[i]=0;
    
    do
    {
        vector<pair<int, int>> selectedH;
        for(int i = 0; i<n; i++)
        {
            if(v[i] == 0)
                selectedH.push_back(houses[i]);
        }
        minMaxDist = min(minMaxDist, computeMaxDist(selectedH));
        
    }while(next_permutation(v.begin() ,v.end()));
    return minMaxDist;
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> k;
    
    for(int i = 0; i<n; i++)
    {
        int x, y;
        cin >> x >> y;
        houses.push_back({x, y});
    }
    
    cout << computeMinMaxDist();
    
    
}
