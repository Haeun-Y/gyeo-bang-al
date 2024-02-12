//240209
//BOJ 14888 연산자 끼워넣기
//SILVER 1
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, maxResult, minResult;
vector<int> seq;
vector<char> op;
char ops[4] = {'+', '-', '*', '/'};
int operate(int a, int b, char ch)
{
    if(ch == '+')
        return a+b;
    else if(ch == '*')
        return a*b;
    else if(ch == '-')
        return a-b;
    else//ch == '/' 
        return a/b;
}
void bruteforce()
{
    maxResult = -1000000000;
    minResult = 1000000000;

    sort(op.begin(), op.end());

    do
    {
        int result = seq[0];
        for(int i = 0; i<op.size(); i++)
            result = operate(result, seq[i+1], op[i]);
        
        maxResult = max(maxResult, result);
        minResult = min(minResult, result);
        
    }while(next_permutation(op.begin(), op.end()));

}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    seq = vector<int>(n, 0);

    for(int i = 0; i<n; i++)
        cin >> seq[i];

    for(int i = 0; i<4; i++)
    {
        int num;
        cin >> num;
        for(int j = 0; j<num; j++)
            op.push_back(ops[i]);
    }

    bruteforce();
    cout << maxResult << "\n" << minResult;

}