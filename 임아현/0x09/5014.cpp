#include <bits/stdc++.h>

using namespace std;

int board[1000002];

int main()
{
    int F, S, G, U, D;
    cin >> F >> S >> G >> U >> D; //총 F층, 현재 S층, 목적 G층, U 위로, D 아래로 
    
    queue<int> Q;
    Q.push(S);
    
    board[S] = 1;
    
    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        int up = cur + U;
        int down = cur - D;

        if(up > 0 && up <= F && !board[up]){
            Q.push(up);
            board[up] = board[cur] + 1;
        }
        
        if(down > 0 && down <= F && !board[down]){
            Q.push(down);
            board[down] = board[cur] + 1;
        }
    }
    if(!board[G]) cout << "use the stairs";
    else cout << board[G] - 1;
    
}