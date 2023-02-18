#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

typedef struct member
{
	string name;
	int age;
	int joiningOrder;

}member;
bool compare(member a, member b)
{
	if (a.age == b.age) return a.joiningOrder < b.joiningOrder;
	else return a.age < b.age;
}
int main(void)
{
	int numOfMembers = 0;
	member tmp;
	scanf("%d", &numOfMembers);

	vector <member> memberList;

	for (int i = 0; i < numOfMembers; i++)
	{
		cin >> tmp.age >> tmp.name;
		tmp.joiningOrder = i;
		memberList.push_back(tmp);
	}

	sort(memberList.begin(), memberList.end(), compare);

	for (int i = 0; i < numOfMembers; i++)
	{
		printf("%d ", memberList[i].age);
		cout << memberList[i].name;
		printf("\n");
	}
}