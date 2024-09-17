#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//TODO : sort 함수 어떤 정렬 알고리즘 사용하는지 확인하기 -> 해당 알고리즘 stable한지 확인하기
bool cmp(pair<int, string> a, pair<int, string> b)
{
    return a.first < b.first;
}
int main(void)
{
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);

    int n;
    cin >> n;

    vector<pair<int, string>> members(n);

    for(int i = 0; i<n; i++)
    {
        cin >> members[i].first;//나이
        cin >> members[i].second;//이름
    }

    sort(members.begin(), members.end(), cmp);
}