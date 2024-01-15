//230708 여방알
//BOJ 15650 n과 m(2) 
//SILVER 3

#include <iostream>
using namespace std;
int seq[10];
void printSequence(int m)
{
    for(int i = 0; i<m; i++)
        cout << seq[i] << " ";
    cout << "\n";

}
void createSequence(int curIdx, int beforeNum, int n, int m)
{
    if(curIdx == m)
    {
        printSequence(m);
        return;
    
    }
    for(int i = beforeNum+1; i<= n; i++)
    {
        seq[curIdx] = i;
        createSequence(curIdx + 1, i, n, m); 
    }
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    createSequence(0, 0, n, m);



}