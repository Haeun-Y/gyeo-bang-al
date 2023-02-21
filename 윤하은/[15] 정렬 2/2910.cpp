#include <bits/stdc++.h>
using namespace std;
bool isExist(vector<pair<int, int>> & v, int target)
{
    for(int i = 0; i< v.size(); i++)
    {
        if(v[i].first == target)
		{
			v[i].second++;
			return true;
		}
    }

	return false;
}
bool cmp(pair<int, int> a, pair<int, int> b)
{
	return a.second > b.second;
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, c;
    cin >> n >> c;
    
    vector<pair<int, int>> v;
    
    for(int i = 0; i<n; i++)
    {
		int num;
		cin >> num;

		if(!isExist(v, num))
			v.push_back({num, 1});
    }

	sort(v.begin(), v.end(), cmp);

	for(int i = 0; i < v.size(); i++)
	{
		for(int j = 0; j<v[i].second; j++)
			cout << v[i].first << " ";
	}
}