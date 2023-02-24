/*
����
���� Ż���� ���簢�� ���忡 ���� ������ �Ķ� ������ �ϳ��� ���� ����, ���� ������ ������ ���� ������ �����̴�.
������ ���� ũ��� N, ���� ũ��� M�̰�, ���ǻ� 1��1ũ���� ĭ���� �������� �ִ�. ���� �ٱ� ��� ���� ��� ������ �ְ�, ���忡�� ������ �ϳ� �ִ�. 
���� ������ �Ķ� ������ ũ��� ���忡�� 1��1ũ���� ĭ�� ���� ä��� �������̰�, ���� �ϳ��� �� �ִ�. ������ ��ǥ�� ���� ������ ������ ���ؼ� ������ ���̴�. 
�̶�, �Ķ� ������ ���ۿ� ���� �� �ȴ�.
�̶�, ������ ������ �ǵ帱 ���� ����, �߷��� �̿��ؼ� �̸� ���� ������ �Ѵ�. 
�������� ����̱�, ���������� ����̱�, �������� ����̱�, �Ʒ������� ����̱�� ���� �� ���� ������ �����ϴ�.
������ ���ۿ��� ���� ���ÿ� �����δ�. ���� ������ ���ۿ� ������ ����������, �Ķ� ������ ���ۿ� ������ �����̴�. 
���� ������ �Ķ� ������ ���ÿ� ���ۿ� ������ �����̴�. ���� ������ �Ķ� ������ ���ÿ� ���� ĭ�� ���� �� ����. 
��, ���� ������ �Ķ� ������ ũ��� �� ĭ�� ��� �����Ѵ�. ����̴� ������ �׸��ϴ� ���� �� �̻� ������ �������� ���� �� �����̴�.
������ ���°� �־����� ��, �ּ� �� �� ���� ���� ������ ������ ���� ���� �� �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù ��° �ٿ��� ������ ����, ���� ũ�⸦ �ǹ��ϴ� �� ���� N, M (3 �� N, M �� 10)�� �־�����. ���� N���� �ٿ� ������ ����� ��Ÿ���� ���� M�� ���ڿ��� �־�����. 
�� ���ڿ��� '.', '#', 'O', 'R', 'B' �� �̷���� �ִ�.
'.'�� �� ĭ�� �ǹ��ϰ�, '#'�� ���� �̵��� �� ���� ��ֹ� �Ǵ� ���� �ǹ��ϸ�, 'O'�� ������ ��ġ�� �ǹ��Ѵ�. 'R'�� ���� ������ ��ġ, 'B'�� �Ķ� ������ ��ġ�̴�.
�ԷµǴ� ��� ������ �����ڸ����� ��� '#'�� �ִ�. ������ ������ �� �� �̸�, ���� ������ �Ķ� ������ �׻� 1���� �־�����.

���
�ּ� �� �� ���� ���� ������ ������ ���� ���� �� �ִ��� ����Ѵ�. ����, 10�� ���Ϸ� �������� ���� ������ ������ ���� ���� �� ������ -1�� ����Ѵ�.
*/

#include <bits/stdc++.h>
using namespace std;

int MN = 11;
string arr[MN];
int dx[4] = { 1, 0, 0, -1 };
int dy[4] = { 0, 1, -1, 0 };

int visit[MN][MN][MN][MN];
int ans = 11;

void dfs(pair<int, int> red, pair<int, int> blue, int depth) {
    if (depth > 10) return;
    int redx = red.first, redy = red.second;
    int bluex = blue.first, bluey = blue.second;
    if (visit[redx][redy][bluex][bluey] <= depth) return;
    visit[redx][redy][bluex][bluey] = depth;

    for (int d = 0; d < 4; d++) { //�� ���� ��������
        pair<int, int> nblue;
        int nx = bluex + dx[d]; //���� �Ķ��� ��ġ
        int ny = bluey + dy[d];
        bool chk = false; //�������� �ε������� ���� �Ǵ�
        while (arr[nx][ny] == '.') { 
            nx += dx[d];
            ny += dy[d];
        }
        if (arr[nx][ny] == 'O') continue; //�Ķ� ���� ���ۿ� ���� ���
        if (arr[nx][ny] == 'R') { // �浹
            chk = true;
        }
        nx -= dx[d];
        ny -= dy[d];
        nblue = { nx, ny };

        if (!chk) { //�ε����� �ʾ��� ��쿡 ����
            arr[bluex][bluey] = '.';
            arr[nx][ny] = 'B';
        }

        pair<int, int> nred; //������ �̵�
        nx = redx + dx[d]; //���� ������ ��ġ
        ny = redy + dy[d];

        while (arr[nx][ny] == '.') { //���� ������
            nx += dx[d];
            ny += dy[d];
        }
        if (arr[nx][ny] == 'O') { //���ۿ� ���� ���
            if (!chk) {//�Ķ� ���� ���� ������ ���� ��쿡�� ���� ����
                ans = min(ans, depth + 1);
                arr[nblue.first][nblue.second] = '.'; //�Ķ� �� ��ġ ������� ������ ���
                arr[bluex][bluey] = 'B';
            }
            continue;
        }
        nx -= dx[d]; 
        ny -= dy[d];
        nred = { nx, ny }; 
        arr[redx][redy] = '.';
        arr[nx][ny] = 'R';

        if (chk) {
            nblue.first = nx - dx[d];
            nblue.second = ny - dy[d];
            arr[nblue.first][nblue.second] = 'B'; 
            arr[bluex][bluey] = '.';
        }
        dfs(nred, nblue, depth + 1); 
        arr[nred.first][nred.second] = '.'; 
        arr[nblue.first][nblue.second] = '.';
        arr[redx][redy] = 'R';
        arr[bluex][bluey] = 'B';
    }
}

int main() {
    int N, M; cin >> N >> M;
    fill(&visit[0][0][0][0], &visit[MN - 1][MN - 1][MN - 1][MN], 11);
    pair<int, int> red;
    pair<int, int> blue;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        for (int j = 0; j < arr[i].size(); j++) {
            if (arr[i][j] == 'R') { 
                red = { i, j };
            }
            if (arr[i][j] == 'B') {
                blue = { i, j };
            }
        }
    }
    dfs(red, blue, 0);

    if (ans > 10) cout << -1; 
    else cout << ans; 
}