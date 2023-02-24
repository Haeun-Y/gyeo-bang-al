#include <bits/stdc++.h>

using namespace std;

int N;
string arr[1000002]; //연산 횟수 저장하기

int main()
{
    cin >> N;
    
    //1 빼기 2로 나누기 3으로 나누기기
    arr[1] = "";
    arr[2] = "2";
    arr[3] = "3";
    
    for(int i = 4; i <= N; i++){
        arr[i] = arr[i - 1] + "1";
        if(!(i % 2)){ 
            if(arr[i].length() > arr[i /2].length() + 1)
               arr[i] = arr[i / 2] + "2";
        }
        if(!(i % 3)){
            if(arr[i].length() > arr[i /3].length() + 1)
               arr[i] = arr[i / 3] + "3";
        }
    }
    
    int ans = arr[N].length();
    cout << ans << '\n';
    
    for(int i = ans - 1; i >= 0; i--){
        cout << N <<' ';
        if(arr[N][i] == '1') N--;
        else if(arr[N][i] == '2') N /= 2;
        else N /= 3;
    }
    cout << '1';
}