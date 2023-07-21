#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<long long> V;
    
    for(int i = 0; i < N; i++){
        long long num, digit;
        long long cnt = 0;
        cin >> num;
        digit = num;
        //자리 수 세기
        while(digit > 0){
            digit /= 10;
            cnt++;
        }
        //숫자 뒤집기
        long long t = pow(10, cnt - 1);
        long long reverse = 0;
        while(cnt--){
            reverse = reverse + num % 10 * t;
            num /= 10;
            t /= 10;
        }
        V.push_back(reverse);
    }
    
    sort(V.begin(), V.end());
    for(int i = 0; i < N; i++){
        cout << V[i] << '\n';
    }
}