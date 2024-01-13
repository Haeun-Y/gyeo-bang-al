#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
vector<int> seq;
vector<int> nums;
void printSeq()
{
    for(int i = 0; i<m; i++)
        cout << seq[i] << " ";
    cout << "\n";
}
void setSeq(int idx, int beforeIdx)
{
    if(idx == m)
    {
        printSeq();
        return;
    }
    else
    {
        int tmp = 0;
        for(int i = beforeIdx; i<n; i++)
        {
            if(tmp == nums[i]) continue;//seq[idx]값이 이전 같과 같다면 중복된 수열이 만들어짐
            seq[idx] = nums[i];
            setSeq(idx+1, i);
            tmp = nums[i];
        }
    }

}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;

    seq = vector<int>(m, 0);
    nums = vector<int>(n, 0);

    for(int i = 0; i<n; i++)
        cin >> nums[i];

    sort(nums.begin(), nums.end());
    
    setSeq(0, 0);

}
