//240111
//BOJ 15664 N과 M(10)
//SILVER 2
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int n, m;
vector<int> nums;
vector<int> seq;
vector<int> beforeSeq;
//seq이 beforeSeq보다 사전순으로 앞이라면 -> -1
//seq == beforeSeq -> 0
//seq이 beforeSeq보다 사전순으로 뒤라면 -> 1
int compareSeq()
{
    //beforeSeq vs seq
    for(int i = 0; i<m; i++)
    {
        if(seq[i] < beforeSeq[i])
            return -1;
        else if(seq[i] > beforeSeq[i])
            return 1;
    }
    return 0;
}
void printSeq()
{
    for(int i = 0; i<m; i++)
        cout << seq[i] << " ";
    cout << "\n";
}
void setElement(int idx, int before)
{
    if(idx == m)
    {
        if(compareSeq() == 1)
        {
            printSeq();
            beforeSeq = seq;
        }
        return;
    }
    else
    {
        for(int i = before+1; i<n; i++)
        {
            seq[idx] = nums[i];
            setElement(idx+1, i);
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
    beforeSeq = vector<int>(m, -1);

    for(int i = 0; i<n; i++)
        cin >> nums[i];

    sort(nums.begin(), nums.end());//오름차순 정렬
    
    setElement(0, -1);
    
}