#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int numOfNum = 0;
	scanf("%d", &numOfNum);

	vector<int> list(numOfNum);

	for (int i = 0; i < numOfNum; i++)
		scanf("%d", &list[i]);

	//오름차순 정렬
	sort(list.begin(), list.end());

	for (int i = 0; i < numOfNum; i++)
		printf("%d\n", list[i]);

}