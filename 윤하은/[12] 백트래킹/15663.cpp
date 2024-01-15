//240112
//BOJ 15664 N과 M(9)
//SILVER 2
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
vector<int> nums;
vector<int> seq;
vector<bool> isUsed;
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
            if(isUsed[i]) continue;
            if(before == nums[i]) continue;//같은 자리에 같은 수 => 중복된 수열

            before = nums[i];
            isUsed[i] = true;
            seq[idx] = nums[i];
            setSeq(idx+1);
            isUsed[i] = false;
        }

    }

}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;

    nums = vector<int>(n, 0);
    isUsed = vector<bool>(n, false);
    seq = vector<int>(m, 0);

    for(int i = 0; i<n; i++)
        cin >> nums[i];

    sort(nums.begin(), nums.end());

    setSeq(0);

}