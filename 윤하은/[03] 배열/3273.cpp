//BOJ 3273 두 수의 합
//binary_search 이용하는 방법 말고 배열 원소에 대해 해당 수의 존재 여부 체크하는 배열을
//두는 방식이 시간복잡도 측면에서 유리함
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> v(n);
    
    for(int i = 0; i<n; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    int target;
    cin >> target;

    int result = 0;

    for(int i = 0; i<n-1; i++)
    {
        int searchTarget = target-v[i];
        if(binary_search(v.begin() + i + 1, v.end(), searchTarget))
            result++;
    }

    cout << result;


    
}
