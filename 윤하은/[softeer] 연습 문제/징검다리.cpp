//240327
//softeer 징검다리
//Lv.3
#include<bits/stdc++.h>
using namespace std;
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<int> rocks(n, 0);
    
    for(int i = n-1; i>=0; i--)
        cin >> rocks[i];
    
    vector<int> rockStair(n, 1);
    int maxResult = 0;
    for(int i = 0; i<n; i++) {
        int maxNum = 0;
        for(int j = 0; j<i; j++) {
            if(rocks[i] >= rocks[j]) continue;
            maxNum = max(maxNum, rockStair[j]);
        }
        rockStair[i] += maxNum;
        maxResult = max(maxResult, rockStair[i]);
    }
    cout << maxResult;
   return 0;
}