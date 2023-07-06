#include <bits/stdc++.h>

using namespace std;

string str1, str2;
int dp[1002][1002];

int main()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> str1 >> str2;
    
    int length1 = str1.length();
    int length2 = str2.length();
    
    
    for(int i = 1; i <= length1; i++){
        for(int j = 1; j <= length2; j++){
            if(str1[i - 1] == str2[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j -1]);
            }
        }
    }
    
    cout << dp[length1][length2];
    
}