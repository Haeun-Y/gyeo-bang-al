//240131
//BOJ 1699 제곱수의 합
//SILVER 2
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector<int> nums;
vector<int> squareNums;
int n;
void computeSquareNums()
{
    for(int i = 1; i * i <= n; i++)
    {
        int num = pow(i, 2);
        squareNums.push_back(num);
        nums[num] = 1;
    }

}
int computeSquareNumsSum()
{
    for(int i = 1; i<n; i++)
    {
        for(int j = 0; j<squareNums.size(); j++)
        {
            int nx = i + squareNums[j];
            int nxSum = nums[i] + 1;
            if(nx > n) break;
            if(nxSum < nums[nx])
                nums[nx] = nxSum;
        }
        //cout << "nums[" << i << "] : " << nums[i] << "\n";
    }

    return nums[n];

}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;

    nums = vector<int>(n+1, 100000);

    computeSquareNums();
    cout << computeSquareNumsSum();

}