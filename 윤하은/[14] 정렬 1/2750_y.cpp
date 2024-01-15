//230729 여방알
//BOJ 2750 수 정렬하기 
//BRONZE 2
//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  
  //ios::sync_with_stdio(false);
  //cin.tie(NULL);

  int n;
  cin >> n;

  vector<int> nums(n, 0);

  for(int i = 0; i<n; i++)
    cin >> nums[i];

  sort(nums.begin(),nums.end());

    for(int i = 0; i<n; i++)
        cout << nums[i] << "\n";

}