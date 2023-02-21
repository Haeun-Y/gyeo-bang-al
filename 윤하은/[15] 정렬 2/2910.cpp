#include <bits/stdc++.h>
using namespace std;
typedef struct element
{
	int num;
	int times;
	int initPos;

}element;
bool isExist(vector<element> & v, int target)
{
    for(int i = 0; i< v.size(); i++)
    {
        if(v[i].num == target)
		{
			v[i].times++;
			return true;
		}
    }

	return false;
}
bool cmp(element a, element b)
{
	if(a.times == b.times)
		return a.initPos < b.initPos;
	return a.times > b.times;
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, c;
    cin >> n >> c;
    
    vector<element> v;
    
    for(int i = 0; i<n; i++)
    {
		int num;
		cin >> num;

		if(!isExist(v, num))
			v.push_back({num, 1, i});
    }

	sort(v.begin(), v.end(), cmp);

	for(int i = 0; i < v.size(); i++)
	{
		for(int j = 0; j<v[i].times; j++)
			cout << v[i].num << " ";
	}
}