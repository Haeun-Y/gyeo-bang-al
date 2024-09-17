#include <bits/stdc++.h>

using namespace std;

int N;
int ab = 1000000;
int mod = 1000000000;
int arr[2000002]; // 1000000이 0임 -1000000해서 생각하기.


int main()
{
    cin >> N;
    N += ab;
    
    arr[ab] = 0; //0
    arr[ab + 1] = 1; //0;
    arr[ab - 1] = 1; // -1;
    
    if(N == ab) cout << "0\n0";
    else{
        if(N < ab){
          for(int i = ab - 2; i >= N; i--){
             arr[i] = (arr[i + 2] - arr[i + 1]) % mod;
           }
        }
        
       else{
           for(int i = ab + 2; i <= N; i++){
              arr[i] = (arr[i - 1] + arr[i - 2]) % mod;
           }
        }
        
        if(arr[N] < 0){
            cout << "-1\n";
        }
        else cout << "1\n";
        cout << abs(arr[N]);
    }
}