#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int numberOfNumbers = 0;
	int tmp = 0;
	scanf("%d", &numberOfNumbers);

	vector<int> v1(10000);//만개 자동으로 0으로 초기화 됨

	for (int i = 0; i < numberOfNumbers; i++)
	{
		scanf("%d", &tmp);
		v1[tmp-1]++;
	}

	for (int i = 0; i < 10000; i++)
	{
		int times = v1[i];
		if (tmp != 0)
		{
			for (int j = 0; j < times; j++)
				printf("%d\n", i+1);
		}
	}

}