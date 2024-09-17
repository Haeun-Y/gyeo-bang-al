//240328
//softeer 강의실 배정
//Lv.3
#include<bits/stdc++.h>
using namespace std;
int n;
vector<pair<int, int>> classes;
bool cmp(pair<int, int> a, pair<int, int> b) 
{
    if(a.second == b.second)
        return a.first < b.first;
    else return a.second < b.second;
}
int computeMaxClass()
{
    sort(classes.begin(), classes.end(), cmp);
    int beforeEndTime = classes[0].second;
    //cout << classes[0].first << "~" << classes[0].second << "\n";
    int result = 1;
    for(int i = 1; i<classes.size();i++) {
        pair<int, int> cur = classes[i];
        if(beforeEndTime > cur.first)
            continue;
        result++;
        beforeEndTime = cur.second;
        //cout << cur.first << "~" << cur.second << "\n";
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