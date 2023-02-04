//BOJ 13335 트럭
#include <bits/stdc++.h>
using namespace std;
int crossBridge(vector<int> & v, int length, int load)
{
  int time = 0;
  int curLoad = 0;
  int truckNum = 0;
  int i = 0;

  queue<pair<int, int>> q;
  q.push({v[i], ++time});
  curLoad = v[i++];
  truckNum= 1;

  while(!q.empty())
    {
      time++;
      
      if(q.front().second+length == time)
      {
        pair<int, int> truck = q.front();
        q.pop();
        curLoad -= truck.first;
        truckNum--;
      }
      if(i < v.size() && curLoad + v[i] <= load && truckNum < length)
      {
        q.push({v[i], time});
        curLoad += v[i++];
        truckNum++;
      }
      
      
    }
  
  return time;

  
}
int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int truckNum, length, load;
  cin >> truckNum >> length >> load;

  vector<int> trucks(truckNum);
  
  for(int i = 0; i<truckNum; i++)
    cin >> trucks[i];

  cout << crossBridge(trucks, length, load);
}
