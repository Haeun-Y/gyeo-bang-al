#include <bits/stdc++.h>

using namespace std;
string arr[52];
int N;

bool cmp(string s1, string s2){
    //길이 다름
    if(s1.length() != s2.length()) return s1.length() < s2.length();
    //길이가 같음
    else{
        int sum1 = 0, sum2 = 0;
        for(auto i: s1){
            if(i >= 48 && i <= 57) sum1 += (i - 48);
        }
        for(auto i: s2){
            if(i >= 48 && i <= 57) sum2 += (i - 48);
        }
        //자리 수의 합 비교하기
        if(sum1 != sum2) return sum1 < sum2;
        //자리 수도 같으면 사전순 정렬
        else{
            return s1 < s2;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    
    //정렬
    sort(arr, arr + N, cmp);
    
    for(int i = 0; i < N; i++){
        cout << arr[i] << '\n';
    }
}