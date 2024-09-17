//231227
//BOJ 3015 오아시스 재결합
//PLATINUM 5
#include <iostream>
#include <utility>
#include <stack>
using namespace std;
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    stack<pair<int, int>> s;

    long long result = 0;

    for(int i = 0; i<n; i++)
    {
        pair<int, int> height;
        cin >> height.first;
        height.second = 1;

        if(s.empty())
        {
            s.push(height);
            continue;
        }

        while(!s.empty() && s.top().first < height.first)
        {
            result += s.top().second;//curPerson & s.top() person pair
            s.pop();
        }

        if(!s.empty() && s.top().first == height.first)
        {
            height.second += s.top().second;
            result += s.top().second;//curPerson & s.top() person pair with same height
            s.pop();
        }

        if(!s.empty() && s.top().first > height.first)
            result++;//curPerson & s.top() person pair


        s.push(height);
    }

    cout << result;


}