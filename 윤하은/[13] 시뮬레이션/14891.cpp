//BOJ 14891 톱니바퀴
#include <bits/stdc++.h>
using namespace std;
vector<vector<char>> v(4, vector<char>(8));
void spinGear(int gearNum)
{
  char last = v[gearNum][7];
  for(int i = 7; i>0; i--)
    {
      v[gearNum][i] = v[gearNum][i-1];
    }  
  v[gearNum][0] = last;

  
  
}
void spinGearReverse(int gearNum)
{
  char first = v[gearNum][0];
  for(int i = 1; i<8; i++)
    v[gearNum][i-1] = v[gearNum][i];
  
  v[gearNum][7] = first;
  
}
void spin(int target, int direction)
{
  int arr[4] = {0,};
  arr[target] = direction;

  for(int i = target+1; i<4; i++)
    {
      if(arr[i-1] != 0 && v[i-1][2] != v[i][6])
        arr[i] = (arr[i-1] == 1)? -1 : 1;
    }
  for(int i = target-1; i>=0; i--)
    {
      if(arr[i+1] != 0 && v[i+1][6] != v[i][2])
        arr[i]= (arr[i+1] == 1)? -1 : 1;
    }

 /* for(int i = 0; i<4; i++)
    cout << arr[i] <<" ";
  cout << "\n";*/
  for(int i = 0; i<4; i++)
    {
      if(arr[i] == 1)
        spinGear(i);
      else if(arr[i]== -1)
        spinGearReverse(i);
    }

 /* cout << target << " " << direction << "\n";
  for(int i = 0; i<4; i++)
    {
      for(int j = 0; j<8; j++)
        cout << v[i][j];
      cout << "\n";
    }*/
  
  
}
int sumScore()
{
  int result = 0;
  for(int i = 0; i<4; i++)
    {
      if(v[i][0] == '1')
        result += pow(2, i);
    }
  return result;
}
int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  for(int i = 0; i<4; i++)
    {
      for(int j = 0; j<8; j++)
        cin >> v[i][j];
    }
  int spinNum;
  cin >> spinNum;

  for(int i = 0; i<spinNum; i++)
    {
      int target, direction;
      cin >> target >> direction;
      spin(target-1, direction);
    }

  cout << sumScore();
  
}
