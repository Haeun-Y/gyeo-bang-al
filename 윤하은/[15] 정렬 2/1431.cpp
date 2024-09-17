#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int sumStr(string a)
{
	int sum = 0;
	for (int i = 0; i < a.length(); i++)
	{
		if (48 <= a[i] && a[i] <= 57)//숫자 기호일때
			sum += a[i] - '0';
	}
	return sum;
}
bool cmp(string a, string b)
{
	if (a.length() != b.length())
		return a.length() < b.length();
	if (sumStr(a) != sumStr(b))
		return sumStr(a) < sumStr(b);
	
	return a < b;
		
}
int main(void)
{
	int guitarNum = 0;
	scanf("%d", &guitarNum);

	vector<string> serialList(guitarNum);

	for (int i = 0; i < guitarNum; i++)
		cin >> serialList[i];
	
	sort(serialList.begin(), serialList.end(), cmp);	
	for (int i = 0; i < guitarNum; i++)
	{
		cout << serialList[i];
		printf("\n");
	}
}