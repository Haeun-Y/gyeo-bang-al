#include <bits/stdc++.h>
using namespace std;
const int arrSize = 3;
int r, c, k;
vector<int> numInfo;
vector<vector<int>> arr;
void sortC()
{
    numInfo = vector<int>(101, 0);
    for(int i = 0; i<arr[i].size(); i++)
    {
        for(int j = 0; j<arr.size(); j++)
            numInfo[arr[j][i]]++;
        sort(numInfo.begin(), numInfo.end());
        for(int j = 0; j<arr[i].size(); j++)
        {
            v.push_back(j);
            v.push_back(numInfo[j]);
        }
        arr[i] = v;
    }

}
void sortR()
{
    numInfo = vector<int>(101, 0);
    for(int i = 0; i<arr.size(); i++)
    {
        vector<int> v;
        for(int j = 0; j<arr[i].size(); j++)
            numInfo[arr[i][j]]++;
        sort(numInfo.begin(), numInfo.end());
        for(int j = 0; j<arr[i].size(); j++)
        {
            v.push_back(j);
            v.push_back(numInfo[j]);
        }
        arr[i] = v;
    }
}
int func1() {
    
    for(int i = 0; i<=100; i++)
    {
        if(arr[r][c] == k) return i;
        
        if(arr.size() > arr[0].size())//R연산
            sortR();
        else sortC();
    }
    return -1;
}
int main(void)
{
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);
    
    arr = vector<vector<int>>(arrSize, vector<int>(arrSize, 0));
    cin >> r >> c >> k;
    
    for(int i = 0; i<arrSize; i++)
        for(int j = 0; j<arrSize; j++)
            cin >> arr[i][j];
            
    cout << func1();

}