//240125
//BOJ 11053 가장 긴 증가하는 부분 수열
//SILVER 2
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<int> seq;
vector<int> seqNum;
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    seq = seqNum = vector<int>(n, 0);
    for(int i = 0; i<n; i++)
    {
        cin >> seq[i];
        for(int j = 0; j<i; j++)
        {
            if(seq[i] > seq[j])
                seqNum[i] = max(seqNum[i], seqNum[j]);
        }
        seqNum[i]++;
    }

    cout << *max_element(seqNum.begin(), seqNum.end());

}