/*
����
N���� ���� �־����� ��, �̸� ������������ �����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ���� ���� N(1 �� N �� 1,000)�� �־�����. ��° �ٺ��� N���� �ٿ��� ���� �־�����.
�� ���� ������ 1,000���� �۰ų� ���� �����̴�. ���� �ߺ����� �ʴ´�.

���
ù° �ٺ��� N���� �ٿ� ������������ ������ ����� �� �ٿ� �ϳ��� ����Ѵ�.
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