#include <iostream>
#include <algorithm>
using namespace std;

typedef struct dot
{
	int x;
	int y;
}dot;
bool compare(dot a, dot b)
{
	if (a.x == b.x)
		return a.y < b.y;
	else return a.x < b.x;
}
int main(void)
{
	int numOfDot = 0;
	scanf("%d", &numOfDot);

	dot* arr = (dot*)malloc(sizeof(dot) * numOfDot);
	
	for (int i = 0; i < numOfDot; i++)
		scanf("%d %d", &arr[i].x, &arr[i].y);

	sort(arr, arr + numOfDot, compare);

	for (int i = 0; i < numOfDot; i++)
		printf("%d %d\n", arr[i].x, arr[i].y);
	
}