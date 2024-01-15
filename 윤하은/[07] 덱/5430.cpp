//BOJ 5430 AC 
#include <bits/stdc++.h>
using namespace std;
int operateD(deque<int> & dq, bool direction)
{
    if(dq.size() == 0) return 0;
    
    //순행
    if(direction)
        dq.pop_front(); 
    
    //역행
    else
        dq.pop_back();
    
    return 1;

}
void printResult(deque<int> & dq, bool direction)
{
    cout << "[";
    if(direction)
    {
        for(int i = 0; i<dq.size(); i++)
        {   
            if(i == (int)dq.size()-1)
                cout << dq[i];
            else cout << dq[i] << ",";
        }
    }

    //역행
    else
    {
        for(int i = (int)dq.size()-1; i>=0; i--)
        {
            if(i == 0)
                cout << dq[i];
            else cout << dq[i] << ",";
        }

    }
    cout << "]\n";
}
void ac(deque<int> & dq, string operation)
{
    //true -> 첫번째 원소부터, false -> 역순
    bool direction = true;
    for(char ch : operation)
    {
        int inter_result = 1;
        switch(ch)
        {
            case 'R':
                direction = !direction;
                break;
            case 'D':
                inter_result = operateD(dq, direction);
                break;
            default:
                break;
        }
        //error -> 끝내기
        if(inter_result == 0)
        {
            cout << "error\n";
            return;
        }
    }
    printResult(dq, direction);

}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;

    for(int i = 0; i<tc; i++)
    {
        string operation;
        cin >> operation;

        int n;
        cin >> n;

        deque<int> dq(n);

        char tmp;
        cin >> tmp;

        for(int j = 0; j<n; j++)
        {
            cin >> dq[j];
            if(j < n-1)
            {
                char tmp2;
                cin >> tmp2;
            }
    
        }    
        cin >> tmp;

        ac(dq, operation);
    }
}
