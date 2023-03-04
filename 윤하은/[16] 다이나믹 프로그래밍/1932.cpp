//BOJ 1932 정수 삼각형 
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  int num = (n*(n+1))/2;
  
  vector<int> triangle(num+1);

  for(int i = 1; i<= num; i++)
    cin >> triangle[i];

  int k = 2;
  for(int i = 2; i<=n; i++)
    {
      for(int j = 1; j<= i; j++)
        {
          //왼쪽 부모 없음
          if(j == 1)
            triangle[k] += triangle[k-i+1]; 

          //오른쪽 부모 없음
          else if(j==i)
            triangle[k] += triangle[k-i];

          else
            triangle[k] += max(triangle[k-i], triangle[k-i+1]);
        
          //cout << triangle[k] << " ";
          k++;

        }
      //cout << "\n";
    }
  int maxResult = triangle[num-n+1];

  for(int i = num-n+2; i<=num; i++)
    {
      maxResult = max(maxResult, triangle[i]);
    }

  cout << maxResult;
  

  
  
}
