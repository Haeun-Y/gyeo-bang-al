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
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);
    
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
/*
#include <bits/stdc++.h>
using namespace std;

map <int, int> order; //index 저장

bool cmp(pair<int, int>& a, pair<int, int>& b)
{
	if (a.second == b.second)
		return order[a.first] < order[b.first];

	return a.second > b.second;
}

int main()
{
	//freopen("test.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, C;
	cin >> N >> C;

	map<int, int> m;
	int num;

	for (int i = 0; i < N; i++)
	{
		cin >> num;
		m[num]++;

		if (order[num] == 0)
			order[num] = i+1;
	}
	
	vector<pair<int, int>> vec(m.begin(), m.end());

	sort(vec.begin(), vec.end(), cmp);

	for (auto x : vec)
	{
		for (int i = 0; i < x.second; i++)
		{
			cout << x.first << " ";
		}
	}

	return 0;
}*/
