#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string a, string b)
{
	if (a.length() == b.length())
	{
		if (a < b)//사전순으로 a가 더 앞임
			return true;
		else return false;
	}
	else
		return a.length() < b.length();
}
int main(void)
{
	int times = 0;
	scanf("%d", &times);
	vector<string> stringList(times);

	for (int i = 0; i < times; i++)
		cin >> stringList[i];
	
	sort(stringList.begin(), stringList.end(), compare);

	for (int i = 0; i < times; i++)
	{
		int flag = 0;
		for (int j = 0; j < i; j++)
		{
			if (stringList[i] == stringList[j])
			{
				flag = 1;
				break;
			}
		}
		if (flag == 1)
			continue;
		cout << stringList[i] << "\n";
	}

}