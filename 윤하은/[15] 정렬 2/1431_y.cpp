//BOJ 1431
#include <bits/stdc++.h>
using namespace std;
int sum(string a)
{
	int sum = 0;
	for (int i = 0; i < a.length(); i++)
	{
		if (48 <= a[i] && a[i] <= 57)
			sum += a[i] - '0';
	}
	return sum;
}
bool cmp(string a, string b)
{
	if (a.length() != b.length())
		return a.length() < b.length();
	if (sum(a) != sum(b))
		return sum(a) < sum(b);
	
	return a < b;
		
}
int main(void)
{
	int numOfGuitar = 0;
	cin >> numOfGuitar;

	vector<string> serialList(numOfGuitar);

	for (int i = 0; i < numOfGuitar; i++)
		cin >> serialList[i];
	
	sort(serialList.begin(), serialList.end(), cmp);	
	for (int i = 0; i < numOfGuitar; i++)
		cout << serialList[i] << "\n";
	
}
