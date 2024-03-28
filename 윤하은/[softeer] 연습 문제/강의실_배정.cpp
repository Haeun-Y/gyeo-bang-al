//240328
//softeer 강의실 배정
//Lv.3
#include<bits/stdc++.h>
using namespace std;
int n;
vector<pair<int, int>> classes;
bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}
int computeMaxClass()
{
    int result = 0;

    vector<pair<int, int>> v = classes;
    
    while(v.size() > 0) {
        sort(v.begin(), v.end(), cmp);
        result++;
        vector<pair<int, int>> v2;
        pair<int, int> cur = v[0];
        
        for(int i = 1; i<v.size(); i++) {
            if(cur.second <= v[i].first) 
                v2.push_back(v[i]);
        }
        v = v2;
    }
    return result;
    
    
}
int main(int argc, char** argv)
{
    cin >> n;
    classes = vector<pair<int, int>>(n, {0, 0});
    for(int i = 0; i<n; i++)
        cin >> classes[i].first >> classes[i].second;
    cout << computeMaxClass();
   return 0;
}