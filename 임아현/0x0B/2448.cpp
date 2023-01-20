#include <bits/stdc++.h>

using namespace std;
//3: base, 6: 3개짜리 삼각형 3개, 12: 6개짜리 삼각형 3개... 
char star[3072][6144]; //세로 N(3x2^10) 가로 2N - 1 별 저장할 배열

void draw(int x, int y, int N){
    //base condition 기본 삼각형 그리기
    if(N == 3){ 
        star[x][y] = '*';
        star[x + 1][y - 1] = '*';
        star[x + 1][y + 1] = '*';
        for(int i = 0; i < 5; i++) 
            star[x + 2][y - 2 + i] = '*';
        return;
    }
    //삼각형은 3개로 이루어져 있음 
    //맨위, 그 아래 왼쪽과 오른쪽 
    //3개짜리는 그대로(위에 하나), 6개 짜리는 3개 붙여서 
    draw(x, y, N / 2);
    draw(x + N / 2, y - N / 2, N / 2);
    draw(x + N / 2, y + N / 2, N / 2);

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    
    //공백으로 기본적으로 초기화
    memset(star, ' ', sizeof(star));
    
    draw(0, N -1, N); 
    
    //결과 출력 가로 2 * N - 1, 세로 N
    for(int i = 0; i < N; i++){ 
        for(int j = 0; j < 2 * N - 1; j++){
            cout << star[i][j];
        }
        cout << '\n';
    }
}