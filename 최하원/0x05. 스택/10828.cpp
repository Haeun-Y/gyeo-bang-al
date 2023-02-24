/*
����
������ �����ϴ� ������ ������ ����, �Է����� �־����� ����� ó���ϴ� ���α׷��� �ۼ��Ͻÿ�.
����� �� �ټ� �����̴�.
push X : ���� X�� ���ÿ� �ִ� �����̴�.
pop : ���ÿ��� ���� ���� �ִ� ������ ����, �� ���� ����Ѵ�. ���� ���ÿ� ����ִ� ������ ���� ��쿡�� - 1�� ����Ѵ�.
size : ���ÿ� ����ִ� ������ ������ ����Ѵ�.
empty : ������ ��������� 1, �ƴϸ� 0�� ����Ѵ�.
top : ������ ���� ���� �ִ� ������ ����Ѵ�.���� ���ÿ� ����ִ� ������ ���� ��쿡�� - 1�� ����Ѵ�.

�Է�
ù° �ٿ� �־����� ����� �� N(1 �� N �� 10, 000)�� �־�����.��° �ٺ��� N���� �ٿ��� ����� �ϳ��� �־�����.�־����� ������ 1���� ũ�ų� ����, 100, 000���� �۰ų� ����.������ �������� ���� ����� �־����� ���� ����.

���
����ؾ��ϴ� ����� �־��� ������, �� �ٿ� �ϳ��� ����Ѵ�.
*/
#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
int dat[MX];
int pos = 0;

void push(int x) {
    dat[pos++] = x;
}
void empty() {
    cout << (pos == 0) << '\n';
}
void size() {
    cout << pos << '\n';
}
void pop() {
    if (pos > 0) {
        cout << dat[pos - 1] << '\n';
        pos--;
    }
    else cout << -1 << '\n';
}
void top() {
    if (pos > 0) cout << dat[pos - 1] << '\n';
    else cout << -1 << '\n';
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        if (s == "push") {
            int n;
            cin >> n;
            push(n);
        }
        else if (s == "pop") { pop(); }
        else if (s == "size") { size(); }
        else if (s == "empty") { empty(); }
        else top();
    }
}