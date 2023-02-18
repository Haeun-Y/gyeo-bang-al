#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
	if (a.second == b.second)
        return a.first < b.first;
	
	else
        return a.second < b.second;
	

}
int main(void)
{
	int numOfDot = 0;
	scanf("%d", &numOfDot);
	vector<pair<int, int>> listOfDot(numOfDot);

	for (int i = 0; i < numOfDot; i++)
        scanf("%d %d", &listOfDot[i].first, &listOfDot[i].second);
	
	sort(listOfDot.begin(), listOfDot.end(), compare);

	for (int i = 0; i < numOfDot; i++)
		printf("%d %d\n", listOfDot[i].first, listOfDot[i].second);
}