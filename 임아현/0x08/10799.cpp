#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    stack <char> S;
    string str;
    cin >> str;
    
    int arr[100001] = {0}; //쇠막대기 배열
    int idx = 0; // 막대기 배열 idx
    int cnt = 0; //count
    
    for(int i = 0; i < str.length(); i++){
        if(str[i] == '(') { //여는 괄호일 시
            S.push(str[i]);
            idx++;
        }
        else{ //닫는 괄호일 시
            if(str[i - 1] == '('){ //레이저임 절단
               for(int j = idx - 1; j > 0; j--){
                   arr[j]++;
               }
               S.pop();
               idx--;
            }
            else{ //쇠막대의 끝 count
               if(arr[idx] != 0) cnt = cnt + arr[idx] + 1;
               arr[idx] = 0;
               S.pop();
               idx--;
            }
        }
    }
    cout << cnt;
}