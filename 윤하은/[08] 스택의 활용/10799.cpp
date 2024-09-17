//BOJ 10799 쇠막대기
#include <bits/stdc++.h>
using namespace std;
void printStack(stack<char> s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << "\n";
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str;

    int result = 0;
    stack<char> sticks;

    for (int i = 0; i < str.length(); i++)
    {
        //레이저일 경우
        if (i < str.length() - 1 && str[i] == '(' && str[i + 1] == ')')
        {
            i++;
            result += sticks.size();
        }
        else if (str[i] == ')')
        {
            result++;
            sticks.pop();
        }

        else
            sticks.push(str[i]);
        //printStack(sticks);
    }
    
    cout << result;
}

//다른 풀이
/*
//BOJ 10799 쇠막대기
#include <bits/stdc++.h>
using namespace std;
bool isLaser(string& str, int i)
{
    //i가 마지막 원소의 인덱스일 경우
    if(i == str.length()-1) return false;
    
    else if(str[i] == '(' && str[i+1] == ')') return true;
    else return false;
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string str;
    cin >> str;
    
    stack<pair<char, int>> sticks;
    
    int laserNum = 0;
    int result = 0;
    
    for(int i = 0; i<str.length(); i++)
    {
        if(isLaser(str, i))
        {
            i++;
            laserNum++;
        }
        else
        {
            if(str[i] == '(')
                sticks.push({str[i], laserNum});
            else//str[i] == ')'
            {
                    result += (laserNum - sticks.top().second + 1);
                    sticks.pop();
                    
            }
        }
        
        
        
    }

    cout << result;
}


*/
