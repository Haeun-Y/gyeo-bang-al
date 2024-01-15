//240112
//BOJ 15665 N과 M(11)
//SILVER 2
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
vector<int> nums;
vector<int> seq;
void printSeq()
{
    for(int i = 0; i<m; i++)
        cout << seq[i] << " ";
    cout << "\n";
}
void setSeq(int idx)
{
    if(idx == m)
    {
        printSeq();
        return;
    }
    else
    {
        int before = 0;
        for(int i = 0; i<n; i++)
        {
            if(before == nums[i]) continue;
            seq[idx] = before = nums[i];
            setSeq(idx+1);
        }
    }

}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    nums = vector<int>(n, 0);
    seq = vector<int>(m, 0);

    for(int i = 0; i<n; i++)
        cin >> nums[i];

    sort(nums.begin(), nums.end());

    setSeq(0);
}