//BOJ 1475 방 번호
#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);

    string roomNum;
    cin >> roomNum;

    vector<int> numCompositions(10);

    //9와 6 -> numCompositions[6] 에만 저장
    for(char ch : roomNum)
    {
        int idx = ch - '0';
        if(idx == 9)
            idx = 6;
        numCompositions[idx]++;
    }

    numCompositions[6] = (int)ceil((double)numCompositions[6]/2);
    sort(numCompositions.begin(), numCompositions.end());

    cout << numCompositions[9];
}