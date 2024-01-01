//231226
//BOJ 6198 옥상정원 꾸미기 
//GOLD 5
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    long long result = 0;

    stack<int> s;

    for(int i = 0 ; i<n; i++)
    {
        int height;
        cin >> height;

        while(!s.empty() && s.top() <= height)
            s.pop();
        
        result += s.size();

        s.push(height);
    }

    cout << result;


}