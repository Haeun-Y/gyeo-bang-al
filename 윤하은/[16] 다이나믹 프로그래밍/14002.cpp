//240220
//BOJ 14002 가장 긴 증가하는 부분 수열 4
//GOLD 4
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<int> seq;
vector<pair<int, int>> subSeq;
bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first;
}
void printSubSeq()
{
    vector<int> v;
    int lastIdx = max_element(subSeq.begin(), subSeq.end(), cmp) - subSeq.begin();
    cout << subSeq[lastIdx].first << "\n";
    
    int i;
    for(i = lastIdx; i != subSeq[i].second; i = subSeq[i].second)
        v.push_back(seq[i]);
        
    v.push_back(seq[i]);
    
    for(int i = v.size()-1; i>=0; i--)
        cout << v[i] << " ";
    
    
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    seq = vector<int>(n, 0);
    subSeq = vector<pair<int, int>>(n, make_pair(0, 0));
    
    for(int i = 0; i<n; i++)
    {
        cin >> seq[i];
        subSeq[i].second = i;
        for(int j = 0; j<i; j++)
        {
            if(seq[j] < seq[i] && subSeq[i].first < subSeq[j].first)
            {
                subSeq[i].first = subSeq[j].first;
                subSeq[i].second = j;
            }
        }
        subSeq[i].first++;
        //cout << "subSeq[" << i << "] : (" << subSeq[i].first << ", " << subSeq[i].second << ")\n";
    }

    printSubSeq();
    
}
