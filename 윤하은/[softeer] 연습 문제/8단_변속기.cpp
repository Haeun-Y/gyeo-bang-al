//240805
//softeer 8단 변속기
//Lv.3
#include<bits/stdc++.h>
using namespace std;
void solution(vector<int>& v)
{
    bool isAscending = (v[0] < v[1])? true : false;
    
    for(int i = 1; i<v.size()-1; i++)
    {
        bool curAscending = (v[i] < v[i+1])? true : false;
        if(isAscending != curAscending) {
            cout << "mixed";
            return;
        }
    }

    if(isAscending) cout << "ascending";
    else cout << "descending";

    return;
        
}
int main(void)
{
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);

    const int n = 8;
    vector<int> numbers(n, 0);

    for(int i = 0; i<n; i++)
            cin >> numbers[i];
    
    solution(numbers);
}