#include <bits/stdc++.h>

using namespace std;
int sum[42][3]; 
int N;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    
    sum[0][0] = 1;
    sum[1][1] = 1;
    
    for(int i = 2; i <=40 ; i++){
        sum[i][0] = sum[i - 1][0] + sum[i - 2][0];
        sum[i][1] = sum[i - 1][1] + sum[i - 2][1];
    }
    
    while(N--){
        int tmp;
        cin >> tmp;
        cout << sum[tmp][0] << ' ' << sum[tmp][1] <<'\n';
    }

}