/*
문제
N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오.

입력
첫째 줄에 수의 개수 N(1 ≤ N ≤ 1,000)이 주어진다. 둘째 줄부터 N개의 줄에는 수가 주어진다.
이 수는 절댓값이 1,000보다 작거나 같은 정수이다. 수는 중복되지 않는다.

출력
첫째 줄부터 N개의 줄에 오름차순으로 정렬한 결과를 한 줄에 하나씩 출력한다.
*/

#include<bits/stdc++.h>
using namespace std;
int N, arr[10000005];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];

    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - 1 - i; j++)
            if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
    }

    for (int i = 0; i < N; i++) cout << arr[i] << "\n";

}