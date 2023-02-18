#include <bits/stdc++.h>
using namespace std;
bool cmp(int a, int b)
{
  return a > b;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
    int numOfNum=0;
  cin >> numOfNum;
  vector<int> nums(numOfNum);

  for(int i =0; i<numOfNum; i++) cin >> nums[i];

  sort(nums.begin(), nums.end(), cmp);

  for(int i =0; i<numOfNum; i++) cout << nums[i] <<"\n";
  
    return 0;
}