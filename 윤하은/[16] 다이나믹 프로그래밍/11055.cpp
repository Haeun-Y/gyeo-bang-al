//240123
//BOJ 11055 가장 큰 증가하는 부분 수열
//SILVER 2
//시간 초과
#include <iostream>
#include <vector>
using namespace std;
int n, result;
vector<int> seq;
void func1(int idx, int beforeElement, int sum)
{
    if(idx == n)
    {
        if(sum > result)
            result = sum;
        return;
    }
    else
    {
        if(seq[idx] >= beforeElement)
        {
            func1(idx+1, seq[idx], sum + seq[idx]);
            func1(idx+1, beforeElement, sum);
        }
        else
            func1(idx+1, beforeElement, sum);
        
    }

}
int main(void)
{
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);

    cin >> n;
    seq = vector<int>(n, 0);
    for(int i = 0; i<n; i++)
        cin >> seq[i];

    func1(0, 0, 0);

    cout << result;
    
}