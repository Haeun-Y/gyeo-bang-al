//231227
//BOJ 17298 오큰수
//GOLD 4
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> nums(n, 0);

    for(int i = 0; i<n; i++)
        cin >> nums[i];

    stack<int> s;

    for(int i = n-1; i>=0; i--)
    {
        int rightBigNum = 0;
        while(!s.empty() && s.top() <= nums[i])
            s.pop();
        
        if(s.empty())
            rightBigNum = -1;

        else
            rightBigNum = s.top();

        s.push(nums[i]);
        nums[i] = rightBigNum;
    }

    for(int i = 0; i<n; i++)
        cout << nums[i] << " ";

}