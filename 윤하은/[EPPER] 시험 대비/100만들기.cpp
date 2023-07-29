#include <bits/stdc++.h>
using namespace std;
void solution(vector<int>& nums, vector<int>& answer)
{
	vector<int> exists(100, -1);
	
	int sum = 0;
	
	for(int i = 0; i<9; i++)
	{
		exists[nums[i]] = i;
		sum += nums[i];
	}
	
	sum -= 100;
	
	
	int flag1 = 0, flag2 = 0;
	
	for(int i = 0; i<9; i++)
	{
		int target = sum - nums[i];
		if(target < 1 || target > 99) continue;
		
		if(exists[target] != -1)
		{
			flag1 = i;
			flag2 = exists[target];
			break;
			
		}
			
		
	}
	
	for(int i = 0; i<9; i++)
	{
		if(i == flag1 || i == flag2)
			continue;
		answer.push_back(nums[i]);
	}
	
	return;
	
	
}
int main(void)
{
	vector<int> nums(9);
	vector<int> answer;
	
	for(int i = 0; i<9; i++)
		cin >> nums[i];
	
	solution(nums, answer);
	
	for(int i = 0; i<7; i++)
		cout << answer[i] << " ";
}
