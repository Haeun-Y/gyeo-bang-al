//240111
//BOJ 1182 부분 수열의 합
//SILVER 2
#include <iostream>
#include <vector>
using namespace std;
vector<int> seq;
int n, result, targetSum;
//idx번째 원소를 포함하거나, 포함하지 않는 부분수열을 찾는 함수
void findSubSeq(int idx, int curSum)
{
    if(idx == n)
    {
        if(curSum == targetSum) result++;
        return;
    }
    else
    {
        findSubSeq(idx+1, curSum);
        findSubSeq(idx+1, curSum+seq[idx]);
    }

}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> targetSum;
    seq = vector<int>(n, 0);

    for(int i = 0; i<n; i++)
        cin >> seq[i];

    findSubSeq(0, 0);
    if(targetSum == 0) result--;

    cout << result;

    
}