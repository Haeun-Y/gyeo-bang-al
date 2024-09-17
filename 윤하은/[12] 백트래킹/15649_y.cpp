//230708 여방알
//BOJ 15649 n과 m(1) 
//SILVER 3
#include <iostream>
#include <vector>
using namespace std;
bool isUsed[10];
int seq[10];
void printSequence(int m)
{
    for(int i = 0; i < m; i++)
        cout << seq[i] << " ";
    cout << "\n";
}
void createSequence(int curIdx, int n, int m)
{
    if(curIdx == m)
    {
        printSequence(m);
        return;
    }

    else
    {
        for(int i = 1; i<=n; i++)
        {
            if(isUsed[i]) continue;
            seq[curIdx] = i;
            isUsed[i] = true;
            createSequence(curIdx+1, n, m);
            isUsed[i] = false;
        }
    }


}
int main(void)
{
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    createSequence(0, n, m);

}