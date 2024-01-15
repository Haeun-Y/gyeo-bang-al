#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
long long reverseNum(long long num)
{
    string str = to_string(num);
    long long end = str.length();
    for(long long i = str.length()-1; i > 0; i--)
    {
        if(str[i] == '0')
            end = i;
        else break;
    }
    
    str = str.substr(0, end);
    reverse(str.begin(), str.end());
    return stoll(str);
    
}
int main(void)
{
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<long long> nums(n);
    
    for(int i = 0; i<n; i++)
    {
        long long num;
        cin >> num;
        nums[i] = reverseNum(num);
    }
    
    sort(nums.begin(), nums.end());
    
    for(int i = 0; i<n; i++)
        cout << nums[i] << "\n";

}