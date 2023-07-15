/*
����
������ �����ϴ� ��(Deque)�� ������ ����, �Է����� �־����� ����� ó���ϴ� ���α׷��� �ۼ��Ͻÿ�.

����� �� ���� �����̴�.
push_front X: ���� X�� ���� �տ� �ִ´�.
push_back X: ���� X�� ���� �ڿ� �ִ´�.
pop_front: ���� ���� �տ� �ִ� ���� ����, �� ���� ����Ѵ�. ����, ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
pop_back: ���� ���� �ڿ� �ִ� ���� ����, �� ���� ����Ѵ�. ����, ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
size: ���� ����ִ� ������ ������ ����Ѵ�.
empty: ���� ��������� 1��, �ƴϸ� 0�� ����Ѵ�.
front: ���� ���� �տ� �ִ� ������ ����Ѵ�. ���� ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
back: ���� ���� �ڿ� �ִ� ������ ����Ѵ�. ���� ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
�Է�
ù° �ٿ� �־����� ����� �� N (1 �� N �� 10,000)�� �־�����. ��° �ٺ��� N���� �ٿ��� ����� �ϳ��� �־�����. �־����� ������ 1���� ũ�ų� ����, 100,000���� �۰ų� ����. ������ �������� ���� ����� �־����� ���� ����.

���
����ؾ��ϴ� ����� �־��� ������, �� �ٿ� �ϳ��� ����Ѵ�.
*/

const int MAX = 100005;

int main(void) {
    int d[MAX];
    int front = 0, back = 0, size = (back - front + MAX) % MAX;
    int N;
    cin >> N;
    while (N--) {
        string s;
        cin >> s;
        if (s == "push_front") {
            int X;
            cin >> X;
            d[front] = X;
            front = (front - 1 + MAX) % MAX;
            size = (back - front + MAX) % MAX;
        }
        else if (s == "push_back") {
            int X;
            cin >> X;
            back = (back + 1) % MAX;
            d[back] = X;
            size = (back - front + MAX) % MAX;
        }
        else if (s == "pop_front") {
            if (size == 0)
                cout << "-1\n";
            else {
                front = (front + 1) % MAX;
                cout << d[front] << "\n";
                size = (back - front + MAX) % MAX;
            }
        }
        else if (s == "pop_back") {
            if (size == 0)
                cout << "-1\n";
            else {
                cout << d[back] << "\n";
                back = (back - 1 + MAX) % MAX;
                size = (back - front + MAX) % MAX;
            }
        }
        else if (s == "size")
            cout << size << "\n";
        else if (s == "empty")
            cout << (size == 0) << "\n";
        else if (s == "front") {
            if (size == 0)
                cout << "-1\n";
            else
                cout << d[(front + 1) % MAX] << "\n";
        }
        else {
            if (size == 0)
                cout << "-1\n";
            else
                cout << d[back] << "\n";
        }
    }
    return 0;
}
