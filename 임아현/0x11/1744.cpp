#include <bits/stdc++.h>

using namespace std;
int arr[52];

int main()
{
    int N;
    cin >> N;
    //숫자 입력받기기
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    
    //숫자 순서대로 정렬
    sort(arr, arr + N);
    
    int idx = 0;
    int sum = 0;
    // 양수끼리, 음수끼리 곱하거나 0과 양수 곱하기기
    // 음수는 앞에서부터 곱해 가기 양수는 뒤에서부터 곱해가기기
    while(idx < N && arr[idx] <= 0){
        int temp = arr[idx];
        idx++;
        if(idx < N && temp <= 0 && arr[idx] <=0){
            sum += temp * arr[idx];
            idx++;
        }
        
        else sum += temp;
    }
    
    int idx2 = N - 1;
    while(idx2 >= idx){
        int temp = arr[idx2];
        idx2--;
        if(idx2 >= idx && temp != 1 && arr[idx2] != 1){
            sum += temp * arr[idx2];
            idx2--;
        }
        else sum += temp;
    }
    
    cout << sum;
}