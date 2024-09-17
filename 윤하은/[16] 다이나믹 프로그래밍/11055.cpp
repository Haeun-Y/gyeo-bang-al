//240123
//BOJ 11055 가장 큰 증가하는 부분 수열
//SILVER 2
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, result;
vector<int> seqSum;
vector<int> seq;
int main(void)
{
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);

    cin >> n;

    seqSum = vector<int>(n, 0);
    seq = vector<int>(n, 0);

    for(int i = 0; i<n; i++)
    {
        cin >> seq[i];

        for(int j = i-1; j >= 0; j--)
        {
            if(seq[i] > seq[j] && seqSum[j] > seqSum[i])
                seqSum[i] = seqSum[j];
        }
        seqSum[i] += seq[i];
    }

    cout << *max_element(seqSum.begin(), seqSum.end());
}