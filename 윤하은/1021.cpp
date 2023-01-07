#include <bits/stdc++.h>
using namespace std;
void printdq(deque<int> &dq)
{
    for(int i = 0; i<dq.size(); i++)
        cout << dq[i] << "  ";
    cout << "\n";
}
void operate2(deque<int> &dq)
{
    int tmp = dq.front();
    dq.pop_front();
    dq.push_back(tmp);
    
    //cout << "operation 2 complete\n";
    //printdq(dq);
}
void operate3(deque<int> &dq)
{
    int tmp = dq.back();
    dq.pop_back();
    dq.push_front(tmp);

    //cout << "operation 3 complete\n";
    //printdq(dq);
}
void moveTarget(deque<int> &dq, int target, int& result)
{
    int target_idx = -1;
    for(int i = 0; i<dq.size(); i++)
    {
        if(dq[i] == target)
        {
            target_idx = i;
            break;
        }
    }
    if(target_idx == -1) return;

    int operation2 = target_idx;
    int operation3 = dq.size()-target_idx;

    //2번 연산 수행
    if(operation2 < operation3)
    {
        for(int i = 0; i<operation2; i++)
            operate2(dq);
        
        result += operation2;
    }
    else
    {
        for(int i = 0; i<operation3; i++)
            operate3(dq);
        
        result += operation3;   
    }
    return;
    
    
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    deque<int> dq;
    int result = 0;

    int element_num, target_num;
    cin >> element_num >> target_num;

    for(int i = 0; i<element_num; i++)
        dq.push_back(i+1);
    
    for(int i = 0; i<target_num; i++)
    {
        int target;
        cin >> target;

        moveTarget(dq, target, result);

        dq.pop_front();
    }

    cout << result;

}
