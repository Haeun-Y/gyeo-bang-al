//BOJ 2164 카드2
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);

    int cardNum;
    cin >> cardNum;

    queue<int> cards;

    for(int i = 1; i<=cardNum; i++)
        cards.push(i);

    while(cards.size() > 1)
    {
        cards.pop();//가장 위에 있는 카드 버림
        
        //가장 위에 있는 카드 맨 밑으로 옮기기
        int card = cards.front();
        cards.pop();
        cards.push(card);
    }

    cout << cards.front();
}