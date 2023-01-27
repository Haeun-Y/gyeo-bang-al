//BOJ 11729 하노이 탑 이동 순서
#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> moves;
void hanoi(int n, int departure, int tmp, int arrival)
{
    if(n == 1)
        moves.push_back({departure, arrival});
    
    else
    {
        //n-1 moves departure to tmp
        hanoi(n-1, departure, arrival, tmp);
        //nth disk moves departure to arrival
        moves.push_back({departure, arrival});
        //n-1 moves tmp to arrival
        hanoi(n-1, tmp, departure, arrival);
    }
    
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int disk;
    cin >> disk;
    
    hanoi(disk, 1, 2, 3);
    cout << moves.size() << "\n";
    
    for(pair<int, int> cur : moves)
        cout << cur.first << " " << cur.second << "\n";
}
