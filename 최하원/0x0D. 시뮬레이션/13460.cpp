/*
문제
구슬 탈출은 직사각형 보드에 빨간 구슬과 파란 구슬을 하나씩 넣은 다음, 빨간 구슬을 구멍을 통해 빼내는 게임이다.
보드의 세로 크기는 N, 가로 크기는 M이고, 편의상 1×1크기의 칸으로 나누어져 있다. 가장 바깥 행과 열은 모두 막혀져 있고, 보드에는 구멍이 하나 있다. 
빨간 구슬과 파란 구슬의 크기는 보드에서 1×1크기의 칸을 가득 채우는 사이즈이고, 각각 하나씩 들어가 있다. 게임의 목표는 빨간 구슬을 구멍을 통해서 빼내는 것이다. 
이때, 파란 구슬이 구멍에 들어가면 안 된다.
이때, 구슬을 손으로 건드릴 수는 없고, 중력을 이용해서 이리 저리 굴려야 한다. 
왼쪽으로 기울이기, 오른쪽으로 기울이기, 위쪽으로 기울이기, 아래쪽으로 기울이기와 같은 네 가지 동작이 가능하다.
각각의 동작에서 공은 동시에 움직인다. 빨간 구슬이 구멍에 빠지면 성공이지만, 파란 구슬이 구멍에 빠지면 실패이다. 
빨간 구슬과 파란 구슬이 동시에 구멍에 빠져도 실패이다. 빨간 구슬과 파란 구슬은 동시에 같은 칸에 있을 수 없다. 
또, 빨간 구슬과 파란 구슬의 크기는 한 칸을 모두 차지한다. 기울이는 동작을 그만하는 것은 더 이상 구슬이 움직이지 않을 때 까지이다.
보드의 상태가 주어졌을 때, 최소 몇 번 만에 빨간 구슬을 구멍을 통해 빼낼 수 있는지 구하는 프로그램을 작성하시오.

입력
첫 번째 줄에는 보드의 세로, 가로 크기를 의미하는 두 정수 N, M (3 ≤ N, M ≤ 10)이 주어진다. 다음 N개의 줄에 보드의 모양을 나타내는 길이 M의 문자열이 주어진다. 
이 문자열은 '.', '#', 'O', 'R', 'B' 로 이루어져 있다.
'.'은 빈 칸을 의미하고, '#'은 공이 이동할 수 없는 장애물 또는 벽을 의미하며, 'O'는 구멍의 위치를 의미한다. 'R'은 빨간 구슬의 위치, 'B'는 파란 구슬의 위치이다.
입력되는 모든 보드의 가장자리에는 모두 '#'이 있다. 구멍의 개수는 한 개 이며, 빨간 구슬과 파란 구슬은 항상 1개가 주어진다.

출력
최소 몇 번 만에 빨간 구슬을 구멍을 통해 빼낼 수 있는지 출력한다. 만약, 10번 이하로 움직여서 빨간 구슬을 구멍을 통해 빼낼 수 없으면 -1을 출력한다.
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

    for (int d = 0; d < 4; d++) { //네 가지 방향으로
        pair<int, int> nblue;
        int nx = bluex + dx[d]; //다음 파란공 위치
        int ny = bluey + dy[d];
        bool chk = false; //빨간공과 부딪히는지 여부 판단
        while (arr[nx][ny] == '.') { 
            nx += dx[d];
            ny += dy[d];
        }
        if (arr[nx][ny] == 'O') continue; //파란 공이 구멍에 빠진 경우
        if (arr[nx][ny] == 'R') { // 충돌
            chk = true;
        }
        nx -= dx[d];
        ny -= dy[d];
        nblue = { nx, ny };

        if (!chk) { //부딪히지 않았을 경우에 수정
            arr[bluex][bluey] = '.';
            arr[nx][ny] = 'B';
        }

        pair<int, int> nred; //빨간공 이동
        nx = redx + dx[d]; //다음 빨간공 위치
        ny = redy + dy[d];

        while (arr[nx][ny] == '.') { //멈출 때까지
            nx += dx[d];
            ny += dy[d];
        }
        if (arr[nx][ny] == 'O') { //구멍에 빠진 경우
            if (!chk) {//파란 공이 같이 빠지지 않을 경우에만 정답 갱신
                ans = min(ans, depth + 1);
                arr[nblue.first][nblue.second] = '.'; //파란 공 위치 원래대로 돌리고 계속
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