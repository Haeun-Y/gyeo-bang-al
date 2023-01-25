//BOJ 2504 괄호의 값
#include <bits/stdc++.h>
using namespace std;
//함수명 수정하기
int func1(string& str, int i)
{
    if(str.length()-1 == i) return -1;
    else if(str[i] == '(' && str[i+1] == ')') return 2;
    else if(str[i] == '[' && str[i+1] == ']') return 3;
    else return -1;
}
int main(void)
{
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);
    
    string str;
    cin >> str;

    stack<int> s;
    int result = 0;

    for(int i = 0; i<str.length(); i++)
    {
        int tmp = func1(str, i);
        if(tmp != -1) 
        {
            s.push(tmp);

            i++;
            continue;
        }

        else if(str[i] == '(')
            s.push(-2);

        else if(str[i] == '[')
            s.push(-3);

        else//닫는 괄호인 경우
        {
            if(s.empty())//올바르지 못한 괄호열
            {
                result = 0;
                break;
            }
            else if(str[i] == ')' || str[i] == ']')
            {
                bool isSmallParen = (str[i] == ')')? true : false;
                
                if(s.top() == ((isSmallParen)?-3:-2))//올바르지 않은 괄호열
                {
                    result = 0;
                    break;
                }

                int num = s.top();
                s.pop();

                while(s.top() >= 0)//s.top 이 숫자일 경우
                {
                    num += s.top();
                    s.pop();                 
                }
                if(s.top() == ((isSmallParen)?-3:-2))//올바르지 않은 괄호열
                {
                    result = 0;
                    break;
                }
                else//올바른 괄호열
                {
                    s.pop();
                    s.push(num * ((isSmallParen)?2:3));
                }

            }
        }

    }

    while(!s.empty())
    {
        if(s.top() < 0)
        {
            result = 0;
            break;
        }
        else result += s.top();
    }

    cout << result;
    
}