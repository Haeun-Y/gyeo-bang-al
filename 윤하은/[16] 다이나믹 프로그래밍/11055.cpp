//BOJ 11055 가장 큰 증가 부분 수열
//틀렸습니다. 
//문제 풀이 다시 정리하기
#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first;
}
int main(void)
{
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);
    
    int n;
    cin >> n;

    vector<pair<int, int>> seq(n);
    vector<int> sum(n);

    for(int i = 0; i<n; i++)
    {
        cin >> seq[i].first;
        seq[i].second = i;
    }

    sort(seq.begin(), seq.end(), cmp);

    /*
    for(int i = 0; i<n; i++)
        cout << seq[i].first << " ";
    cout << "\n";
    */
    
    sum[n-1] = seq[n-1].first;

    pair<int, int> result = {sum[n-1], seq[n-1].second};
    
    for(int i = n-2; i>=0; i--)
    {

        if(seq[i].second < result.second)
        {
            sum[i] = result.first = result.first + seq[i].first;
            result.second = seq[i].second;
        }

        else
        {
            sum[i] = seq[i].first;
            if(seq[i+1].second > seq[i].second)
                sum[i] += sum[i+1];
            
            if(sum[i] > result.first)
            {
                result.first = sum[i];
                result.second = seq[i].second;
            }
            
        }

        //cout << "result : " << result.first << ", " << result.second << "\n";
        //cout << sum[i] << "\n";


    }

    cout << result.first;
}